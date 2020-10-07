Esercizi delle slides 120-visite-di-alberi-02.pdf
=============================================================
Esercizio 2: Scrivi lo pseudocodice della procedura CERCA(t,n) 
che ritorna TRUE se il valore n e' presente nell'albero binario 
t facendo uso di una visita in preordine
-------------------------------------------------------------
CERCA(t,n) /* t e' un albero con il campo t.root */
   return CERCA_RIC(t.root,n)

-------------------------------------------------------------
CERCA_RIC(v,n)  /* v e' un nodo; n e' un intero */

	if( v == NULL ) return FALSE

	if( v.info == n )  /* ho trovato il nodo contenente n */
		return TRUE

	L = CERCA_RIC(v.left,n)
	R = CERCA_RIC(v.right,n)
	return L || R

    /* equivalentemente "return CERCA_RIC(v.left,n) || 
                                CERCA_RIC(v.right,n)"  */
-------------------------------------------------------------
facendo uso di una visita in postordine
-------------------------------------------------------------
CERCA_RIC(v,n)  /* v e' un nodo; n e' un intero */

	if( v == NULL ) return FALSE


	L = CERCA_RIC(v.left,n)
	R = CERCA_RIC(v.right,n)

	if (L || R) return TRUE

	if( v.info == n )  /* ho trovato il nodo contenente n */
		return TRUE
	else
		return FALSE
-------------------------------------------------------------
facendo uso di una visita in simmetrica
-------------------------------------------------------------
CERCA_RIC(v,n)  /* v e' un nodo; n e' un intero */

	if( v == NULL ) return FALSE

	L = CERCA_RIC(v.left,n)
	if (L) return TRUE

	if( v.info == n )  /* ho trovato il nodo contenente n */
		return TRUE

	R = CERCA_RIC(v.right,n)
	if (R) return TRUE
    else return FALSE
-------------------------------------------------------------
procedura difficile da classificare
-------------------------------------------------------------
CERCA_RIC(v,n)  /* v e' un nodo; n e' un intero */

	if( v == NULL ) return FALSE

	return (v.info == n) || 
	       CERCA_RIC(v.left,n) || 
	       CERCA_RIC(v.right,n)
==============================================================
Esercizio 3: Scrivi lo pseudocodice della procedura CONTA-NODI(t) 
che ritorna il numero di nodi dell’albero binario t (fai uso di 
una visita in postordine)
--------------------------------------------------------------
CONTA-NODI(t)
	return CONTA-NODI-RIC(t.root)
--------------------------------------------------------------
CONTA-NODI-RIC(v)   /* v puo' essere NULL */
	
	if ( v == NULL ) return 0

	l = CONTA-NODI-RIC(v.left)
	r = CONTA-NODI-RIC(v.right)
	return 1 + l + r
--------------------------------------------------------------
CONTA-NODI(t)
    if( t.root == NULL) return 0
	else return CONTA-NODI-RIC(t.root)
--------------------------------------------------------------
CONTA-NODI-RIC(v)   /* v non puo' essere NULL */
	
	if( v.left != NULL )
		l = CONTA-NODI-RIC(v.left)
	if( v.right != NULL )	
		r = CONTA-NODI-RIC(v.right)
	return 1 + l + r
==============================================================
Esercizio 4: Scrivi lo pseudocodice della procedura CAMMINO(t) 
che verifica se un albero binario t è un cammino cioe' se tutti 
i nodi hanno grado uno con l'eccezione dell'unica foglia assumi 
che un albero vuoto sia un cammino
--------------------------------------------------------------
CAMMINO(t)
	return CAMMINO_RIC(t.root)

--------------------------------------------------------------
CAMMINO_RIC(n)
	if( n == NULL ) return TRUE

    l = CAMMINO_RIC(n.left)
    r = CAMMINO_RIC(n.right)

    return l && r && (n.left == NULL || n.right == NULL)
==============================================================
Esercizio 5: Scrivi lo pseudocodice della procedura HEIGHT(t) 
che calcola l'altezza di un albero binario t cioe' il numero 
di archi del cammino che va dalla radice alla foglia piu' 
profonda (ritorna -1 se l'albero e' vuoto)
--------------------------------------------------------------
HEIGHT(t)
	return HEIGHT_RIC(t.root)
--------------------------------------------------------------
HEIGHT_RIC(n)  /* n e' un riferimento ad un nodo dell'albero */

	if (n == NULL) return -1

	l = HEIGHT_RIC(n.left)
	r = HEIGHT_RIC(n.right)

	if (l > r) return l+1
	else return r+1
--------------------------------------------------------------
Altra strategia
--------------------------------------------------------------
HEIGHT2(t)
	return HEIGHT_RIC2(t.root,0)   /* zero e' la profondita'
	                                  della radice */  
