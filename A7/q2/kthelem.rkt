#lang racket

(provide k-th-largest-element)

;; Jiayu Zhou
;; CS136, Winter 2015
;; Assignment 7, Problem 2


;;(k-th-largest-element lon k) consumes a list of numbers and an integer k, and produces the kth largest element of the list, false if that element does not exist.
(define (k-th-largest-element lon k)
  (local [(define sortedlon (sort lon >))
          (define (disp lon k)
            (cond [(empty? lon) #f]
                  [(= k 0) (first lon)]
                  [else (disp (rest lon) (sub1 k))]))]
         (disp sortedlon (- k 1))))