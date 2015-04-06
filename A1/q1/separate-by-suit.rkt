#lang racket

;; Jiayu Zhou
;; CS136 Winter 2015
;; Assignment 1, Problem 1

(require "numbers1.rkt" "card-deck.rkt")

;;(rank deck sym) consumes a deck and a previous symbol, and produces a new list of suits from the deck, with duplicate consecutive symbols removed.
;;rank: (listof Card) Sym -> (listof Sym)
(define (rank deck sym)
  (cond [(< (length deck) 2) empty]
        [(symbol=? (get-suit (first deck)) sym) (rank (rest deck) sym)]
        [else (cons (get-suit (first deck)) (rank (rest deck) (get-suit (first deck))))]))

;;(separate-by-suit) consumes nothing produces a list of 4 piles 
;;of cards separated by suit from a deck that is shuffled 
;;(get-number) times.
;;separate-by-suit: Void -> (listof (listof Card))
(define (separate-by-suit)
  (local [(define deck (shuffle-deck (build-deck) (get-number)))
          (define order (rank deck 'X))]
   (list (filter (lambda (c) (symbol=? (first order) (get-suit c))) deck)
         (filter (lambda (c) (symbol=? (second order) (get-suit c))) deck)
        (filter (lambda (c) (symbol=? (third order) (get-suit c))) deck)
        (filter (lambda (c) (symbol=? (fourth order) (get-suit c))) deck))))
