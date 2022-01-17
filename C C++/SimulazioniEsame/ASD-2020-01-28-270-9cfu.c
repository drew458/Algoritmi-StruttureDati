#include <stdio.h>
#include <stdlib.h>
#include <strutture.h>

/*---------------------------------------------- TESTO ESAME --------------------------------------------------
* Scrivi in linguaggio C il codice della funzione
*   int verifica(nodo_albero* a, grafo* g)
* che accetti in input un puntatore a alla radice di un albero di grado arbitrario di interi e un puntatore g ad
* grafo non orientato rappresentato tramite oggetti e riferimenti. La funzione restituisce 1 se esiste nodo
* dell’albero che ha tanti figli quanti sono i nodi di una componente connessa del grafo g, altrimenti la
* funzione restituisce 0. Se uno (o entrambi) tra grafo e albero è vuoto (cioè uguale a NULL) la funzione
* ritorna 0.
*/

/* DFS (Depth-First Search) in un grafo
*  numero_nodi_visita è un puntatore alla variabile che conta il numero nei nodi visitati dalla DFS */
void DFS(nodo* n, int marcatore) {
    n->color = marcatore;
    elem_archi* la = n->archi;
    while(la != NULL) {
        nodo* altro_nodo = nodo_opposto(n,la->info);
        if(altro_nodo->color == 0)
            DFS(altro_nodo,marcatore);
        la=la->next;
    }
} 

/* Funzione che restituisce il nodo opposto al nodo n sull'arco a */
nodo* nodo_opposto(nodo* n,arco* a){
    nodo* m = a->from;
    if(m==n)
        return m=a->to;
    return m;
}


/* Funzione che conta i nodi di una componente connessa passata come parametro */
int nodi_comp(grafo_oggetti* g, int comp) {
    elem_nodi* ln = g->nodi;
    int output=0;
    while(ln != NULL) {
        if(ln->info->color==comp)
            output++;
        ln = ln->next;
    }
    return output;
}


/* Funzione che calcola il numero di figli di un nodo in un albero con struttura figlio sinitro - fratello destro */
int numero_figli(nodo_albero2* a) {
    if(a==NULL) return 0;
    nodo_albero2* b = a->left_child;
    int numfigli;
    while( b != NULL) {
        numfigli++;
        b = b->right_sibling;
    }
    return numfigli;
}


int verifica_sperimentale(grafo_oggetti* g, int numero_cc, nodo_albero2*a) {
    if(a==NULL) return 0;
    for(int i=0; i<numero_cc; i++) {
        if(numero_figli(a)==nodi_comp(g,i)) return 1;  
    }
    return verifica_sperimentale(g, numero_cc, a->left_child) || verifica_sperimentale(g, numero_cc, a->right_sibling);
}


/* La funzione restituisce 1 se esiste nodo
*  dell’albero che ha tanti figli quanti sono i nodi di una componente connessa del grafo g, altrimenti la
*  funzione restituisce 0. Se uno (o entrambi) tra grafo e albero è vuoto (cioè uguale a NULL) la funzione
*  ritorna 0. */
int verifica(nodo_albero2* a, grafo_oggetti* g) {
    if(a==NULL || g==NULL) return 0;
    elem_nodi* ln = g->nodi;
    while(ln != NULL){
        ln->info->color = 0;        //Smarco tutti i nodi
        ln=ln->next;
    }

    //Ora cerco tutte le componenti connesse del grafo
    
    int numero_cc=0;
    while(ln != NULL) {
        if(ln->info->color==0){
            numero_cc++;
            DFS(ln->info->color, numero_cc);
        }
        ln=ln->next;
    }

    return verifica_sperimentale(g, numero_cc, a);
}