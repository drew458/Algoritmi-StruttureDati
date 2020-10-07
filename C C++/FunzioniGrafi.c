#include <stdio.h>
#include <stdlib.h>
#include <strutture.h>

/* -----------------------File con tutte le funzioni incontrate negi esami passati sui grafi----------------------- */

/* DFS (Depth-First Search) di un grafo rappresentato tramite oggetti */
void DFS(nodo* n) {
    n->color = 0;
    elem_archi* la = n->archi;
    while(la != NULL) {
        nodo* altro_nodo = la->info->from;
        if(altro_nodo == n)
            altro_nodo = la->info->to;
        if(altro_nodo->color == 0)
            DFS(altro_nodo);
        la = la->next;
    }
}


/* visita DFS del grafo rappresentato mediante oggetti e
 * riferimenti e marcatura dei nodi raggiunti con il valore passato. */
void DFS_mark(nodo* n, int mark) {
    n->color = mark;    // coloro il nodo come visitato
    elem_archi* ea = n->archi;
    while( ea != NULL) {
        nodo* altro_nodo = ea->info->from;
        if( altro_nodo == n) {
            altro_nodo = ea->info->to;
        }
        if( altro_nodo->color == 0) {   // se non e' gia' visitato...
            DFS_mark(altro_nodo, mark);      // ... lo visito e marco
        }
        ea = ea->next;
    }
}


/* Visita in profondità di un grafo (Depth-First Search) rappresentato tramite oggetti riportando il 
*  numero dei nodi della componente connessa visitata */ 
int DFS_size(nodo* n){
    n->color = 1;                     //nodo visitato
    int output = 1;                   // conto il nodo corrente
    elem_archi* ea = n->archi;        //lista di archi adiacenti al nodo n
    while( ea != NULL ) {             //finchè non ci sono più archi...
        nodo* altro_nodo = nodo_opposto(ea->info, n);       /* considero il nodo opposto(l'altro 
                                                               estremo dell'arco rispetto ad n) */
        if( altro_nodo->color == 0 )                        //se non è ancora stato visitato...
            output = output + DFS_size(altro_nodo);         /* lo visito e lo aggiungo al numero dei nodi 
                                                               della componente connessa */
        ea = ea->next;
    }
    return output;                                          //numero dei nodi delle componenti connesse
}


/* DFS che conta il numero dei nodi attraversati tramite un puntatore*/
void DFS_punt(nodo* n, int* numero_nodi) {
	n->color = 1;   // marco il nodo come visitato
	(*numero_nodi)++;

	elem_archi* la = n->archi;
	while( la != NULL ) {
		nodo* altro_nodo = nodo_opposto(n,la->info);
		if( altro_nodo->color == 0 ){
			DFS_punt(altro_nodo,numero_nodi);
		}
		la = la->next;
	}
}


/* funzione che conta i nodi di una componente connessa passata come parametro */
int conta_nodi(grafo_oggetti* g, int comp) {
    int numero_nodi=0;
    elem_nodi* en = g->nodi;                //creo una lista di nodi che contiene i nodi del grafo
    while(en != NULL){
        if(en->info->color==comp)           //se la marcatura del nodo è uguale al numero della componente connessa...
            numero_nodi++;                  
        en=en->next;
    }
    return numero_nodi;
}


/* Funzione che calcola la componente connessa che ha più nodi in un grafo */
int nodi_comp_conn_max(grafo_oggetti* g) {
    elem_nodi* en = g->nodi;    //lista di nodi
    while(en != NULL) {
        en->info->color = 0;    //coloro tutti i nodi della lista con 0
        en = en->next;
    }
    en = g->nodi;
    int biggest = DFS_size(en);
    while(en != NULL) {
        if(en->info->color==0) {
            int output = DFS_size(en);
            if(output>biggest)
                biggest = output;
        }
        en=en->next;
    }
    return biggest;
}


/* funzione che calcola la dimensione della massima componente connessa del grafo (versione con puntatore)*/
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
			DFS_punt(ln->info,&nodi_della_visita);	
			if( nodi_della_visita > massimo) {
				massimo = nodi_della_visita;
			}
		}
		ln = ln->next;
	} 
	return massimo;
}


/* Funzione che calcola la dimensione della componente connessa più piccola del grafo in input */
int dim_comp_min(grafo_oggetti* n) {
    
    /* Passo 1) coloro a 0 tutti i nodi del grafo */
    elem_nodi* en = n->nodi;
    while (en != NULL) {
        en->info->color = 0;
        en = en->next;
    }

    /*Passo 2) eseguo una serie di visite memorizzando la componente connessa più piccola incontrata */
    int size;
    int smallest = DFS_size(n->nodi->info);

    en=n->nodi;
    while(en != NULL) {
        if(en->info->color == 0){               //trovata componente da visitare...
            int size=DFS_size(en->info);        //...la visito
            if(size<smallest)                   /* se la componente connessa visitata ha 
                                                   meno nodi dellapiù piccola trovata fino a ora... */
                smallest=size;                  // la imposto come minima
        }
        en = en->next;
    }
    return smallest;     
} 


/* funzione che ritorna il nodo raggiunto dall'arco "a" partendo dal nodo "n" */
nodo* nodo_opposto(nodo* n, arco* a) {
	nodo* output = a->from;
	if (output == n) 
		output = a->to;
	return output;
}


/* aggiunge un arco al grafo rappresentato tramite liste di adiacenza */
void aggiungi_arco(grafo_array* g, int u, int v) {
    elem_int* ei = (elem_int*)malloc(sizeof(elem_int));
    ei->info = v;
    ei->next = g->A[u];
    ei->prev = NULL;        //lo aggiungerò in testa alla lista
    
    if(g->A[u] != NULL) {   //era già presente un elemento nella lista 
        g->A[u]->prev = ei;
    }
    g->A[u] = ei;

    /* l’arco opposto viene aggiunto quando viene trovato
       a partire dal nodo v nel grafo_oggetti g */
}