#lang racket

;; playboard.rkt

;; This module stores the data for a playing board that is partitioned into
;; squares and provides functions to check the values of each square.

(require "numbers3.rkt")
(provide lookup match?)


;;;;;;;;;; Implementation ;;;;;;;;;;
;;(create-playing-board) consumes nothing and produces a playing 
;;board with dimensions and values specified by get-number function
;;create-playing-board: Nothing -> (listof (listof Nat))
(define (create-playing-board) 
  (local [(define rows (get-number))
          (define cols (get-number))]
         (map (lambda (row) 
                (map (lambda (col) (get-number)) 
                     (build-list cols add1))) 
              (build-list rows add1))))


(define playing-board (create-playing-board))

;;(get board row col) consumes a nested list, a row and column 
;;number, and produces the value on the nested list at that row 
;;and column, or #f if value is out of bounds
;;get: (listof (listof Any)) Nat Nat -> Any
(define (get board row)
  (cond [(empty? board) #f]
        [(= row 1) (first board)]
        [else (get (rest board) (sub1 row))]))

;;(lookup row col) produces the value at square (row, col) on 
;;the playing board  or #f if the row or col arguments are 
;;outside the dimensions of the board.
;;lookup: Nat Nat -> (anyof Int #f)
(define (lookup row col)
  (get (get playing-board row) col))

;; (match? row1 col1 row2 col2) produces #t if the values of 
;;squares (row1, col1) and (row2, col2) are the same, #f otherwise.
;; match?: Nat Nat Nat Nat -> Bool
(define (match? row1 col1 row2 col2)
  (cond [(= (lookup row1 col1) (lookup row2 col2)) #t]
        [else #f]))