Esercizi del file 100-liste-tramite-oggetti-06.pdf
====================================================================
Esercizio 1: Scrivi lo pseudocodice della procedura MASSIMO(l) 
che ritorna il valore del massimo elemento contenuto in una lista 
singolarmente concatenata di interi (assumi che la lista non sia mai vuota)

MASSIMO(l)
	massimo = l.head.info   /* la lista non e' mai vuota */

	x = l.head
	while ( x != NULL )
        if( x.info > massimo)
        	massimo = x.info
		x = x.next

    return massimo
=====================================================================
Esercizio 2: Scrivi lo pseudocodice della procedura SOMMA(l) che ritorna 
la somma degli elementi contenuti in una lista singolarmente concatenata di interi

SOMMA(l)
	somma = 0   

	x = l.head
	while ( x != NULL )
        	somma = somma + x.info
		x = x.next

    return somma
======================================================================
Esercizio 3. Scrivi lo pseudocodice della procedura SEARCH(l,u) che ritorna 
il riferimento all’elemento i che contiene il valore intero u in una lista 
singolarmente concatenata di interi (oppure NULL se u non è nella lista)

SEARCH(l,u)

	x = l.head
	while ( x != NULL )
		if ( x.info == u )
			return x
		x = x.next

	return NULL    /* oppure "return x" */

-----------------------------------------------------------------------
Altra versione con un solo return.
-----------------------------------------------------------------------
SEARCH(l,u)

	x = l.head
	while ( x != NULL )
		if ( x.info == u )
			break
		x = x.next
	return x
-----------------------------------------------------------------------
Versione alternativa un po' prolissa
-----------------------------------------------------------------------
SEARCH(l,u)

    output = NULL
	x = l.head
	while ( x != NULL )
		if ( x.info == u )
			output = x
		x = x.next
	return x
=======================================================================
Esercizio 4: Scrivi lo pseudocodice della procedura PREV(l,i) che ritorna 
il riferimento all’elemento che precede l’elemento i in una lista 
singolarmente concatenata di interi (oppure NULL se i è il primo elemento 
della lista)

PREV(l,i)

	x = l.head
	while ( x != NULL )
		if( x.next == i )
			return x
		x = x.next
    return NULL    /* non ho trovato i oppure i e' il primo elemento */
=======================================================================
Esercizio 5. Scrivi lo pseudocodice dell’operazione DELETE(l,i) che cancella il nodo i 
di una lista singolarmente concatenata

DELETE(l,i)

	prec = PREV(l,i) /* se prec e' NULL allora i primo della lista
	                    oppure i non appartenente alla lista */
	if ( prec == NULL )
		if ( i == l.head )  /* i primo della lista */
			l.head = l.head.next
		return 

	/* ora prec != NULL */

    prec.next = i.next  /* equivalente: "prec.next = prec.next.next" */
=======================================================================
Esercizio 6. Scrivi lo pseudocodice dell’operazione DELETE(l,u) che 
cancella il nodo che contiene il valore intero u in una lista 
singolarmente concatenata di interi. Supponiamo che u sia sempre il lista.

DELETE(l,u)
   if( l.head.info == u )       
   		l.head = l.head.next    /* u e' il primo elemento */
   		return

   x = l.head
   while ( x != NULL )
      if ( x.next != NULL )
      	  if( x.next.info == u )
      	      x.next = x.next.next
      	      return
   	  x = x.next
-----------------------------------------------------------------------
Versione alternativa
-----------------------------------------------------------------------
DELETE(l,u)
   if( l.head.info == u )       
   		l.head = l.head.next    /* u e' il primo elemento */
   		return

   x = l.head  /* x e' sicuramente diverso da NULL */
   while ( x.next != NULL )
      if( x.next.info == u )
      	  x.next = x.next.next
      	  return
   	  x = x.next
=======================================================================




