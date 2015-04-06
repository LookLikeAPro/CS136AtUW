#lang racket

;; numbers.rkt

;; NOTE: You are not required to understand the implementation of this
;;       code but should be able to understand the given interface.
;;       Also, you may not use functions from here that are not described
;;       in the course notes in your own assignments or exams. 

;; IMPORTANT: You may change the integers in the list of numbers lon to
;;            further test your code.  You should NOT add any new
;;            constants or functions.  We will replace this file with
;;            our own version when testing your code for correctness.

(provide get-number)

;; (get-number) produces a non-negative integer from lon or #f.
;; The i-th time (get-number) is called, it produces the i-th element of lon. 
;; If the number of calls to (get-number) exceeds the number of elements
;; in lon, then #f is produced.
;; (get-number): Void -> (anyof Int #f)
;; Example:
;; (define lon '(0 100) 
;; (get-number) => 0
;; (get-number) => 100
;; (get-number) => #f


;;;;;;;;;; IMPLEMENTATION ;;;;;;;;;;

(define lon '(3 4 3 4 1 2 3 2 6 4 6 5 1 5))

(define cur-idx 0)
(define length (foldr (lambda (x y)(add1 y)) 0 lon))

(define (get-number)
  (cond [(= cur-idx length) #f]
        [else (set! cur-idx (add1 cur-idx))
              (list-ref lon (sub1 cur-idx))]))