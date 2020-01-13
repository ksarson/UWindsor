;;Kolby Sarson
;;104232327
;;Assignment 1
;;Due: October 9, 2019, 11:59pm
;;My program is Left-Associative

#lang racket

(define (calculator calc) ;;Define the procedure
 (cond
  ((equal? (length calc) 1) (car calc)) ;;If there is only one element, then that is the answer
  (else (calculator (cons ;;Return a new pair with using the next 2 lines as the 2 elements
                     (eval (cons (cadr calc) (cons (car calc) (cons (caddr calc) '())))) ;;Eval the first 2 numbers using the first symbol and return the resulting number
                     (cdddr calc)))) ;;Obtain the rest of the elements in the list
 )
)

;;equal? that both elements are equivalent
;;cons returns a new pair with elements (a d)
;;eval evaluates two elements separated by a symbol
;;car returns the first element of a pair (a)
;;cdr returns the second element of a pair (d)
;;cadr returns the first element of the second element
;;caddr returns the first element (of the second element's second element)
;;cdddr returns the second elment (of the second element's second element)