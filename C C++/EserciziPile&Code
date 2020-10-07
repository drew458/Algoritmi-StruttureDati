Esercizi 1-4 su pile e code del file 080-tipi-astratti-di-dato-03.pdf
=========================================================================
/* Esercizio 1: scrivi lo pseudocodice della procedura NEW_QUEUE() che 
   restituisce il riferimento ad una coda vuota */

NEW_QUEUE()    /* crea e ritorna una coda vuota */

	/* c e' un oggetto con i campi c.head e c.tail che sono interi
	   e c.A che e' un array di 8 interi. */

	c.tail = 0
	c.head = 0
	return c 

=========================================================================
/* Esercizio 2: Scrivi lo pseudocodice della procedura SIZE(c) che 
   restituisce il numero di elementi in una coda */

SIZE(c)    /* restituisce il numero di elementi della coda */

     if c.tail >= c.head 
     	return c.tail-c.head
     else   /* c.tail < c.head */
     	return A.length - (c.head - c.tail)

=========================================================================
/* Esercizio 3: Scrivi lo pseudocodice della procedura ENQUEUE(q,x) 
   che abbia complessità ammortizzata Theta(1) */

ENQUEUE(q,x)  

	if (c.head == c.tail+1) OR (c.tail == c.A.length-1 AND c.head == 0)

		/* B e' un nuovo array di interi di dimensione 2*c.A.length  */

		if (c.head == c.tail+1)
			j = 0    /* posizione nell'array B */
			for i = c.tail+1 to c.A.length-1
				B[j] = c.A[i]
				j = j + 1
            for i = 0 to c.tail-1
            	B[j] = c.A[i]
            	j = j + 1
        else
        	for i = 0 to c.A.length-2
        		B[i] = c.A[i]
        c.head = 0
        c.tail = c.A.length-1
        c.A = B                 /* sostituisco l'array A con l'array B */
    
    c.A[c.tail] = x
    if (c.tail == c.A.length-1)
    	c.tail = 0
    else
    	c.tail = c.tail + 1

=========================================================================
/* Esercizio 4: Descrivi come sia possibile implementare un coda 
   utilizzando esclusivamente pile */
-------------------------------------------------------------------------   
NEW_QUEUE()
	/* creo un oggetto c che contiene due pile vuote c.p1 e c.p2 */
	return c
-------------------------------------------------------------------------   
ENQUEUE(c,x)  /* c e' un oggetto che contiene due pile c.p1 e c.p2 */

	while ( ! IS_EMPTY(c.p2) )
		PUSH(c.p1, POP(c.p2))

	PUSH(c.p1,x)
-------------------------------------------------------------------------   
DEQUEUE(c)   /* c e' un oggetto che contiene due pile c.p1 e c.p2 */

    while ( ! IS_EMPTY(c.p1) )
    	PUSH(c.p2, POP(c.p1))

    if( IS_EMPTY(c.p2))
        error("coda vuota!")

    return POP(c.p2)
=========================================================================    
