#include <stdio.h>
#include <stdlib.h>
#include <htable.h>

/*--------------------------------------- STRUTTURE ---------------------------------------------------------- */

typedef struct nodo_struct {
    elem_nodi* pos;     //posizione nodo
    elem_archi* archi;
    int color;
} nodo;

typedef struct elem_lista_nodi {
    struct elem_lista_nodi* prev;
    struct elem_lista_nodi* next;
    nodo* info;
} elem_nodi;        //elemento di una lista di nodi

typedef struct arco_struct {
    elem_archi* pos;        //posizione arco
    nodo* from;
    nodo* to;
    elem_archi* frompos;    //posizione arco
    elem_archi* topos;      //posizione arco
} arco;

typedef struct elem_lista_archi {
    struct elem_lista_archi* prev;
    struct elem_lista_archi* next;
    arco* info;
} elem_archi;   //elemento di una lista di archi

typedef struct {
    int numero_nodi;
    int numero_archi;
    elem_archi* archi;
    elem_nodi* nodi;
} grafo_oggetti;

typedef struct elem_lista_int {
    struct elem_lista_int* prev;
    struct elem_lista_int* next;
    int info;
} elem_int;     //elemento di una lista di interi

typedef struct {
    int numero_nodi;
    elem_int** A;  //liste di adiacenza
} grafo_array;     //struttura di un grafo rappresentato tramite array di liste doppiamente concatenate


/*------------------------------------------------ TESTO ESAME ------------------------------------------------------------

/* Scrivi in linguaggio C il codice della funzione
 *      grafo_array* componente_connessa(grafo_oggetti* g, nodo* n)
 * che accetti in input un puntatore ad grafo non orientato g rappresentato tramite oggetti ed il riferimento
 * ad un nodo n e produca in output il riferimento ad un grafo non orientato rappresentato tramite un array
 * di liste di adiacenza che contiene esclusivamente i nodi e gli archi della componente connessa che contiene
 * il nodo n. 
 */

/* DFS (Depth-First Search) */
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


/* funzione richiesta dal compito */
grafo_array* componente_connessa(grafo_oggetti* g, nodo* n) {
    elem_nodi* en = g->nodi;
    while(en != NULL) {
        en->info->color = 0;        //smarco tutti i nodi
    }
    DFS(n);         //visito la componente di n e marco tutti i suoi nodi con 1

    /* popolo una tabella hash contenente tutte le corrispondenze tra i nodi del grafo_oggetti e quelli del 
     * grafo_array. Cont è un contatore dei nodi. Il suo valore viene via via usato come intero identificatore del nodo
     * del grafo_array. */

    htable* htab = crea_tabella();
    int cont=0;
    en = g->nodi;
    while( en != NULL) {
        if(en->info->color == 1) {      //il nodo è stato visitato
            cont++;     //conto questo nodo
            aggiungi_elemento(htab, en->info, cont);
            //userò cont come identificatore di questo nodo
        }
    }

    //creo il grafo di output

    grafo_array* ga = (grafo_array*)malloc(sizeof(grafo_array));
    ga->numero_nodi=cont;
    ga->A = (elem_int**)calloc(ga->numero_nodi, sizeof(elem_int*));

    //ora aggiungo gli archi al grafo di output

    en=g->nodi; 
    while(en!=NULL) {
        if(en->info->color == 1) {      //en->info è stato visitato
            /* scorro la lista degli archi del nodo en->info e aggiungo gli archi corrispondenti al grafo di output */
            elem_archi* ea = en->info->archi;
            while(ea != NULL) {
                nodo* altro_nodo = en->info->from;
                if(altro_nodo == en->info)
                    altro_nodo=en->info->to;
                aggiungi_arco(ga,trova_valore(htab, en->info), trova_valore(htab,altro_nodo));
                ea=ea->next;
            }
        }
        en=en->next;
    }
    distruggi_tabella(htab);
    return ga;
}