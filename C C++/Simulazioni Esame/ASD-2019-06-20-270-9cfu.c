#include <stdio.h>
#include <strutture.h>

/******************************************** TESTO ESAME *************************************************************
 * 
 * Scrivi in linguaggio C il codice della funzione
        int verifica(int h, nodo_albero* a, grafo* g)
 * che accetti in input un intero h, un puntatore a alla radice di un albero binario di interi e un puntatore g ad
 * grafo non orientato rappresentato tramite oggetti e riferimenti. La funzione restituisce 1 se il numero di  
 * nodi dell’albero a che sono a profondità h sono tanti quanti sono i nodi della componente più grande del
 * grafo g, altrimenti la funzione restituisce 0. Se uno (o entrambi) tra grafo e albero è vuoto (cioè uguali a
 * NULL) la funzione ritorna 0. */

/* Funzione che esegue una visita in profondità (Depth-First Search) e conta i nodi della componente connessa nella
 * variabile size */
int DFS_size (nodo* n) {
    int size;
    n->color = 1;                   //Visito il nodo
    elem_archi* ea = n->archi;      //costruisco una lista di archi con gli archi adiacenti al nodo considerato
    while (ea != NULL)              
    {
        nodo* altro_nodo = ea->info->from;         //considero il nodo di origine dell'arco
        if(altro_nodo == n)                        //se il nodo di origine è il proprio nodo considerato
            altro_nodo = ea->info->to;             //...considera il nodo opposto
        if(altro_nodo->color == 0)                 //se il nodo non è stato visitato...
            size = size + DFS_size(altro_nodo);    //...visitalo
        ea=ea->next;
    }
    return size;
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


/* Funzione che calcola la profondità di un albero */
int prof_albero(nodo_albero* a){
    if(a==NULL) return -1;
    int l=prof_albero(a->left);
    int r=prof_albero(a->right);
    if(l>r)
        return l+1;
    return r+1;
}


/* Funzione che calcola il numero di nodi a profondità h */
int nodi_prof(nodo_albero* a, int h) {
    if(a==NULL) return 0;
    if(h==0) return 1;
    int numero = nodi_prof(a->left,h-1) + nodi_prof(a->right, h-1);
    return numero;
}


/* La funzione restituisce 1 se il numero di  
 * nodi dell’albero a che sono a profondità h sono tanti quanti sono i nodi della componente più grande del
 * grafo g, altrimenti la funzione restituisce 0. Se uno (o entrambi) tra grafo e albero è vuoto (cioè uguali a
 * NULL) la funzione ritorna 0. */
int verifica(int h, nodo_albero* a, grafo_oggetti* g) {
    if(a==NULL && g==NULL) return 1;
    if(a==NULL || g==NULL) return 0;
    return (nodi_comp_conn_max(g)==nodi_prof(a,h));
}