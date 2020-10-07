BFS(g,v)
for i=0 to g.A.lenght-1
	color[i]=0

q=QUEQUE_EMPTY()		//coda vuota
color[v]=1				//marco(coloro) il primo elemento
ENQUEQUE[q,v]			//metto in coda il primo elemento

while not QUEQUE_VOID(q)		//finchè la coda non è vuota
	u=DEQUEQUE(q)				//estraggo indice
	x=g.A[u]					//imposto l'adiacente di u
	while x != NULL				//finchè ci sono adiacenti
		k=x.info				//k indice del nodo adiacente
		if(color==0)
			color[k]==1
			ENQUEQUE(q,k)
		x=x.next

------------------------------------------------------------------------------------------------------------------

/* Esercizio 1: Scrivi lo pseudocodice della procedura BFS(g,v) nel caso in cui il grafo non diretto g
 * sia rappresentato tramite una matrice di adiacenza */
 
bfsMatrix(g,v)
for i=0 to g.A.lenght-1 
	color[i]=0
q=QUEQUE_EMPTY()
color[v]=1
ENQUEQUE[q,v]
while not QUEQUE_VOID(q)
	u=DEQUEQUE(q)
	for i = 0 to g.A.length-1 
		if ( (g.A[u][i] == 1) &&  // se i e' un mio vicino
			  color[i] == 0 ))    // e se non e' marcato
			color[i] = 1
			ENQUEUE(q,i)

//////////////////////*********************\\\\\\\\\\\\\\\\\\\\\\\\\\\

/* Esercizio 5: Scrivi lo pseudocodice della procedura BFS_order(g,v) 
che restituisce in output un array order dove order[n] è il numero 
d'ordine con cui il nodo n è stato visitato. */
------------------------------------------------------------------
BFS_ORDER(g,v)

	/* definisco un array color con A.length interi */
	for i=0 to g.A.length-1
		color[i] = 0		/* inizializzo color */
		order[i] = -1		/* -1 rappresenta il fatto che non ho raggiunto il nodo */

	numero_ordine = 1;
	q = QUEUE_EMPTY()				/* creo una coda vuota */
	color[v] = 1					/* nodo v visitato */
	order[v] = numero_ordine		/* nodo v visitato per primo */
	numero_ordine++;
	ENQUEUE(q,v)        

	while( ! IS_EMPTY(q) ) 
		u = DEQUEUE(q)
		for i = 0 to g.A.length-1 
			if ( (g.A[u][i] == 1) &&		// se i e' un mio vicino
				color[i] == 0 ))			// e se non e' marcato
				color[i] = 1
				order[i] = numero_ordine;
				numero_ordine++;
				ENQUEUE(q,i)
	return order;
=================================================================


Esercizio 6: Scrivi lo pseudocodice della procedura DISTANZE(g,v) che restituisce un array di interi che rappresentano le 
distanze di tutti i nodi dal nodo v. I nodi non raggiunti devono avere distanza -1
------------------------------------------------------------------
DISTANZE(g,v)

    /* definisco un array color con A.length interi */
	for i=0 to g.A.length-1
		color[i] = 0   /* inizializzo color */
		distanze[i] = -1  /* -1 rappresenta il fatto che non ho 
		                     raggiunto il nodo */

	q = QUEUE_EMPTY()         /* creo una coda vuota */
	color[v] = 1              /* nodo v visitato */
	distanze[v] = 0           /* la distanza di v da v e' zero */
	ENQUEUE(q,v)        

	while( ! IS_EMPTY(q) ) 
		u = DEQUEUE(q)
		for i = 0 to g.A.length-1 
			if ( (g.A[u][i] == 1) &&  // se i e' un mio vicino
                  color[i] == 0 ))    // e se non e' marcato
                color[i] = 1
                distanze[i] = distanze[u]+1;
                ENQUEUE(q,i)
    return distanze;
=================================================================