--------------------------------------------------------------
HEIGHT_RIC2(n,p)  /* n e' un riferimento ad un nodo
                     p e' un intero che rappresenta la 
                     profondita' del nodo n rispetto alla
                     radice dell'albero */

    if (n == NULL) return -1   /* valore convenzionale per
                                  segnalare che non c'e' nessuna
                                  foglia */
    l = HEIGHT_RIC2(n.left,p+1)
    r = HEIGHT_RIC2(n.right,p+1)

    if( l==-1 && r==-1)  /* sono una foglia */
     	return p         /* profondita' della foglia piu' profonda
     	                    contenuta in questo sottoalbero */
    if ( l > r ) return l
    else return r
==============================================================
Esercizio 6: Scrivi lo pseudocodice della procedura AVERAGE(t) 
che calcoli la media dei valori contenuti in un albero binario t 
(puoi far uso o meno di CONTA-NODI(t); se l'albero e' vuoto 
produci un errore).
--------------------------------------------------------------
AVERAGE(t)
	num = CONTA_NODI(t)
	somma = SOMMA_NODI_RIC(t.root)
	if (t.root == NULL ) 
		errore(AVERAGE lanciato su un albero vuoto) 
	else
		return somma/num
--------------------------------------------------------------
SOMMA_NODI_RIC(n)  /* n e' un riferimento ad un nodo */

	if (n == NULL)  return 0

	return n.info + SOMMA_NODI_RIC(n.left) + 
	                SOMMA_NODI_RIC(n.right)
--------------------------------------------------------------
AVERAGE(t)  /* una sola visita */
 	/* A e' un array di interi con due caselle */
 	A[0] = 0    /* numero dei nodi */
 	A[1] = 0    /* somma dei nodi */
 	AVERAGE_RIC(t.root,A)
 	if( A[0] == 0 )
		errore("AVERAGE lanciato su un albero vuoto") 
    else return A[1]/A[0]
--------------------------------------------------------------
AVERAGE_RIC(n,A)
	
    if (n == NULL) return

    AVERAGE_RIC(n.left,A) 
    AVERAGE_RIC(n.right,A)

    A[0] = A[0]+1
    A[1] = A[1]+n.info
---------------------------------------------------------------


Esercizi delle slides 120-visite-di-alberi-02.pdf
==================================================================
Esercizio 7: Scrivi lo pseudocodice della procedura COMPLETO(t) che 
verifichi se un albero binario t e' completo. Puoi far uso o meno 
della procedura HEIGHT(t). Se l'albero e' vuoto ritorna TRUE.
------------------------------------------------------------------
COMPLETO(t) 
	f = CONTA_FOGLIE(t)
	h = HEIGHT(t)
	return  2^h == f
------------------------------------------------------------------
CONTA_FOGLIE(t)
	return CONTA_FOGLIE_RIC(t.root)
------------------------------------------------------------------
CONTA_FOGLIE_RIC(n)
	if (n == NULL) return 0
	if ((n.left == NULL)&&(n.right == NULL))
		return 1
	return CONTA_FOGLIE_RIC(n.left) + CONTA_FOGLIE_RIC(n.right)
------------------------------------------------------------------
COMPLETO2(t)
	return COMPLETO_RIC(t.root) != -1
------------------------------------------------------------------
COMPLETO_RIC(n)  /* ritorna -1 se n e' la radice di un albero 
                    non completo, oppure h se n e' la radice di
                    un albero completo di profondita' h */
    if( n == NULL ) return -1  /* l'albero vuoto non e' completo */
    if((n.left == NULL)&&(n.right == NULL))    /* sono una foglia */
    	return 0     /* una foglia e' un albero completo di prof. 0 */
    l = COMPLETO_RIC(n.left)
    r = COMPLETO_RIC(n.right)
    if ( l == -1 ) return -1      /* ora sono sicuro che l ed r 
                                     non sono entrambi -1 */
    if ( l == r ) return l+1
    return -1
------------------------------------------------------------------
COMPLETO_RIC(n)  /* ritorna -1 se n e' la radice di un albero 
                    non completo, oppure h se n e' la radice di
                    un albero completo di profondita' h */
    if( n == NULL ) return -1  /* l'albero vuoto non e' completo */
    if((n.left == NULL)&&(n.right == NULL))    /* sono una foglia */
    	return 0     /* una foglia e' un albero completo di prof. 0 */
    l = COMPLETO_RIC(n.left)
    r = COMPLETO_RIC(n.right)
    if ( (l == r) && ( l != -1) ) return l+1
    return -1
==================================================================
Esercizio 8: Scrivi lo pseudocodice della procedura DEALLOCA(t) che rimuova (deallocandoli) tutti i nodi di un albero t
------------------------------------------------------------------
DEALLOCA(t)
	DEALLOCA_RIC(t.root)
	t.root = NULL
------------------------------------------------------------------
DEALLOCA_RIC(n)
	if (n == NULL) return

    DEALLOCA_RIC(n.left)
    DEALLOCA_RIC(n.right)

	FREE(n)
