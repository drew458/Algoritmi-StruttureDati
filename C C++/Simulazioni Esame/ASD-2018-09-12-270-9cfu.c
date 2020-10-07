#include <stdio.h>
#include <strutture.h>


/*--------------------------------------- TESTO ESAME ---------------------------------------------------------
    
    Scrivi in linguaggio C il codice della funzione
        int foglie_comp(grafo_oggetti* g, nodo_albero* a)
    che accetti in input un puntatore ad grafo non orientato g rappresentato tramite oggetti e un puntatore a
    alla radice di un albero di grado arbitrario di interi rapresentato tramite la struttura figlio‐sinistro
    (left_child) e fratello destro (right_sibling). La funzione restituisce 1 se almeno una componente
    connessa del grafo g ha tanti nodi quante le foglie dell’albero a, altrimenti la funzione restituisce 0. 
    Se grafo e albero sono entrambi vuoti (cioè uguali a NULL) la funzione ritorna true. 
    Se uno è vuoto e uno no,allora ritorna false. 


/* Visita DFS (Depth-First Search) del grafo rappresentato tramite oggetti e marcatura dei nodi visitati con
*  il numero della componente attuale.
*  comp = numero della componente connessa attuale */
void DFS(nodo* n, int comp) {
    n->color=comp;                     //coloro il nodo come visitato
    elem_archi* ea = n->archi;         /* creo una nuova lista di archi e la riempio 
    									  con tutti gli archi adiancenti al nodo n */
    while (ea != NULL)                 //finchè non ci sono più archi adiancenti...
    {
        nodo* altro_nodo= ea->info->from;       /* creo un nodo che punta al nodo da cui parte 
                                                   l'arco adiacente al nodo n */
        if(altro_nodo==n)                       /* se il nodo creato è proprio uguale al nodo n... */
            altro_nodo = ea->info->to;          /* punta al nodo di destinazione dell'arco 
                                                   adiancente al nodo n */
        if(altro_nodo->color == 0)              /* se il nodo creato non è stato visitato... */
            DFS(altro_nodo, comp);              /* ...lo visito e lo marco */
        ea=ea->next;
    }
}


/* funzione che conta le foglie in un albero con la struttura figlio sinistro - fratello destro */
int conta_foglie(nodo_albero2* a) {
    if(a==NULL) return 0;
    if(a->left_child == NULL)               //trovata una foglia
        return 1 + conta_foglie(a->right_sibling);
    return conta_foglie(a->left_child) + conta_foglie(a->right_sibling);
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


/* La funzione restituisce 1 se almeno una componente
*  connessa del grafo g ha tanti nodi quante le foglie dell’albero a, altrimenti la funzione restituisce 0. 
*  Se grafo e albero sono entrambi vuoti (cioè uguali a NULL) la funzione ritorna true. 
*  Se uno è vuoto e uno no,allora ritorna false. */
int foglie_comp(grafo_oggetti* g, nodo_albero2* a) {
    if(a==NULL && g==NULL) return 1;
    if(a==NULL || g==NULL) return 0;

    elem_nodi* en = g->nodi;            //creo una lista di nodi e ci inserisco tutti i nodi del grafo
    while(en != NULL){
        en->info->color=0;              //smarco tutti i nodi
        en=en->next;
    }
    
    /* Conto le componenti connesse totali del grafo */

    int comp=0;
    while (en != NULL){
        if(en->info->color==0) {        //trovato nodo non visitato
            comp++;                     //incremento il numero di componenti connesse
            DFS(en, comp);              //visito e marco i nodi con comp
        }
        en=en->next;
    }

    int foglie_albero = conta_foglie(a);
    int c;                              //indice di una componente connessa
    for(c=1; c<=comp; c++){             //ciclo che scorre tutte le componenti connesse
        if(conta_nodi(g,c)==foglie_albero)      //trovata
            return 1;
        return 0;                       //nessuna componente trovata
    }
}