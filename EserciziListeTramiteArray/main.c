Esercizi 1-4  del file 080-liste-tramite-array-02.pdf
================================================================
/* Esercizio 1: Scrivi lo pseudocodice della procedura SIZE(l) che 
   conta gli elementi della lista l */
----------------------------------------------------------------
SIZE(l)  /* conta gli elementi della lista l realizzata tramite array */

	cont = 0  /* conta gli elementi della lista */
	i = HEAD(l)    /* iteratore al primo elemento della lista */ 
	while ( i != NULL_ITERATOR() )  /* questo funzionerebbe con 
	                                   tutte le realizzazioni */
	while ( i != -1 )               /* questo funziona solo 
	                                   con liste realizzate 
	                                   tramite array */
	    cont = cont + 1
	    i = NEXT(l,i)

    return cont
-----------------------------------------------------------------
NULL_INTERATOR()  /* definisce la costante iteratore nullo */
	return -1
-----------------------------------------------------------------
NEXT(l,i)    /* ritorna l'iteratore successivo ad i */
	return l.next[i]
-----------------------------------------------------------------
HEAD(l)    /* ritorna l'iteratore che punta al primo elemento
              di l */
    return l.head
=================================================================
/* Esercizio 2: Scrivi lo pseudocodice della procedura SEARCH(l,k) 
che restituisce la posizione del primo elemento di l con valore 
della chiave k. */
-----------------------------------------------------------------
SEARCH(l,k)  /* ritorna l'iteratore dell'elemento contenente il
                valore k (la prima occorrenza di k) */
    i = HEAD(l)
    while( i != NULL_ITERATOR() )            
    	if INFO(l,i) == k
    		return i
    	i = NEXT(l,i)
    return NULL_ITERATOR()	/* analogo a "return i" */
-----------------------------------------------------------------
INFO(l,i)  /* ritorna l'elemento (intero) della lista in 
              posizione i */
    if ( i == NULL_ITERATOR() ) 
    	errore("INFO su iteratore nullo")
    return l.key[i]
=================================================================
/* Esercizio 3: Scrivi lo pseudocodice della procedura DELETE(l,i) 
   che rimuove da l l’elemento in posizione i. */
-----------------------------------------------------------------
DELETE(l,i)  /* rimuove l'elemento in posizione i */

    if (i == NULL_ITERATOR() )
    	errore("rimozione di un iteratore nullo")

    if (l.prev[i] != NULL_ITERATOR() )
    	l.next[l.prev[i]] = l.next[i]
    else
    	l.head = l.next[i]

    if (l.next[i] != NULL_ITERATOR() )
    	l.prev[l.next[i]] = l.prev[i]

    FREE_COLUMN(l,i)
==================================================================
/* Esercizio 4: Scrivi lo pseudocodice della procedura DELETE(l,x) 
   che rimuove da l il primo elemento che ha valore x */
------------------------------------------------------------------
DELETE(l,x)

	i = SEARCH(l,x)
	DELETE(l,i)
-------------------------------------------------------------------
DELETE(l,x)  /* assumo che x appartenga sempre alla lista l */

	i = HEAD(l)
	while ( i != NULL_ITERATOR() )
		if (INFO(i) == x)  /* trovato l'elemento da rimuovere */

			if PREV(l,i) == NULL_ITERATOR()
				l.head = l.next[i]
			else
				l.next[l.prev[i]] = l.next[i]

			if NEXT(l,i) == NULL_ITERATOR()
				l.prev[l.next[i]] = l.prev[i]
			FREE_COLUMN(l,i)
			return
        i = NEXT(l,i)
===================================================================








	
