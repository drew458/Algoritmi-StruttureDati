Esercizio 1: Scrivi lo pseudocodice della funzione ALBERO-RICOPRENTE(g,u)
input: un grafo non orientato g rappresentato da un array g.A di liste di adiacenza e un nodo u
output: un array parent dove parent[v] è l’indice del nodo da cui è stato raggiunto v in una DFS a partire dal nodo u
il parent[u] è convenzionalmente posto uguale a -1
-----------------------------------------------------------------
DFS(g,u)
	// creo un array color di interi con tante posizioni
	// quanti i nodi di g (dim. di g.A)

    for i=0 to color.length-1
    	color[i] = 0     // smarco tutti i nodi
    DFS_visit(g,u,color)
-----------------------------------------------------------------
DFS_visit(g,u,color) 
	color[u] = 1
	x = g.A[u]
	while x != NULL
		if ( color[x.key] == 0 )  // nodo non visitato
			DFS_visit(g,x.key,color)
		x = x.next
-----------------------------------------------------------------
ALBERO_RICOPRENTE(g,u)  // versione che ritorna l'array PARENT
	// creo un array color di interi con tante posizioni quanti sono i nodi di g (dim. di g.A)
	// creo un array PARENT di interi con tante posizioni quanti sono i nodi di g (dim. di g.A)

    for i=0 to color.length-1
    	color[i] = 0     // smarco tutti i nodi
    	PARENT[i] = -1

    DFS_visit_parent(g,u,color,PARENT)
    return PARENT
-----------------------------------------------------------------
DFS_visit_parent(g,u,color,PARENT) 
	color[u] = 1
	x = g.A[u]
	while x != NULL
		if ( color[x.key] == 0 )  // nodo non visitato
			PARENT[x.key] = u
			DFS_visit_parent(g,x.key,color,PARENT)
		x = x.next
===============================================================
Esercizio 2: produci in output un albero t (connesso e di grado arbitrario) con le seguenti caratteristiche
i nodi di t hanno gli stessi indici dei nodi del grafo
c’è un arco in t diretto da un nodo x ad un nodo y solo se nella DFS il nodo y è stato raggiunto da x
-----------------------------------------------------------------
ALBERO_RICOPRENTE(g,u)  // versione che ritorna un albero
	// creo un array color di interi con tante posizioni
	// quanti sono i nodi di g (dim. di g.A)
	// creo un array PARENT di interi con tante posizioni
	// quanti sono i nodi di g (dim. di g.A)

    for i=0 to color.length-1
    	color[i] = 0     // smarco tutti i nodi
    	PARENT[i] = -1

    DFS_visit_parent(g,u,color,PARENT)
    
    /* A e' un albero di grado arbitrario, cioe' un oggetto
       che ha un solo attributo "root" che è un riferimento
       alla radice dell'albero. Ogni nodo dell'albero ha i
       campi: parent, info, left (riferimento al primo figlio),
       right (riferimento al fratello) */

    A.root = NULL  // A in questo momento e' un albero vuoto

    // creo un array NODI di interi che ha tante celle quante g.A

    for i=0 to NODI.length-1
    	/* temp è un nuovo oggetto nodo con i campi parent, info, left (riferimento al primo figlio), right (riferimento al fratello) */
    	temp.parent = NULL
    	temp.info = i
    	temp.left = NULL
    	temp.right = NULL
    	NODI[i] = temp

    A.root = NODI[u]

    for i=0 to PARENT.length-1
    	if( PARENT[i] != -1 )   /* i e' nodo radice oppure
    	                           non e' stato raggiunto */
	    	nodo_corrente = NODI[i]
    		nodo_genitore = NODI[PARENT[i]]

    		nodo_corrente.parent = nodo_genitore
    		nodo_corrente.right = nodo_genitore.left
    		nodo_genitore.left nodo_corrente

    return A
================================================================
Esercizio 3: Scrivi lo pseudocodice della procedura DFS(g,v) nel 
caso in cui il grafo sia rappresentato da una matrice di adiacenza g.A
-----------------------------------------------------------------
DFS_matrice(g,u)
	// creo un array color di interi con tante posizioni
	// quanti i nodi di g (dim. di g.A)

    for i=0 to color.length-1
    	color[i] = 0     // smarco tutti i nodi
    DFS_visit(g,u,color)
-----------------------------------------------------------------
DFS_visit_matrice(g,u,color) 
	color[u] = 1
	for i = 0 to g.A[u].length-1
		if (g.A[u][i] == 1 && color[i] == 0)
			DFS_visit(g,i,color)
================================================================
Esercizio 4: Scrivi lo pseudocodice della procedura DFS(g,v) che 
restituisce in output un array ordine dove ordine[v] è il numero 
d'ordine con cui il nodo v e' stato visitato nella visita in profondita'
-----------------------------------------------------------------
DFS_ORDINE(g,u)  // versione che ritorna l'array ORDER
	// creo un array ORDER di interi con tante posizioni
	// quanti sono i nodi di g (dim. di g.A)

    for i=0 to color.length-1
    	color[i] = 0     // smarco tutti i nodi
    	ORDER[i] = -1

    // creo un array di interi con una sola cella
    nodi_visitati[0] = 0;

    DFS_visit_order(g,u,color,ORDER,nodi_visitati)
    return ORDER
-----------------------------------------------------------------
DFS_visit_ORDINE(g,u,color,ORDER,nodi_visitati) 
	color[u] = 1
	nodi_visitati[0]++
	ORDER[u] = nodi_visitati[0]
	x = g.A[u]
	while x != NULL
		if ( color[x.key] == 0 )  // nodo non visitato
			PARENT[x.key] = u
			DFS_visit_ORDINE(g,x.key,color,ORDER,nodi_visitati)
		x = x.next
=================================================================