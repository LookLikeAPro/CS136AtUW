#lang racket
#lang racket

;; Step 1. O(1), see below:
;;      empty?: O(1)
;;      first:  O(1)
;;      rest:   O(1)
;;      +:      O(1)
;;      O(1) + O(1) + O(1) + O(1) = O(1)
;; Step 2. n - 1
;; Step 3. T(n) = O(1) + T(n - 1)
;; Step 4. T(n) = O(n)
;;   TIME: O(n), where n is the length of lon
(define (sum lon)
	(cond [(empty? lon) 0]
				[else (+ (first lon) (sum (rest lon)))]))

;;---------------------------------------------------------
;; Step 1. O(1), see below:
;;		cond: O(1)
;;      empty?x2: O(1)
;;		or:     O(1)
;;      firstx2:  O(1)
;;      >:       O(1)
;;      rest:   O(1)
;;      firstx2:  O(1)
;;      <:       O(1)
;;      rest:     O(1)
;;      cons:      O(1)
;;      restx2:    O(1)
;;      O(1) x 16 = O(1)
;; Step 2. n - 1
;; Step 3. T(n) = O(1) + T(n - 1)
;; Step 4. T(n) = O(n)
;;   TIME: O(n), where n is the length of the shorter list of l1 and l2
(define (sorted-intersection lst1 lst2)
	(local
		;; common: (listof num)[sorted](listof num)[sorted] -> (listof num)
		[(define (common l1 l2)
			 (cond
				 [(or (empty? l1)(empty? l2)) empty]
				 [(> (first l1) (first l2)) (common (rest l1) l2)]
				 [(< (first l1) (first l2)) (common l1 (rest l2))]
				 [ else (cons (first l1) (common (rest l1)(rest l2)))]))
		 (define l1 (sort lst1 >))
		 (define l2 (sort lst2 >))]
		(common l1 l2)))

;;---------------------------------------------------------
;; Step 1. O(n), see below:
;;		length: O(n)
;;      foldr +:  O(n)
;;      /:        O(1)
;;      map sqdiff: O(n)
;;      -x2: O(1)
;;		*:     O(1)
;;		foldr +: O(n)
;;		/:     O(1)
;;		sqrt:    O(1)
;;      O(1) x 3 + O(n) x 3 = O(n)
;; Step 2. n - 1
;; Step 3. T(n) = O(n) + T(0)
;; Step 4. T(n) = O(n)
;;   TIME: O(n), where n is the length of nlst
(define (standard-deviation nlst)
	(local
		[(define n (length nlst)) 
		 (define avgx (/ (foldr + 0 nlst) n)) 
		 (define (sqdiff x)
				(* (- x avgx) (- x avgx)))]
		;; main function body
		(sqrt(/ (foldr + 0 (map sqdiff nlst)) n))))

;;---------------------------------------------------------
;; Step 1. O(n), see below:
;;		sort: O(nlogn) ;;Only happens once. Not included in recurrence calculation
;;      rest:  O(1)
;;      empty?:  O(1)
;;      first: O(1)
;;      rest x2: O(1)
;;		empty?:     O(1)
;;		first: O(1)
;;		second:     O(1)
;;		/:    O(1)
;;      rest: O(1)
;;      drop-right: O(n)
;;      O(1) x 10 + O(n) = O(n)
;; Step 2. n - 1
;; Step 3. T(n) = O(n) + T(n - 1)
;; Step 4. T(n) = O(n^2)
;;   TIME: O(n^2), where n is the length of lon
(define (median lon)
	(define (median-helper sorted)
		(cond
			((empty? (rest sorted)) (first sorted))
			((empty? (rest (rest sorted))) 
			 (/ (+ (first sorted) (second sorted)) 2))
			(else (median-helper (drop-right (rest sorted) 1)))))
	(median-helper (sort lon <)))


;;---------------------------------------------------------
;; Step 1. O(1), see below:
;;		printf: O(1)
;;      =:  O(1)
;;      printf:  O(1)
;;      sub1: O(1)
;;      printf: O(1)
;;      O(1) x 5 = O(1)
;; Step 2. n - 1
;; Step 3. T(n) = O(1) + T(n - 1)
;; Step 4. T(n) = O(n)
;;   TIME: O(n), where n is the n parameter of (drawing n)
;; requires: n>=0
(define (drawing n)
	(begin
		(printf "~a\n" n)
		(cond
			[(= n 1) (printf "***\n")]
			[else (drawing (sub1 n))])
		(printf "~a\n" n)))


;;---------------------------------------------------------

;;Running time of draw-helper
;; Step 1. O(1), see below:
;;      =:  O(1)
;;      printf:  O(1)
;;      printf:  O(1)
;;      sub1: O(1)
;;      O(1) x 4 = O(1)
;; Step 2. n - 1
;; Step 3. T(n) = O(1) + T(n - 1)
;; Step 4. T(n) = O(n)
;;   TIME: O(n), where n is the k parameter of (draw-helper k)
;;Running time of draw
;; Step 1. O(n), see below:
;;      =:  O(1)
;;      printf:  O(1)
;;      printf:  O(1)
;;      draw-helper: O(n)
;;      sub1:    O(1)
;;      O(1) x 4 + O(n) = O(n)
;; Step 2. n - 1
;; Step 3. T(n) = O(n) + T(n - 1)
;; Step 4. T(n) = O(n^2)
;;   TIME: O(n^2), where n is the n parameter of (draw n)
;; requires: k>=0
(define (draw-helper k)
	(cond
		[(= k 0) (printf "\n")]
		[else (begin
						(printf "*")
						(draw-helper (sub1 k)))]))
;; requires: n>=0
(define (draw n)
	(cond
		[(= n 0) (printf "\n")]
		[else (begin
						(printf "~a\n" n)
						(draw-helper  n)
						(draw (sub1 n)))]))
						