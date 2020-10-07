#include <stdio.h>          /* così posso usare NULL */
#include <strutture.h>      /* strutture fornite nel testo */

/* ------------------------------------------ TESTO ESAME ---------------------------------------------------- 

    Scrivi in linguaggio C il codice della funzione
        int verifica(grafo_oggetti* g, nodo_albero* a)
    che accetti in input un puntatore ad grafo non orientato g rappresentato tramite oggetti e un puntatore a
    alla radice di un albero di grado arbitrario di interi rapresentato tramite la 
    struttura figlio‐sinistro (left) e fratello destro (right). 
    La funzione restituisce 1 se il numero delle componenti connesse del grafo è
    uguale al numero di sottoalberi “omogenei” dell’albero a, altrimenti la funzione restituisce 0. 
    Un sottoalbero è “omogeneo” se ha il valore 1 nel campo info di tutti i suoi nodi (compresa la radice del
    sottoalbero). Se grafo e albero sono entrambi vuoti (cioè uguali a NULL) la funzione ritorna true. 
    Se uno è vuoto e uno no, allora ritorna false.


/* vista DFS (Depth-First Seach) del grafo rappresentato tramite oggetti e riferimenti */
void DFS(nodo*n) {
    n->color=1;                                 //Coloro il nodo come visitato
    elem_archi* ea= n->archi;                   /* creo una nuova lista di archi e la riempio 
    									           con tutti gli archi adiancenti al nodo n */
    while(ea != NULL) {                         /* finchè non ci sono più archi... */
        nodo* altro_nodo = ea->info->from;      /* creo un nodo che punta al nodo da cui parte 
                                                   l'arco adiacente al nodo n */
        if(altro_nodo==n) {                     /* se il nodo creato è proprio uguale al nodo n... */ 
            altro_nodo = ea->info->to;          /* punta al nodo di destinazione dell'arco 
                                                   adiancente al nodo n */
        }
        if(altro_nodo->color == 0) {            //Se non è gia stato visitato....
            DFS(altro_nodo);                    //Lo visito
        }
        ea=ea->next;
    }
} 


/* verifica se il sottoalbero radicato al nodo a passato come parametro
*  contiene tutti valori info==1. L’albero è un albero di grado arbitrario.
*  Ritorna 0 (cioè false) quando lanciata su un albero NULL. */
int sottoalbero_omogeneo(nodo_albero2* a){
    if(a == NULL) return 0;
    if(a->info != 1) return 0;
    int output=1;
    nodo_albero2* x=a->left_child;
    while(x!=NULL) {
        output = output && sottoalbero_omogeneo(x);
        x = x->right_sibling;
    }
    return output;
}


/* ritorna il numero di sottoalberi omogenei dell’albero a di grado
*  arbitrario passato come parametro */
int sottoalberi_omogenei (nodo_albero2* a) {
    int output=0;
    if(a==NULL) return output;                  //cioè return 0
    output = sottoalbero_omogeneo(a);           //conta questo sottoalbero 
    nodo_albero2* x = a->left_child;
    while(x != NULL) {
        output = output + sottoalbero_omogeneo(x);
        x=x->right_sibling;
    }
    return output;
}


/* La funzione restituisce 1 se il numero delle componenti connesse del grafo è
*  uguale al numero di sottoalberi “omogenei” dell’albero a, altrimenti la funzione restituisce 0. Un
*  sottoalbero è “omogeneo” se ha il valore 1 nel campo info di tutti i suoi nodi (compresa la radice del
*  sottoalbero). Se grafo e albero sono entrambi vuoti (cioè uguali a NULL) la funzione ritorna true. Se uno è
*  vuoto e uno no, allora ritorna false. */
int verifica (grafo_oggetti* g, nodo_albero2* a) {
    if(g==NULL && a==NULL) return 1;        //se grafo e albero entrambi null, restituisci 1
    if(g==NULL && a != NULL) return 0;      //se un dei due è null e l'altro no, restituisci 0
    if(g != NULL && a==NULL) return 0;

    elem_nodi* en = g->nodi;
    while (en != NULL) {
        en->info->color=0;           //marco tutti i nodi con 0
        en=en->next;                 //scorro i nodi
    }

    int comp=0;                      //numero delle componenti connesse
    while (en != NULL) {
        if(en->info->color == 0 ) {  //trovato nodo non visitato
            comp++;                  //aggiorno il numero delle componenti connesse
            DFS(en);                 //visito e marco con 1
        }
        en=en->next;                 //scorro i nodi
    }
    return comp==sottoalberi_omogenei(a);
}