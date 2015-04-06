#lang racket

(require file/md5)

(provide get-runc-magic)

;; you shouldn't be looking here!

(define (get-runc-magic id)
  (display (cond
             [(false? (getenv "GEDIT_CURRENT_DOCUMENT_NAME")) "OOPS! You don't appear to be using gEdit (RunC)"]
             [(or (false? (getenv "RUNC"))
                  (> 2 (string->number (getenv "RUNC")))) "OOPS! You don't appear to be using a recent version of RunC"]
             [(equal? id 12345678) "OOPS! You didn't change your student Number!"]
             [else (string-append "Your Racket RunC Magic Number is: " 
                                  (number->string (apply + (bytes->list (md5 (number->string id))))))]))
  (display "\n"))
