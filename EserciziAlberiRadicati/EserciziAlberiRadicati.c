Esercizi delle slides 110-alberi-radicati-07.pdf
==============================================================
Esercizio 1: Scrivi lo pseudocodice delle funzioni;	NEW_TREE(); 
IS_EMPTY(t); ROOT(t); LEFT(t,n); RIGHT(t,n); INFO(t,n)
--------------------------------------------------------------
NEW_TREE()
   /* t e' un oggetto con il solo attributo "root" che e'
      un riferimento ad un nodo dell'albero con i campi
      parent, left, right (riferimenti) e info (intero) */

    t.root = NULL
    return t
--------------------------------------------------------------
IS_EMPTY(t)
	return t.root == NULL
--------------------------------------------------------------
ROOT(t)
	return t.root  /* ritorna NULL se l'albero e' vuoto */
--------------------------------------------------------------
LEFT(t,n)
	return n.left /* ritorna NULL se n non ha figlio sinistro */
--------------------------------------------------------------
RIGHT(t,n)
	return n.right /* ritorna NULL se n non ha figlio sinistro */
--------------------------------------------------------------
INFO(t,n)
	return n.info
==============================================================
Esercizio 2: Scrivi lo pseudocodice della funzione 
TWO_CHILDREN(n) che ritorna TRUE se il nodo n ha due figli, 
FALSE altrimenti
--------------------------------------------------------------
TWO_CHILDREN(n)
	return (n.left != NULL) && (n.right != NULL)
==============================================================
Esercizio 3: Scrivi lo pseudocodice della procedura
ADD_ROOT(t,z) che aggiunga il nodo radice con 
valore z all'albero binario t 
--------------------------------------------------------------
ADD_ROOT(t,z)
	/* temp e' un nuovo nodo dell'albero con campi parent,
	   left, right (riferimenti) e info (intero) */
	temp.parent = NULL
	temp.left = NULL
	temp.right = NULL
	temp.info = z
	t.root = temp
==============================================================
Esercizio 4: Scrivi lo pseudocodice delle procedure 
ADD_LEFT(t,n,z) e ADD_RIGHT(t,n,z) che aggiungono il figlio
sinistro e destro al nodo n, contenente il valore z
--------------------------------------------------------------
ADD_LEFT(t,n,z)
	/* temp e' un nuovo nodo dell'albero con campi parent,
	   left, right (riferimenti) e info (intero) */
	temp.parent = n
	temp.left = NULL
	temp.right = NULL
	temp.info = z
	n.left = temp
--------------------------------------------------------------
ADD_RIGHT(t,n,z)
	/* temp e' un nuovo nodo dell'albero con campi parent,
	   left, right (riferimenti) e info (intero) */
	temp.parent = n
	temp.left = NULL
	temp.right = NULL
	temp.info = z
	n.right = temp
==============================================================
Esercizio 5: Scrivi lo pseudocodice della funzione ONLY_LEFT(t) 
che restituisce TRUE se tutti i nodi dell’albero binario t 
hanno solamente il figlio sinistro (o nessun figlio), FALSE altrimenti.
Se l'albero e' vuoto restituisci TRUE.
---------------------------------------------------------------
ONLY_LEFT(t)
	n = t.root
	while ( n != NULL )
		if (n.right != NULL)
			return FALSE
		n = n.left
	return TRUE
===============================================================
Esercizio 6: Scrivi lo pseudocodice della procedura
ADD_ROOT(t,z) che aggiunga un nodo radice con valore z 
all'albero t. Supponi che l’albero t sia vuoto
---------------------------------------------------------------
ADD_ROOT(t,z)
	/* temp e' un nuovo nodo dell'albero con campi parent,
	   left, right (riferimenti) e info (intero) */
	temp.parent = NULL
	temp.left = NULL   /* ancora non ho figli */
	temp.right = NULL  /* la radice non ha fratelli */
	temp.info = z
	t.root = temp
===============================================================
Esercizio 7: Scrivi lo pseudocodice della procedura 
ADD_SIBLING(t,n,z) che aggiunge al nodo n un figlio che contiene 
il valore z.
---------------------------------------------------------------
ADD_SIBLING(t,n,z)
	/* temp e' un nuovo nodo dell'albero con campi parent,
	   left, right (riferimenti) e info (intero) */
	temp.parent = n
	temp.left = NULL   /* ancora non ho figli */
	temp.right = n.left    
	temp.info = z
	n.left = temp  /* ora sono il primo figlio di n */
================================================================