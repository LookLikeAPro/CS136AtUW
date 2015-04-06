#lang racket

;; Your Name
;; CS136 Winter 2015
;; Assignment 1, Problem 0d

(provide slon-intersect)

;;(slon-intersect slon1 slon2) consumes two parameters slon1 and 
;;slon2 that are both lists of numbers sorted in ascending order, 
;;and produces a sorted list of numbers (in ascending order) that 
;;contains all numbers that appear in both slon1 and slon2 .
;;slon-intersect: (listof Num) (listof Num) -> (listof Num)
;;Requires: No duplicate elements in slon1 and slon2
(define (slon-intersect slon1 slon2)
  (cond [(or (empty? slon1) (empty? slon2)) empty]
        [(= (first slon1) (first slon2)) (cons (first slon1) (slon-intersect (rest slon1) (rest slon2)))]
        [(< (first slon1) (first slon2)) (slon-intersect (rest slon1) slon2)]
        [else (slon-intersect slon1 (rest slon2))]))

;;(slon-intersect '(1 2 3 4) '(2 3 5))