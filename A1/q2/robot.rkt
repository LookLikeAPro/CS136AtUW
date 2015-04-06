#lang racket
;; robot.rkt

;; A module for creating a robot arena game.

(provide create-robot move-robot sighted-robots)

;; arena-size defines the number of grid squares along each axis in the arena
(define arena-size 100)

;;;;;;;;;; Implementation ;;;;;;;;;;

(struct arena-posn (x y))
;; An Arena-Posn is a (arena-posn Nat Nat)
;; requires: fields correspond to valid X and Y indices of the arena grid
;;           1 <= x <= arena-size
;;           1 <= y <= arena-size

(struct robot (name orientation location speed))
;; A Robot is a (robot Str Sym Arena-Posn Nat)
;; requires: fields describe the properties and location of a robot in the arena
;;orientation is one 'North, 'East, 'South, 'West


;;(normalize int) consumes a number and if said number is smaller 
;;than 1, produces 1, and if bigger than 100, produces 100, 
;;otherwise it produces the same number
;;normalize: Num -> Num
(define (normalize int)
  (cond [(> int 100) 100]
        [(< int 1) 1]
        [else int]))

;;(drive posn dir move speed) consumes an arena-posn, a direction, a move symbol, and a speed, and produces the posn and direction resulting from the movement.
;;drive: Arena-Posn Sym Sym Nat -> (list Arena-Posn Sym)
;;requires: dir is one of 'North, 'East, 'South, 'West
;;          move is one of 'F, 'B, 'L, 'R
(define (drive posn dir move speed)
  (cond [(symbol=? dir 'North) 
         (cond [(symbol=? 'L move) (list posn 'West)]
               [(symbol=? 'R move) (list posn 'East)]
               [(symbol=? 'F move) (list (arena-posn (arena-posn-x posn) (normalize (+ (arena-posn-y posn) speed))) dir)]
               [(symbol=? 'B move) (list (arena-posn (arena-posn-x posn) (normalize (- (arena-posn-y posn) speed))) dir)])]
        [(symbol=? dir 'West) 
         (cond [(symbol=? 'L move) (list posn 'South)]
               [(symbol=? 'R move) (list posn 'North)]
               [(symbol=? 'F move) (list (arena-posn (normalize (- (arena-posn-x posn) speed)) (arena-posn-y posn)) dir)]
               [(symbol=? 'B move) (list (arena-posn (normalize (+ (arena-posn-x posn) speed)) (arena-posn-y posn)) dir)])]
        [(symbol=? dir 'South) 
         (cond [(symbol=? 'L move) (list posn 'East)]
               [(symbol=? 'R move) (list posn 'West)]
               [(symbol=? 'F move) (list (arena-posn (arena-posn-x posn) (normalize (- (arena-posn-y posn) speed))) dir)]
               [(symbol=? 'B move) (list (arena-posn (arena-posn-x posn) (normalize (+ (arena-posn-y posn) speed))) dir)])]
        [(symbol=? dir 'East) 
         (cond [(symbol=? 'L move) (list posn 'North)]
               [(symbol=? 'R move) (list posn 'South)]
               [(symbol=? 'F move) (list (arena-posn (normalize (+ (arena-posn-x posn) speed)) (arena-posn-y posn)) dir)]
               [(symbol=? 'B move) (list (arena-posn (normalize (- (arena-posn-x posn) speed)) (arena-posn-y posn)) dir)])]))

;;(see? r1 r2) consumes two robots and produces a boolean value indicating whether r2 is within the sight of r1
;;see? Robot Robot -> Bool
(define (see? r1 r2)
  (cond [(symbol=? (robot-orientation r1) 'North) 
         (and (= (arena-posn-x (robot-location r2)) (arena-posn-x (robot-location r1)))
              (> (arena-posn-y (robot-location r2)) (arena-posn-y (robot-location r1))))]
        [(symbol=? (robot-orientation r1) 'South) 
         (and (= (arena-posn-x (robot-location r2)) (arena-posn-x (robot-location r1)))
              (< (arena-posn-y (robot-location r2)) (arena-posn-y (robot-location r1))))]
        [(symbol=? (robot-orientation r1) 'East) 
         (and (= (arena-posn-y (robot-location r2)) (arena-posn-y (robot-location r1)))
              (> (arena-posn-x (robot-location r2)) (arena-posn-x (robot-location r1))))]
        [(symbol=? (robot-orientation r1) 'West) 
         (and (= (arena-posn-y (robot-location r2)) (arena-posn-y (robot-location r1)))
              (< (arena-posn-x (robot-location r2)) (arena-posn-x (robot-location r1))))]))

;; (create-robot n o x y s) produces a robot from the specified arguments
;; create-robot: Str Sym Nat Nat Nat -> Robot
;; requires: o is one of 'North, 'East, 'South, 'West
;;           1 <= x <= arena-size
;;           1 <= y <= arena-size
(define (create-robot n o x y s)
  (robot n o (arena-posn x y) s))

;; (move-robot r lorm) produces the resulting robot after all 
;;movements in lorm are applied to robot r
;; move-robot: Robot (listof (anyof 'L 'R 'F 'B)) -> Robot
(define (move-robot r lorm)
  (cond [(empty? lorm) r]
        [else (local [(define newpos (drive (robot-location r) (robot-orientation r) (first lorm) (robot-speed r)))]
                     (move-robot (robot (robot-name r) (second newpos) (first newpos) (robot-speed r)) (rest lorm)))]))

;;(arena-posn-y (robot-location (move-robot (create-robot "lol" 'North 50 50 1) (list 'F))))

;; (sighted-robots r1 r2) determines which robots can be seen by 
;;at least one other robot.  A robot can see along the horizontal 
;;or vertical grid squares from their location in the direction 
;;they are oriented.
;; sighted-robots: Robot Robot -> (listof Robot)
;; requires: since our game only supports 2 robots, the resulting 
;;list will contain at most 2 robots.
(define (sighted-robots r1 r2)
  (local [(define see1 (see? r1 r2))
          (define see2 (see? r2 r1))]
         (cond [(and see1 see2) (list r1 r2)]
               [see1 (list r2)]
               [see2 (list r1)]
               [else empty])))
;;(sighted-robots (create-robot "lol" 'North 1 1 1)(create-robot "lol" 'South 1 2 1))

