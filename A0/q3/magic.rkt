#lang racket

(require file/md5)

(provide conjure-magic)

;; you shouldn't be looking here!

(define (conjure-magic id)
  (display (cond
             [(equal? id 12345678) "OOPS! You didn't change your student Number!"]
             [else (string-append "Your Racket RunC Magic Number is: " 
                                  (number->string (apply + (bytes->list (md5 (number->string id))))))]))
  (display "\n"))
