#include <stdio.h>
#include <strutture.h>

/*--------------------------------------------- TESTO ESAME ------------------------------------------------------------
* Scrivi in linguaggio C il codice della funzione
*   int verifica_figli_componente(grafo* g, nodo_albero* a)
* che accetti in input un puntatore ad grafo non orientato g rappresentato tramite oggetti e un puntatore a
* alla radice di un albero di grado arbitrario di interi rapresentato tramite la struttura figlio‐sinistro
* (left_child) e fratello destro (right_sibling). La funzione restituisce 1 se esiste un nodo
* dell’albero a che ha tanti figli quanti sono i nodi della componente connessa più grande del grafo g,
* altrimenti la funzione restituisce 0. Se grafo e albero sono entrambi vuoti (cioè uguali a NULL) la funzione
* ritorna true. Se uno è vuoto e uno no, allora ritorna false. 
*/

/* funzione che ritorna il nodo raggiunto dall'arco "a" partendo dal nodo "n" */
nodo* nodo_opposto(nodo* n, arco* a) {
	nodo* output = a->from;
	if (output == n) 
		output = a->to;
	return output;
}


/* DFS che conta il numero dei nodi attraversati */
void DFS(nodo* n, int* numero_nodi) {
	n->color = 1;   // marco il nodo come visitato
	(*numero_nodi)++;

	elem_archi* la = n->archi;
	while( la != NULL ) {
		nodo* altro_nodo = nodo_opposto(n,la->info);
		if( altro_nodo->color == 0 ){
			DFS(altro_nodo,numero_nodi);
		}
		la = la->next;
	}
}


/* funzione che calcola la dimensione della massima componente connessa del grafo */
int massima_componente(grafo_oggetti* g) {

	elem_nodi* ln = g->nodi;
	while( ln != NULL ) {
		ln->info->color = 0;  // smarco i nodi
		ln = ln->next;
	}

	int massimo = 0;   // dimensione della componente più grande
	                   // visitata fino ad adesso
	ln = g->nodi;
	while( ln != NULL ) {
		if( ln->info->color == 0 ) {  // ho trovato un nodo non visitato
			int nodi_della_visita = 0;
			DFS(ln->info,&nodi_della_visita);	
			if( nodi_della_visita > massimo) {
				massimo = nodi_della_visita;
			}
		}
		ln = ln->next;
	} 
	return massimo;
}


/* funzione che ritorna 1 se esiste un nodo nell'albero
   di grado arbitrario "a" passato come parametro che abbia esattamente "max" figli */
int esiste_genitore_con_figli(nodo_albero2* a, int max) {

	if( a == NULL) return 0;

    /* verifica se sono un nodo con max figli */

	int contatore = 0;
	nodo_albero2* figlio = a->left_child;
	while( figlio != NULL) {
		contatore++;
		figlio = figlio->right_sibling;
	}
	if( contatore == max) 
		return 1;

	return esiste_genitore_con_figli(a->left_child, max) ||
	       esiste_genitore_con_figli(a->right_sibling, max);
}


/* funzione richiesta */
int verifica_figli_componente(grafo_oggetti* g, nodo_albero2* a) {
	
	if( (g == NULL) && (a == NULL) ) 
		return 1;
	if( (g == NULL) || (a == NULL) ) 
		return 0;

	int max = massima_componente(g);

	return esiste_genitore_con_figli(a,max);
} 