Esercizi 9-12,15,17 delle slides 100-liste-tramite-oggetti-06.pdf
==============================================================
Esercizio 9: Scrivi lo pseudocodice della procedura 
COMUNI(l1,l2) che ritorna il numero di elementi della lista l1 
che sono anche contenuti nella lista l2
--------------------------------------------------------------
COMUNI(l1,l2) 
	contatore = 0  /* conta gli elementi comuni con l2 */

	x = l1.head
	while (x != NULL)

		y = l2.head
		while ( y != NULL)

			if( y.info == x.info )
				contatore++
				break   /* solo se voglio trattare il caso 
				           di occorrenze multiple dentro l2 */
			y = y.next
		x = x.next

    return contatore
==============================================================
Esercizio 10: Scrivi lo pseudocodice della procedura non ricorsiva 
INVERSA(l) che ritorna una nuova lista singolarmente concatenata 
in cui gli elementi sono in ordine inverso
--------------------------------------------------------------
INVERSA(l)  
	/* l2 e' una nuova lista vuota */
	l2.head = NULL
	x = l.head
	while ( x != NULL)

		/* temp e' un nuovo elemento di una lista semplicemente
		   concatenata di interi con i campi info (intero) e 
		   next (riferimento) */

        temp.info = x.info
        temp.next = l2.head
        l2.head = temp

		x = x.next

    return l2

==============================================================
Esercizio 11: Scrivi lo pseudocodice della precedura ACCODA(l1,l2) 
che accoda gli elementi della lista l2 alla lista l1 mantenendo 
l'ordine relativo che gli elementi avevano nelle liste originarie
Puoi supporre di poter modificare le liste in input
--------------------------------------------------------------
ACCODA(l1,l2)

   x = l1.head
   if (x == NULL)  /* la prima lista era vuota */
   		return l2

   while( x.next != NULL ) 
   		x = x.next

   x.next = l2.head
   l2.head = NULL   /* tronco la seconda lista */

   return l1
===============================================================
Esercizio 11: Scrivi lo pseudocodice della precedura ACCODA(l1,l2) 
che accoda gli elementi della lista l2 alla lista l1 mantenendo 
l'ordine relativo che gli elementi avevano nelle liste originarie
ORA SUPPONIAMO DI NON POTER MODIFICARE LE DUE LISTE
---------------------------------------------------------------
ACCODA(l1,l2)

   /* l3 e' una nuova lista semplicemente concatenata di interi */
   l3.head = NULL 

   ultimo = NULL    /* ultimo elemento della lista l3 */

   x = l1.head
   while (x != NULL)

    	/* temp e' un nuovo elemento di una lista semplicemente
		   concatenata di interi con i campi info (intero) e 
		   next (riferimento) */

		temp.info = x.info
		temp.next = NULL

		if(ultimo == NULL)   /* temp e' il primo elemento che 
		                        aggiungo ad l3 */
			l3.head = temp
        else 
        	ultimo.next = temp
        	ultimo = temp

        x = x.next


   y = l2.head
   while (y != NULL)

    	/* temp e' un nuovo elemento di una lista semplicemente
		   concatenata di interi con i campi info (intero) e 
		   next (riferimento) */

		temp.info = y.info
		temp.next = NULL

		if(ultimo == NULL)   /* temp e' il primo elemento che 
		                        aggiungo ad l3 */
			l3.head = temp
        else 
        	ultimo.next = temp
        	ultimo = temp

        y = y.next

    return l3
===============================================================   
ACCODA(l1,l2)  /* strategia di costruzione della lista rovesciata: 
(1) scorro la lista l1 e inserisco in testa ad l3
(2) scorro la lista l2 e inserisco in testa ad l3
(3) inverto l3 */

   /* l3 e' una nuova lista semplicemente concatenata di interi */
   l3.head = NULL 

	x = l1.head
	while ( x != NULL)
		/* temp e' un nuovo elemento di una lista semplicemente
		   concatenata di interi con i campi info (intero) e 
		   next (riferimento) */
        temp.info = x.info
        temp.next = l3.head
        l3.head = temp
		x = x.next
	 
	x = l2.head
	while ( x != NULL)
		/* temp e' un nuovo elemento di una lista semplicemente
		   concatenata di interi con i campi info (intero) e 
		   next (riferimento) */
        temp.info = x.info
        temp.next = l3.head
        l3.head = temp
		x = x.next

    return INVERSA(l3)
