#lang racket

;; Jiayu Zhou
;; CS136 Winter 2015
;; Assignment 1, Problem 0a

(provide  has-same-consecutive-letter?)

;;(has-same-consecutive-letter? str) consumes a string str and 
;;produces #t if str contains two consecutive letters that are 
;;the same, #f otherwise.
;;has-same-consecutive-letter?: Str -> Bool
(define (has-same-consecutive-letter? str)
  (has-same-consecutive-character? (string->list str)))

;;(has-same-consecutive-character? lst) consumes a list of 
;;characters and produces #t if lst contains two consecutive 
;;characters that are the same, #f otherwise.
;;has-same-consecutive-character?: (listof Char) -> Bool
(define (has-same-consecutive-character? lst)
  (cond [(or (empty? lst) (empty? (rest lst))) #f]
        [(char=? (first lst) (second lst)) #t]
        [else (has-same-consecutive-character? (rest lst))]))

;;(has-same-consecutive-letter? "better")
;;(has-same-consecutive-letter? "beware")