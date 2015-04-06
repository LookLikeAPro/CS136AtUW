#lang racket

;; Jiayu Zhou
;; CS136 Winter 2015
;; Assignment 1, Problem 0c

(provide list-letter-range)

;;(list-letter-range a b) consumes two characters l1 and l2 and produces a list of letters ranging from a to b.
;;list-letter-range: Char Char -> (listof Char)
;;requires: l1 is before l2 or same as l2 in ASCII Table
(define (list-letter-range l1 l2)
  (cond [(char=? l1 l2) (cons l1 empty)]
        [else (cons l1 (list-letter-range (integer->char (add1 (char->integer l1))) l2))]))

;;(list-letter-range #\e #\z)