=================================================================
Esercizio 12: Scrivi lo pseudocodice dell’operazione 
INSERT_BEFORE(l,n,i) che riceva come parametri una lista 
doppiamente concatenata l, un intero n ed un iteratore i, 
e inserisca n nella lista prima dell’elemento riferito da i
-----------------------------------------------------------------
INSERT_BEFORE(l,n,i) 

	/* temp e' un nuovo elemento di una lista semplicemente
	   concatenata di interi con i campi info (intero), 
	   next e prev (riferimenti) */

	temp.info = n
    temp.next = i
    temp.prev = i.prev

    i.prev = temp

    if( temp.prev == NULL) /* i era il primo elemento della 
                              lista */
        l.head = temp
    else
    	temp.prev.next = temp
==============================================================
Esercizio 15: Scrivi lo pseudocodice della procedura DELETE(l,u) 
che rimuova l’elemento che ha valore u da una lista doppiamente 
concatenata di interi
--------------------------------------------------------------
DELETE(l,u)  /* u e' un intero */

	x = l.head
	while ( x != NULL )

		if ( x.info == u )   /* ho trovato l'elemento da
		                        rimuovere */
		    if( x.prev != NULL)
		    	x.prev.next = x.next
		    else
		    	l.head = x.next

		    if( x.next != NULL )
		    	x.next.prev = x.prev
            return
		x = x.next
==============================================================
Esercizio 17: Scrivi lo pseudocodice della procedura MERGE(l1, l2) 
che accetti come parametri due liste doppiamente concatenate 
di interi ordinate in senso crescente e restituisca una lista 
ordinata in senso crescente con gli elementi di entrambe
--------------------------------------------------------------
MERGE(l1,l2)

	/* l3 nuova lista vuota */
	l3.head = NULL

	x = l1.head
	y = l2.head
	while ( (x != NULL) && (y != NULL) )

		if( x.info < y.info )

			INSERISCI_IN_TESTA(l3, x.info)
			x = x.next
		else
			INSERISCI_IN_TESTA(l3, y.info)
			y = y.next

	while ( x != NULL )
		INSERISCI_IN_TESTA(l3,x.info)
		x = x.next

	while ( y != NULL )
		INSERISCI_IN_TESTA(l3,y.info)
		y = y.next

	return INVERTI(l3)

===========================================================
INSERISCI_IN_TESTA(l,u)

	temp.info = u
	temp.prev = NULL
	temp.next = l.head

	if( l.head != NULL )
		l.head.prev = temp

	l.head = temp
===========================================================



Esercizio 20: Scrivi lo pseudocodice della procedura INSERT(l,n) 
che inserisce in testa ad una lista con sentinella l un intero n
------------------------------------------------------------
INSERT(l,n)
	/* temp è un nuovo elemento della lista con i campi 
	   info (intero) next e prev (riferimenti) */
	   
	temp.info = n
	temp.prev = l.null
	temp.next = l.null.next

	l.null.next.prev = temp
	l.null.next = temp
============================================================
Esercizio 21: Scrivi lo pseudocodice della procedura SEARCH(l,n) 
che ritorna un iteratore all'elemento della lista con sentinella l 
che ha valore n 
SEARCH(l,n) ritorna l.null se n non e' presente nella lista l
------------------------------------------------------------
SEARCH(l,n) 
	
	x = l.null.next  /* primo elemento della lista */
	while( x != l.null )
		if ( x.info == u)
			return x
		x = x.next

	return x   /* equivalentemente "return l.null" */
============================================================