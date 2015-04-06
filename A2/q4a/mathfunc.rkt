#lang racket

;; Jiayu Zhou
;; CS136 Winter 2015
;; Assignment 2, Problem 4a

(provide max2 min2 maxfactor coprime )

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;(max2 a b) consumes two integers a and b and produces the
;;max value between them
;;max2: Int Int -> Int

;;(min2 a b) consumes two integers a and b and produces the
;;minimum value between them
;;min2: Int Int -> Int

;;(maxfactor a) consumes a integer and produces the largest
;;integer factor of it
;;maxfactor: Int -> Int

;;(coprime a b) consumes integers a and b, produces true if
;;they are coprime and false if not
;;coprime: Nat Nat -> Bool

;;(findfactor a f) consumes integer a and integer f, and 
;;produces the largest value possilbe from f and up that divides 
;;a into integer factors
;;findfactor: Int Int -> Int

;;(testfactor a b i) consumes integers a, b and i, and produces
;;the largest possible integer from i and up that divides a 
;;and b with no remainders.
;;testfactor: Int Int Int -> Int

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; See interface above.
(define (max2 a b)
  (cond [(> a b) a]
        [else b]))

;; See interface above.
(define (min2 a b)
  (cond [(> a b) b]
        [else a]))

(define (findfactor a f)
  (cond [(= (remainder a f) 0) f]
        [else (findfactor a (- f 1))]))

;; See interface above.
(define (maxfactor a)
  (findfactor (abs a) (quotient a 2)))

(define (testfactor a b i)
  (cond [(or (> i b) (> i a)) 1]
        [(= 0 (remainder a i) (remainder b i)) 
         (max2 i (testfactor a b (+ 1 i)))]
        [else (testfactor a b (+ 1 i))]))

;; See interface above.
(define (coprime a b)
  (cond [(=(testfactor (abs a) (abs b) 1) 1) #t]
        [else #f]))

