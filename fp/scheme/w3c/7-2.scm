(define mysum
  (lambda (ls)
    (if (null? ls)
        0
        (+ (car ls) (mysum (cdr ls))))))