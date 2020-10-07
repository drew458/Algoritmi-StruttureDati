#include <stdio.h>
#include <strutture.h>

/*---------------------------------------- TESTO ESAME ---------------------------------------------------

* Scrivi in linguaggio C il codice della funzione
    int verifica(int h, nodo_albero* a, grafo* g)
* che accetti in input un intero h, un puntatore a alla radice di un albero binario di interi 
* e un puntatore g ad grafo non orientato rappresentato tramite oggetti e riferimenti. 
* La funzione restituisce 1 se il numero di nodi dell’albero a che sono radici di un sottoalbero
* di profondità h sono tanti quanti sono i nodi della componente più piccola del grafo g, altrimenti 
* la funzione restituisce 0. Se grafo e albero sono entrambi vuoti (cioè uguali a NULL) la funzione ritorna 1. 
* Se uno è vuoto e uno no, allora ritorna 0. 
* Se non ci sono sottoalberi di profondità h in a (cioè se il loro numero è 0) la funzione ritorna 0. */

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

/* Ritorna il nodo incidente sull'arco "e" diverso da "n" */
nodo* nodo_opposto(arco* e, nodo* n) {
    if(e->from == n) return e->to;
    else e->from;
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


/* Calcola la profondità di un albero */
int prof_albero(nodo_albero* a) {
    if(a==NULL) return -1;
    int l=prof_albero(a->left);
    int r=prof_albero(a->right);
    if(l>r) return l+1;
    else return r+1;
}


/* Ritorna il numero di sottoalberi con una profondità h in un albero */
int sottoalberi_prof(nodo_albero* a, int h) {
    int numero;
    if(a==NULL) return 0;
    numero = (sottoalberi_prof(a->left, h) + sottoalberi_prof(a->right, h));
    if(prof_albero(a)==h)
        numero++;
    return numero; 
}

/* La funzione restituisce 1 se il numero di nodi dell’albero a che sono radici di un sottoalbero
*  di profondità h sono tanti quanti sono i nodi della componente più piccola del grafo g, altrimenti 
*  la funzione restituisce 0. Se grafo e albero sono entrambi vuoti (cioè uguali a NULL) la funzione ritorna 1. 
*  Se uno è vuoto e uno no, allora ritorna 0. 
*  Se non ci sono sottoalberi di profondità h in a (cioè se il loro numero è 0) la funzione ritorna 0. */
int verifica (int h, nodo_albero* a, grafo_oggetti* g) {
    if(a==NULL && g==NULL) return 1;
    if(a==NULL || g==NULL) return 0;
    if(dim_comp_min(g) == sottoalberi_prof(a,h)) return 1;
    else return 0;
}