==================================================================
Esercizio 9: Scrivi lo pseudocodice della procedura POTA(t,x) che elimini da un albero binario 
il sottoalbero radicato ad un nodo x specificato tramite riferimento.
Puoi omettere di deallocare i nodi potati
------------------------------------------------------------------
POTA(t,x)
    if ( x == t.root )
   	   t.root = NULL
   	   // DEALLOCA_RIC(x)  /* se vuoi anche deallocare */
   	   return
    p = x.parent
    if( x == p.left )  /* ero il figlio sinistro di p */
    	p.left = NULL
    else               /* ero il figlio destro di p */
    	p.right = NULL
    // DEALLOCA_RIC(x)  /* se vuoi anche deallocare i nodi */
    return
=================================================================
ESERCIZIO 10: Scrivi lo pseudocodice della procedura 
POTA_PROFONDITA(t,h) che poti un albero binario lasciando solamente i nodi a profondita' minore di h
puoi fare uso o meno di POTA(t,x)
-----------------------------------------------------------------
POTA_PROFONDITA(t,h)
	POTA_RIC(t,t.root,h)
-----------------------------------------------------------------
POTA_RIC(t,n,h)   /* t e' un albero, n e' un nodo, h e' un intero */
    if (n == NULL) return

    if (h == 0) POTA(t,n)

    POTA_RIC(t,n.left,h-1)
    POTA_RIC(t,n.right,h-1)
-----------------------------------------------------------------
ESERCIZIO 11: Scrivi lo pseudocodice della procedura PARENTETICA-SIMMETRICA(t) che stampi un albero binario t nella rappresentazione parentetica simmetrica
-----------------------------------------------------------------
PARENTETICA-SIMMETRICA(t)
	PARENTETICA_SIM_RIC(t.root)
-----------------------------------------------------------------
PARENTETICA_SIM_RIC(n)
	if ( n == NULL ) 
		PRINT("()")
		return
	PRINT("(")
	PARENTETICA_SIM_RIC(n.left)
	PRINT(n.info)
	PARENTETICA_SIM_RIC(n.right)
	PRINT(")")
=================================================================
ESERCIZIO 13: scrivi lo pseudocodice della procedura
VALORE-NONNO(t) che calcoli il numero di nodi dell’albero binario t che hanno lo stesso valore del genitore del genitore (cioè del nonno)
-----------------------------------------------------------------
VALORE-NONNO(t)
	return VALORE_NONNO_RIC(t.root)
-----------------------------------------------------------------
VALORE_NONNO_RIC(n)
	if (n == NULL) return 0

	l = VALORE_NONNO_RIC(n.left)
	r = VALORE_NONNO_RIC(n.right)

	if ( TESTA_VALORE_NONNO(n))
		return 1 + l + r
	else
		return l+r
-----------------------------------------------------------------
TESTA_VALORE_NONNO(n)
	if( n == NULL ) return FALSE
	if (n.parent == NULL ) return FALSE
	if (n.parent.parent == NULL ) return FALSE
	return n.info == n.parent.parent.info
=================================================================
ESERCIZIO 14: Scrivi lo pseudocodice della procedura DUE-FIGLI(t) che calcoli il numero di nodi nell’albero binario t che hanno esattamente due figli
-----------------------------------------------------------------
DUE-FIGLI(t)
	return DUE_FIGLI_RIC(t.root)
-----------------------------------------------------------------
DUE_FIGLI_RIC(n)
	if (n == NULL) return 0

	l = DUE_FIGLI_RIC(n.left)
	r = DUE_FIGLI_RIC(n.right)

	if ( TESTA_DUE_FIGLI(n))
		return 1 + l + r
	else
		return l+r
-----------------------------------------------------------------
TESTA_DUE_FIGLI(n)  /* n sempre diverso da NULL */
	return (n.left != NULL) && (n.right != NULL)
=================================================================
ESERCIZIO 16: Scrivi la procedura CAMMINO(t,n) che ritorni una lista con gli identificatori dei nodi del cammino dalla radice fino al nodo il cui riferimento e' n. Puoi supporre che n appartenga all'albero
-----------------------------------------------------------------
CAMMINO(t,n)
	/* L e' una nuova lista di interi */
	L.head = NULL
	x = n
	while ( x != NULL )
		AGGIUNGI_IN_TESTA(L,x.info)
		x = x.parent
	return L
-----------------------------------------------------------------
AGGIUNGI_IN_TESTA(L,u)  /* u e' un intero, L doppiamente concatenata */

    /* temp nuovo elemento della lista con campi prev, next 
       (riferimenti) e info (intero) */
    temp.prev = NULL
    temp.next = L.head
    temp.info = u

    if( L.head != NULL )
    	L.head.prev = temp
    L.head = temp
=================================================================








