#include <stdio.h>
#include <stdlib.h>
#include <strutture.h>

/* ----------------------------------------------- TESTO ESAME ------------------------------------------------------------
* Scrivi in linguaggio C il codice della funzione
*   int verifica_livello_componente(grafo* g, nodo_albero* a)
* che accetti in input un puntatore ad grafo non orientato g rappresentato tramite oggetti e riferimenti e un
* puntatore a alla radice di un albero binario di interi. La funzione restituisce 1 se esiste un livello dell’albero
* a che ha tanti nodi quanti sono i nodi di una componente connessa del grafo g, altrimenti la funzione
* restituisce 0. Se grafo e albero sono entrambi vuoti (cioè uguali a NULL) la funzione ritorna true. Se uno è
* vuoto e uno no, allora ritorna false. 
*/

/* funzione che ritorna il nodo raggiunto dall'arco "a" partendo dal nodo "n" */
nodo* nodo_opposto(nodo* n, arco* a) {
	nodo* output = a->from;
	if (output == n) 
		output = a->to;
	return output;
}

/* Funzione chre restituisce la profondità di un albero */
int profondita_albero(nodo_albero* a) {
	if (a == NULL) return -1;

	int l = profondita_albero(a->left);
	int r = profondita_albero(a->right);
	if ( l > r )
		return l+1;
 	return r+1;
}


/* Conta i nodi di tutti i livelli dell'albero */
void conta_nodi_livelli(nodo_albero* a, int* contatore, int livello) {
	if ( a == NULL ) return;

	contatore[livello]++;
	conta_nodi_livelli(a->left,  contatore, livello+1);
	conta_nodi_livelli(a->right, contatore, livello+1);
}


/* DFS(Depth-First Search) con marcature dei nodi tramite un marcatore */
void DFS(nodo* n, int marcatore) {
	n->color = marcatore;
	elem_archi* la = n->archi;
	while( la != NULL ) {
		nodo* altro_nodo = nodo_opposto(n,la->info);
		if (altro_nodo->color == 0) {
			DFS(altro_nodo,marcatore);
		}
		la = la->next;
	}
}


/* La funzione restituisce 1 se esiste un livello dell’albero
*  a che ha tanti nodi quanti sono i nodi di una componente connessa del grafo g, altrimenti la funzione
*  restituisce 0. Se grafo e albero sono entrambi vuoti (cioè uguali a NULL) la funzione ritorna true. Se uno è
*  vuoto e uno no, allora ritorna false. */
int verifica_livelli_componente(grafo_oggetti* g, nodo_albero* a) {
	int altezza = profondita_albero(a);

	int* contatore_prof = (int*)calloc(altezza+1,sizeof(int));			//ogni livello dell'albero è un indice dell'array
																		//contiene il numero di nodi ad ogni livello

	conta_nodi_livelli(a,contatore_prof,0);  // 0 perché lanciato su radice

	elem_nodi* ln = g->nodi;
	while( ln != NULL) {
		ln->info->color = 0;   // smarco tutti i nodi
		ln = ln->next;
	}

	/* ora cerco tutte le componenti connesse del grafo */

	int numero_cc = 0;					//numero delle componenti connesse
	ln = g->nodi;
	while( ln != NULL ) {
		if( ln->info->color == 0 ) {    // trovato un nodo non visitato
		 	numero_cc++;				//aumento il numero delle componenti connesse del nodo
		 	DFS(ln->info, numero_cc);	//lo visito e lo marco con il numero delle componenti connesse
		}
		ln = ln->next; 
	}

    // ora tutti i nodi sono marcati con colori che vanno da 1 a numero_cc

    int* dim_componenti = (int*)calloc(numero_cc+1,sizeof(int));   // non utilizzo la prima cella

    ln = g->nodi;
    while( ln != NULL ) {
    	dim_componenti[ln->info->color]++;		//array che contiene il numero di nodi di ogni componente connessa
    	ln = ln->next;
    }


    int l, c;

    for( l = 0; l <= altezza ; l++ ) {
    	printf("al livello %d ho %d nodi\n",l,contatore_prof[l]);
    }
   	for( c = 1; c <= numero_cc ; c++) {
   		printf("la componente %d ha %d nodi\n",c,dim_componenti[c]);	
   	}


    for( l = 0; l <= altezza ; l++ ) {
    	for( c = 1; c <= numero_cc ; c++) {
    		if( contatore_prof[l] == dim_componenti[c])
    			return 1;
    	}
    }
    return 0;

}