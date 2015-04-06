#lang racket

;; Jiayu Zhou
;; CS136 Winter 2015
;; Assignment 1, Problem 0b

(provide list-range)

;;(list-range a b) consumes two integers a and b and produces a list of all integers from a to b
;;list-range: Int Int -> (listof Int)
;;requires: a<=b
(define (list-range a b)
  (cond [(= a b) (cons a empty)]
        [else (cons a (list-range (add1 a) b))]))

;;(list-range 2 6)