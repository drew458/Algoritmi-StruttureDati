#include <stdio.h>
#include <strutture.h>

/*-------------------------------------------- TESTO ESAME ------------------------------------------------------------------

*    Scrivi in linguaggio C il codice della funzione
*        int verifica(nodo_albero* a, grafo* g)
*    che accetti in input un puntatore a alla radice di un albero binario di interi e un puntatore g ad grafo non
*    orientato rappresentato tramite oggetti e riferimenti. La funzione restituisce 1 se il numero di nodi
*    dell’albero a che hanno un solo figlio sono tanti quanti sono i nodi della componente più piccola del grafo
*    g, altrimenti la funzione restituisce 0. Se uno (o entrambi) tra grafo e albero è vuoto (cioè uguali a NULL) la
*    funzione ritorna 0.
*/


/* Funzione che esegue una visita in profondità del grafo (Depth-First Search) e conta il numero dei nodi della componente */
int DFS_size(nodo* n){
    int output;
    n->color=1;
    elem_archi* ea = n->archi;
    while(ea != NULL){
        nodo* altro_nodo=ea->info->from;
        if(altro_nodo == n)
            altro_nodo = ea->info->to;
        if(altro_nodo->color == 0)
            output = output + DFS_size(altro_nodo);
        ea = ea->next;
    }
}


/* Funzione che conta il numero dei nodi della componente connessa più piccola del grafo */
int min_nodi_comp (grafo_oggetti* g) {
    if(g==NULL) return 0;           //ridondante (la funzione principale esegue la stessa verifica)
    elem_nodi* en = g->nodi;
    while(en != NULL) {
        en->info->color == 0;
        en = en->next;
    }
    en = g->nodi;
    int smallest = DFS_size(en->info);
    while(en != NULL) {
        if(en->info->color == 0) {
            int output = output + DFS_size(en->info);
            if(output<smallest)
                smallest = output;
        }
        en = en->next;
    }
    return smallest;
}


/* Funzione che conta i nodi che hanno un figlio unico in un albero */
int nodi_figlio_unico(nodo_albero* a){
    if(a==NULL) return 0;
    if(a->left==NULL || a->right==NULL) return 1;
    int output = nodi_figlio_unico(a->left) + nodi_figlio_unico(a->right);
}


/* La funzione restituisce 1 se il numero di nodi
   dell’albero a che hanno un solo figlio sono tanti quanti sono i nodi della componente più piccola del grafo
   g, altrimenti la funzione restituisce 0. Se uno (o entrambi) tra grafo e albero è vuoto (cioè uguali a NULL) la
   funzione ritorna 0. */
int verifica(nodo_albero* a, grafo_oggetti* g){
    if(a==NULL || g==NULL) return 0;
    if(a==NULL && g==NULL) return 0;        //Questo è ridondante, perche l'OR comprende anche il caso in cui sono entrambi nulli */
    return (nodi_figlio_unico(a)==min_nodi_comp(g));
}