#lang racket

(provide shuffle-deck build-deck get-suit get-rank)

(random-seed 1234)

(struct card (suit rank) #:transparent)

(define num-suits 4)
(define num-ranks 13)
(define num-cards (* num-suits num-ranks))

(define suits '(club diamond heart spade))
(define ranks '(2 3 4 5 6 7 8 9 10 jack queen king ace))

;;(get-suit c) consumes a card c and produces its suit
;;get-suit: Card -> Sym
;;Example:
;;(check-expect (get-suit (make-card 'club 2)) club)
;;(check-expect (get-suit (make-card 'heart 2)) heart)
;;;;;;;;;; IMPLEMENTATION ;;;;;;;;;;
;;(get-suit c) consumes a card c and produces its suit
;;get-suit: Card -> Sym
(define (get-suit c) 
  (card-suit c))

;;(get-rank c) consumes a card c and produces its rank
;;get-rank: Card -> (Anyof Nat Sym)
(define (get-rank c) 
  (card-rank c))

;;(build-deck) consumes nothing and produces a list of 52 cards 
;;each with different suit and rank, also known as a deck.
;;build-deck: Nothing -> (listof Card)
(define (build-deck)
  (flatten (build-list num-suits (lambda (x) (build-list num-ranks (lambda (y) (card (list-ref suits x) (list-ref ranks y))))))))

;;(shuffle-deck d n) consumes a list of cards d and a number n 
;;and randomly rearranges the list of cards by moving random ;;cards for n number of times.
;;shuffle-deck: (listof Card) Nat -> (listof Card)
(define (shuffle-deck d n)
  (cond [(<= n 0) d]
        [else (shuffle-deck (move-to-front d (random num-cards)) (sub1 n))]))

;;(move-to-front d n) consumes a list of elements d and a ;;number n and moves the card in position n to the front of the 
;;list.
;;move-to-front: (listof Card) Nat -> (listof Card)
(define (move-to-front d n)
  (cons (list-ref d n) (remove-from-list d n)))

;;(remove-from-list d n) consumes a list of elements d and a ;;number n and removes the card in position n of the list.
;;remove-from-list: (listof Card) Nat -> (listof Card)
(define (remove-from-list d n)
  (cond [(= n 0) (rest d)]
        [else (cons (first d) (remove-from-list (rest d) (sub1 n)))]))

  
  
  
  