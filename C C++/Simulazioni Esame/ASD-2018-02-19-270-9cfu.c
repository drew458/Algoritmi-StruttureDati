#include <stdio.h>
#include <stdlib.h>
#include <strutture.h>

/*----------------------------------------------- TESTO ESAME -------------------------------------------------------

 * Scrivi in linguaggio C il codice della funzione
    int verifica(grafo_oggetti* g, nodo_albero* a)
 * che accetti in input un puntatore ad grafo non orientato g rappresentato tramite oggetti e un puntatore a
 * alla radice di un albero binario di interi. La funzione restituisce 1 se il numero di nodi della componente
 * connessa più grande (cioè con più nodi) del grafo è uguale alla profondità del nodo con indice (campo info)
 * più alto dell’albero, altrimenti restituisce 0.
 */


/* visita DFS del grafo rappresentato mediante oggetti e
 * riferimenti e marcatura dei nodi raggiunti con il valore passato. */
void DFS(nodo* n, int mark) {
    n->color = mark;    // coloro il nodo come visitato
    elem_archi* ea = n->archi;
    while( ea != NULL) {
        nodo* altro_nodo = ea->info->from;
        if( altro_nodo == n) {
            altro_nodo = ea->info->to;
        }
        if( altro_nodo->color == 0) {   // se non e' gia' visitato...
            DFS(altro_nodo, mark);      // ... lo visito e marco
        }
        ea = ea->next;
    }
}


/* ritorna il numero di nodi della componente specificata */
int nodi_componente(grafo_oggetti* g, int comp){
    int cont = 0; // questo sarà l’output
    elem_nodi* en = g->nodi; // scorro la lista dei nodi
    while (en != NULL) {
        if(en->info->color == comp) {
            cont++;
        }
        en = en->next;
    }
    return cont;
}


/* ritorna il massimo tra due interi */
int massimo(int a, int b) {
    if (a > b) return a;
    return b;
}


/* ritorna il massimo valore contenuto in un nodo nell’albero */
int massimo_albero(nodo_albero* a) {
    if ( a == NULL ) return -1;
    int left = massimo_albero(a->left);
    int right = massimo_albero(a->right);
    return massimo(a->info,massimo(left, right));
}


/* ritorna la profondità del nodo che contiene il valore intero id */
int profondita_nodo(nodo_albero* a, int id) {
    if (a == NULL) return -1;
    if (a->info == id) return 0;
    int left = profondita_nodo(a->left, id);
    int right = profondita_nodo(a->right, id);
    int max = massimo(left, right);
    if (max == -1) return -1; // non lo abbiamo trovato
    else return max+1;
}


/* funzione richiesta dal compito */
int verifica(grafo_oggetti* g, nodo_albero* a) {
    elem_nodi* en = g->nodi;
    while (en != NULL) {
        en->info->color = 0; // marco tutti i nodi con 0
        en = en->next;
    }
    int comp = 0;
    en = g->nodi;
    while (en != NULL) {
        if(en->info->color == 0) { // trovato nodo non visitato
            comp++;
            DFS(en, comp); // visito e marco tutto con comp
        }
        en = en->next;
    }
    int nodi_comp_max = 0;
    int j;
    for (j=1; j <= comp; j++) {
        nodi_comp_max = massimo(nodi_comp_max, nodi_componente(g, j));
    }
    int prof_nodo = profondita_nodo(a, massimo_albero(a));
    return prof_nodo == nodi_comp_max;
}