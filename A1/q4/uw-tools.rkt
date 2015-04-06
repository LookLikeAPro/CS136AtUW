#lang racket

;; CS136 Assignment 1, q4
;; uw-tools.rkt

(require "uw-api.rkt")
(provide course-desc online? course-sections course-capacity section-info next-holiday room-status)

;;(get-item data title) consumes an association list data and a 
;;title to look for, and produces #f if key is not found, or data 
;;inside the key if key is found
;;get-item: AL Str -> Any
(define (get-item data title)
  (cond [(empty? data) null]
        [(not (list? data)) null]
        [(not (string? title)) null]
        [(not (string? (first (first data)))) (get-item (rest data) title)]
        [(string=? (first (first data)) title) (second (first data))]
        [else (get-item (rest data) title)]))

;;(flatten lst) consumes a list of strings called lst and outputs 
;;all terms of the list appended in a singe string
;;flatten: (listof Str) -> Str
(define (flatten lst)
  (cond [(empty? lst) ""]
        [else (string-append (first lst) (flatten (rest lst)))]))

;;(date-compare date1 date2) consumes two date strings in format "yyyy-mm-dd" and produces true or false indicating whether the first date is earlier than the second
;;date-compare: Str Str -> Bool
(define (date-compare date1 date2)
  (< (string->number (list->string (filter (lambda (char) (not (char=? char #\-))) (string->list date1))))
     (string->number (list->string (filter (lambda (char) (not (char=? char #\-))) (string->list date2))))))


;;(included? day1 day2) consumes two strings representing a list of weekdays and produces true or false indicating whether the first weekday is part of the second
;;date-compare: Str Str -> Bool
(define (included? day1 day2)
  (cond [(list? (member (cond [(string=? day1 "Th") #\X]
                [else (first (string->list day1))])
          (map (lambda (c) (cond [(char=? c #\h) #\X]
                                 [else c]))
               (string->list day2)))) #t]
        [else #f]))

;;(time-compare t1 t2) consumes two time strings in format "hh:mm" and produces true or false indicating whether the first date is earlier than the second
;;date-compare: Str Str -> Bool
(define (time-compare t1 t2)
  (<= (string->number (list->string (filter (lambda (char) (not (char=? char #\:))) (string->list t1))))
     (string->number (list->string (filter (lambda (char) (not (char=? char #\:))) (string->list t2))))))


;;(course-desc subject catalog) consumes a subjet string, a 
;;catalog number, and produces a string with the calendar 
;;"description" of the course. 
;;course-desc: Str Nat -> Strlist
;;requires: valid subject and catalog that exist in UW Open Data API as input
(define (course-desc subject catalog)
  (get-item (uw-api 
                   (string-append "/courses/" subject "/" 
                                  (number->string catalog))) "description"))


;;(online? subject catalog) consumes a subjet string, a 
;;catalog string, and produces #t if the course is available 
;;online (or is only available online), and #f otherwise
;;online?: Str Nat -> Strlist
;;requires: valid subject and catalog that exist in UW Open Data API as input
(define (online? subject catalog)
  (get-item (get-item (uw-api (string-append "/courses/" subject "/" (number->string catalog))) "offerings") "online"))

;;(course-sections term subject catalog) consumes a term number, 
;;a subject string, a catalog number, and produces a list of 
;;strings that correspond to the section names for the course.
;;course-sections: Nat Str Nat -> (listof Str)
;;requires: valid term, subject and catalog that exist in UW Open Data API as input
(define (course-sections term subject catalog)
  (local [(define data (uw-api (string-append "/terms/"
                                              (number->string term) "/" subject "/" (number->string catalog) "/schedule")))
          (define (process data)
            (cond [(empty? data) empty]
                  [else (cons (get-item (first data) "section")
                              (process (rest data)))]))]
         (process data)))

;;(course-capacity term subject catalog) consumes a term number, 
;;a subject string, a catalog number, and produces a list of 
;;lists illustrating how "full" a course is. For each "LEC" 
;;section, it must produce a list with 3 items: the section, the 
;;enrollment_capacity and the enrollment_total (number of 
;;students in the class)
;;course-capacity: Nat Str Nat -> (listof Str)
;;requires: valid term, subject and catalog that exist in UW Open Data API as input
(define (course-capacity term subject catalog)
  (local [(define data (uw-api (string-append "/terms/"
                                              (number->string term) "/" subject "/" (number->string catalog) "/schedule")))
          (define (process data)
            (cond [(empty? data) empty]
                  [(string=? (substring (get-item (first data) "section") 0 3) "LEC")
                   (cons (list (get-item (first data) "section")
                               (get-item (first data) "enrollment_capacity")
                               (get-item (first data) "enrollment_total"))
                         (process (rest data)))]
                  [else (process (rest data))]))]
         (process data)))

;;(section-info term subject catalog section) consumes a term 
;;number, subject string, catalog number, section string, and 
;;produces a single string with information about a particular 
;;section. 
;;section-info: Nat Str Nat Str -> (listof Str)
;;requires: valid term, subject, catalog and section info that exist in UW Open Data
(define (section-info term subject catalog section)
  (local [(define data (uw-api (string-append "/terms/"
                                              (number->string term) "/" subject "/" (number->string catalog) "/schedule")))
          (define (process data)
            (cond [(empty? data) empty]
                  [(string=? section (get-item (first data) "section"))
                   (string-append subject " " (number->string catalog) " " section " " 
                                  (get-item (get-item (first (get-item (first data) "classes")) "date") "start_time") "-"
                                  (get-item (get-item (first (get-item (first data) "classes")) "date") "end_time") " "
                                  (get-item (get-item (first (get-item (first data) "classes")) "date") "weekdays") " "
                                  (get-item (get-item (first (get-item (first data) "classes")) "location") "building") " "
                                  (get-item (get-item (first (get-item (first data) "classes")) "location") "room") " "
                                  (flatten (get-item (first (get-item (first data) "classes")) "instructors")))]
                  [else (process (rest data))]))]
         (process data)))

;;(next-holiday date) consumes a date string in format "yyyy-mm-dd" and produces the next holiday description as a string
;;next-holiday: Str -> Str
(define (next-holiday date)
  (local [(define data (sort (uw-api "/events/holidays") (lambda (item1 item2) (date-compare (get-item item1 "date") (get-item item2 "date")))))
          (define (process data)
            (cond [(empty? data) #f]
                  [(date-compare date (get-item (first data) "date"))
                   (string-append (get-item (first data) "date") " " (get-item (first data) "name"))]
                  [else (process (rest data))]))] 
         (process data)))

;;(room-status building room day time) consumes a builidng string, a room number, a day string and a time string and produces a string indicating what class is in that room at the time, or "FREE" if there is no class.
;;room-status: Str Nat Str Str -> Str
(define (room-status building room day time)
  (local [(define data (uw-api (string-append "/buildings/"building"/"(number->string room)"/courses")))
          (define (process data)
            (cond [(empty? data) "FREE"]
                  [(and (included? day (get-item (first data) "weekdays"))
                        (time-compare (get-item (first data) "start_time") time)
                        (time-compare time (get-item (first data) "end_time")))
                   (string-append (get-item (first data) "subject") " "
                                  (get-item (first data) "catalog_number") " "
                                  (get-item (first data) "title"))]
                  [else (process (rest data))]))] 
         (process data)))