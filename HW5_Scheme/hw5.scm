(define mycount                                                                     ; define function
    (lambda (num lst)                                                               ; num is # to search for, lst is the list
        (cond ((null? lst) 0)                                                       ; handle null case
            ((list? (car lst)) (+ (mycount num (car lst)) (mycount num (cdr lst)))) ; if head is a list, run through list and add total, then keep going
            ((= (car lst) num) (+ 1 (mycount num (cdr lst))))                       ; add 1 if found, then keep going
            (else (mycount num (cdr lst))))))                                       ; otherwise, don't add 1 and keep going
			  
(define tagmatch                                                                            ; define function
    (lambda (num lst)                                                                       ; num is # to search for, lst is the list
        (cond ((null? lst) '())                                                             ; handle null case
            ((list? (car lst)) (cons (tagmatch num (car lst)) (tagmatch num (cdr lst))))    ; if head is a list, run through that list, add it, then keep going
            ((= (car lst) num) (cons 1 (tagmatch num (cdr lst))))                           ; append 1 if found, then keep going
            (else (cons 0 (tagmatch num (cdr lst)))))))                                     ; otherwise, append 0, then keep going

