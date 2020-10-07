#include <stdio.h>
#include <strutture.h>

/* File con tutte le funzioni incontrate negli esami passati sugli alberi */

/* Funzione che trova il massimo tra due interi */
int massimo(int a, int b) {
    if(a>b)
        return a;
    return b;
}


/* Funzione che ritorna la profondità del nodo che contiene il valore k */
int profondità_nodo(nodo_albero*a, int k) {
    if(a==NULL) return -1;
    if(a->left == k)        
        return 0;
    int l=profondità_nodo(a->left, k);
    int r=profondità_nodo(a->right, k);
    int max=massimo(l,r);       //max è la profondità massima
    if(max==-1) return -1;      //non lo abbiamo trovato
    else return max+1;
}


/* verifica se il sottoalbero radicato al nodo a passato come parametro
*  contiene tutti valori info=1. L’albero è un albero di grado arbitrario.
*  Ritorna 0 (cioè false) quando lanciata su un albero NULL. */
int sottoalbero_omogeneo(nodo_albero* a) {
    if(a==NULL) return 0;
    if(a->info != 1) return 0;
    int output=1;
    nodo_albero* x = a->left;
    while(x != NULL) {
        output = output && sottoalbero_omogeneo(x);
        x = x->right;
    }
    return output;
}


/* ritorna il numero di sottoalberi omogenei dell’albero a di grado
*  arbitrario passato come parametro */
int sottoalberi_omogenei(nodo_albero* a) {
    if(a == NULL) return 0;
    int output;
    output = sottoalbero_omogeneo(a);
    nodo_albero* x = a->left;
    while(a != NULL) {
        output = output + sottoalbero_omogeneo(x);
        x = x->right;
    }
    return output;
}


/* funzione che conta le foglie in un albero con la struttura figlio sinistro - fratello destro */
int foglie_albero(nodo_albero2* a) {
    if(a==NULL) return 0;
    if(a->left_child == NULL)       //trovata una foglia
        return 1 + foglie_albero(a->right_sibling);
    return foglie_albero(a->left_child) + foglie_albero (a->right_sibling);
}


/* funzione che ritorna 1 se esiste un nodo nell'albero di grado arbitrario che abbia esattamente "max" figli */
int esiste_genitore_con_figli(nodo_albero2* a, int max) {
    if(a==NULL) return 0;

    //Verifica se sono un nodo con max figli
    
    int contatore=0;
    nodo_albero2* figlio = a->left_child;   
    while(figlio != NULL) {     //trovato un figlio
        contatore++;
        figlio = figlio->right_sibling;
    }
    if(contatore==max)
        return 1;
    
    return esiste_genitore_con_figli(a->left_child,max) || esiste_genitore_con_figli(a->right_sibling, max);
}


/* funzione che restituisce la profondità di un albero */
int profondita_albero(nodo_albero* a) {
    if(a==NULL) return -1;
    int l=profondità_albero(a->left);
    int r=profondita_albero(a->right);
    if(l>r)
        return l;
    return r;
}


/* Conta i nodi per ogni livello dell'albero binario */
void conta_nodi_livelli(nodo_albero* a, int* contatore, int livello) {
    if(a==NULL) return;

    contatore[livello]++;
    conta_nodi_livelli(a->left, contatore, livello+1);
    conta_nodi_livelli(a->right, contatore, livello+1);
}


/* Ritorna il numero di sottoalberi con una profondità h in un albero */
int sottoalberi_prof(nodo_albero* a, int h) {
    if(a == NULL) return 0;
    int output;
    output = sottoalberi_prof(a->left, h) + sottoalberi_prof(a->right, h);
    if(profondita_albero(a)==h)
        output++;
    return output;
}


/* Funzione che calcola il numero di nodi a profondità h */
int nodi_prof(nodo_albero* a, int h) {
    if(a==NULL) return 0;
    if(h==0) return 1;
    int output = nodi_prof(a->left, h-1) + nodi_prof(a->right, h-1);
    return output;
}


/* Funzione che conta i nodi che hanno un figlio unico in un albero */
int nodi_figlio_unico(nodo_albero* a) {
    if(a==NULL) return 0;
    if(a->left==NULL || a->right==NULL) return 1;
    int output = nodi_figlio_unico(a->left) + nodi_figlio_unico(a->right);
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