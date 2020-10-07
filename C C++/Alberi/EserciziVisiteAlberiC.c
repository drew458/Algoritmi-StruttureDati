
/* Esercizi delle slides 120-visite-di-alberi-02.pdf */

#include <stdio.h>
#include <stdlib.h>
#include <strutture.h>

/*--------------------------------------------------------------------------------------------------------------*/

/* Esercizio 2: Scrivi lo pseudocodice della procedura CERCA(t,n) 
*  che ritorna TRUE se il valore n e' presente nell'albero binario 
*  t facendo uso di una visita in preordine */ 
cerca_pre(nodo_albero* t, int n) {
    if(t==NULL) return 0;
    if(t->info == n) return 1;
    return cerca_pre(t->left, n) || cerca_pre(t->right, n);
}


/* facendo uso di una visita in postordine */
cerca_post(nodo_albero* t, int n) {
    if(t==NULL) return 0;
    if(t->left->info==n || t->right->info==n) return 1;
    return t->info==n;
}


/* facendo uso di una visita in simmetrica */
cerca_simm(nodo_albero* t, int n) {
    if(t==NULL) return 0;
    if(t->left->info==n) return 1;
    if(t->info) return 1;
    return t->right->info==n;
}

/*--------------------------------------------------------------------------------------------------------------*/

/* Esercizio 3: Scrivi lo pseudocodice della procedura CONTA-NODI(t) 
*  che ritorna il numero di nodi dell’albero binario t (fai uso di una visita in postordine) */
int conta_nodi(nodo_albero* t) {
     if(t == NULL) return 0;
     return 1 + conta_nodi(t->left) + conta_nodi(t->right);
}

/*--------------------------------------------------------------------------------------------------------------*/

/* Esercizio 4: Scrivi lo pseudocodice della procedura CAMMINO(t) 
*  che verifica se un albero binario t è un cammino cioe' se tutti 
*  i nodi hanno grado uno (un solo figlio) con l'eccezione dell'unica foglia. Assumi che un albero vuoto sia un cammino */
int cammino(nodo_albero* t) {
    if(t==NULL) return 0;
    return ((cammino(t->left) != NULL) || (cammino(t->right) == NULL)) ||
           ((cammino(t->left) == NULL) || (cammino(t->right) != NULL)); 
}

/*--------------------------------------------------------------------------------------------------------------*/

/* Esercizio 5: Scrivi lo pseudocodice della procedura HEIGHT(t) 
*  che calcola l'altezza (profondità) di un albero binario t cioe' il numero 
*  di archi del cammino che va dalla radice alla foglia piu' 
*  profonda (ritorna -1 se l'albero e' vuoto) */
int height(nodo_albero* t) {
    if(t==NULL) return 0;
    int l=height(t->left);
    int r=height(t->right);
    if(l>r) return 1+l;
    return 1+r;
}

/*--------------------------------------------------------------------------------------------------------------*/

/* Esercizio 6: Scrivi lo pseudocodice della procedura AVERAGE(t) 
*  che calcoli la media dei valori contenuti in un albero binario t 
*  (puoi far uso o meno di CONTA-NODI(t); se l'albero e' vuoto 
*  produci un errore). */
float average(nodo_albero* t) {
    if(t==NULL) return;
    float somma = somma + t->info;
    average(t->left);
    average(t->right);
    return somma/conta_nodi(t);
}

/*--------------------------------------------------------------------------------------------------------------*/

/* Esercizio 7: Scrivi lo pseudocodice della procedura COMPLETO(t) che 
*  verifichi se un albero binario t e' completo. Puoi far uso o meno 
*  della procedura HEIGHT(t). Se l'albero e' vuoto ritorna TRUE. */
int completo(nodo_albero* t) {
    int f = conta_foglie(t);
    int h = height(t);
    return 2^h == f;
}

int conta_foglie(nodo_albero* t) {
    if(t==NULL) return 0;
    int output;
    if(t->left == NULL && t->right == NULL) {       //ho trovato una foglia
        output++;
        }
    conta_foglie(t->left);
    conta_foglie(t->right);
    return output;
}

/*--------------------------------------------------------------------------------------------------------------*/

/* Esercizio 8: Scrivi lo pseudocodice della procedura DEALLOCA(t) che rimuova (deallocandoli) tutti i nodi di un albero t */
void dealloca(nodo_albero* t) {
    if(t==NULL) return;
    free(t);
    dealloca(t->left);
    dealloca(t->right);
}

/*--------------------------------------------------------------------------------------------------------------*/

/* Esercizio 9: Scrivi lo pseudocodice della procedura POTA(t,x) che elimini da un albero binario 
*  il sottoalbero radicato ad un nodo x specificato tramite riferimento.
*  Puoi omettere di deallocare i nodi potati */
void pota(nodo_albero* t, nodo_albero3* x) {
    if(x==t) {
        dealloca(x);
        return;
    }
    nodo_albero3* p = x->parent;
    if(x==p->left)
        p->left=NULL;
    if(x==p->right)
        p->right=NULL;
    dealloca(x);
    return;
}

/*--------------------------------------------------------------------------------------------------------------*/

/* ESERCIZIO 10: Scrivi lo pseudocodice della procedura 
*  POTA_PROFONDITA(t,h) che poti un albero binario lasciando solamente i nodi a profondita' minore di h
*  puoi fare uso o meno di POTA(t,x) */
void pota_profondita(nodo_albero3* t, int h) {
    if(height(t) == h) {
        nodo_albero3* x = t;
        dealloca(x);
        nodo_albero3* p = x->parent;
        if(p == x->left)
            x->left = NULL;
        if(p == x->right)
            x->right = NULL;
        dealloca(x);
        pota_profondita(x->left,h);
        pota_profondita(x->right, h);
    }
    pota_profondita(t->left, h);
    pota_profondita(t->right, h);
    return; 
}

/*--------------------------------------------------------------------------------------------------------------*/

/* ESERCIZIO 13: scrivi lo pseudocodice della procedura
 * VALORE-NONNO(t) che calcoli il numero di nodi dell’albero binario t che hanno lo stesso valore 
 * del genitore del genitore (cioè del nonno) */
int valore_nonno(nodo_albero3* t) {
    if(t == NULL) return 0;
    int output=0;
    nodo_albero3* padre = t->parent;
    if(padre->parent == t)
        output++;
    return output = output + valore_nonno(t->left) + valore_nonno(t->right);
}

/*--------------------------------------------------------------------------------------------------------------*/

/* ESERCIZIO 14: Scrivi lo pseudocodice della procedura DUE-FIGLI(t) che calcoli il numero di nodi 
 * nell’albero binario t che hanno esattamente due figli */
int due_figli(nodo_albero3* t) {
    if(t==NULL) return 0;
    int output = 0;
    if(t->left != NULL && t->right != NULL)
        output++;
    return output = output + due_figli(t->left) + due_figli(t->right);
}

/*--------------------------------------------------------------------------------------------------------------*/

/* ESERCIZIO 16: Scrivi la procedura CAMMINO(t,n) che ritorni una lista con gli identificatori 
 * dei nodi del cammino dalla radice fino al nodo il cui riferimento e' n. Puoi supporre che n appartenga all'albero */
elem_nodi* cammino(nodo_albero3* t, nodo_albero3* n) {
    nodo_albero3* x = n;
    elem_nodi* ln;
    while(x != NULL) {
        ln->info = x;
        ln = ln->next;
        x = x->parent;
    }
    return ln;
}

/*--------------------------------------------------------------------------------------------------------------*/

/* Costruisco un albero di esempio */

nodo_albero3* albero_esempio() {
    nodo_albero3** albero = (int*)calloc(16, sizeof(nodo_albero3*));
    int input;
    for(int i=0; i<16; i++) {
        albero[i] = (nodo_albero3*)malloc(sizeof(nodo_albero3));
        printf("Inserire elemento di posizione %d dell'albero", i);
        scanf("%d", &input);
        albero[i]->info = input;
        albero[i]->parent = NULL;
        albero[i]->left = NULL;
        albero[i]->right = NULL;
    }

    albero[0]->left = albero[1];
    albero[0]->right = albero[2];
    albero[1]->left = albero[3];
    albero[1]->right = albero[4];
    albero[2]->left = albero[5];
    albero[2]->right = albero[6];
    albero[3]->left = albero[7];
    albero[3]->right = albero[8];
    albero[4]->left = albero[9];
    albero[4]->right = albero[10];
    albero[5]->left = albero[11];
    albero[5]->right = albero[12];
    albero[6]->left = albero[13];
    albero[6]->right = albero[14];
    albero[8]->right = albero[15];

    albero[1]->parent = albero[0];
    albero[2]->parent = albero[0];
    albero[3]->parent = albero[1];
    albero[4]->parent = albero[1];
    albero[5]->parent = albero[2];
    albero[6]->parent = albero[2];
    albero[7]->parent = albero[3];
    albero[8]->parent = albero[3];
    albero[9]->parent = albero[4];
    albero[10]->parent = albero[4];
    albero[11]->parent = albero[5];
    albero[12]->parent = albero[5];
    albero[13]->parent = albero[6];
    albero[14]->parent = albero[6];
    albero[15]->parent = albero[8];
}

/*--------------------------------------------------------------------------------------------------------------*/

/* Funzione principale */

int main() {
    nodo_albero3* a = albero_esempio();
    int valore;

    /* Test del metodo cerca */
    printf("Inserire il valore da cercare nell'albero");
    scanf("%d", &valore);
    if(cerca_pre(a, valore))
        printf("Il valore è presente nell'albero! (ricerca preordine)");
    else printf("Il valore NON è presente nell'albero (ricerca preordine)");
    if(cerca_post(a, valore))
        printf("Il valore è presente nell'albero! (ricerca postordine)");
    else printf("Il valore NON è presente nell'albero (ricerca postordine)");
    if(cerca_simm(a, valore))
        printf("Il valore è presente nell'albero! (ricerca simmetrica)");
    else printf("Il valore NON è presente nell'albero (ricerca simmetrica)");

    /* Test metodo conta_nodi */
    printf("I nodi dell'albero sono %d (atteso %d)", conta_nodi(a), 16);

    /* Test metodo cammino */
    if(!cammino(a)) 
        printf("L'albero non è un cammino");
    else printf("L'albero è un cammino");

    /* Test metodo height */
    printf("L'albero ha profondita' %d (atteso %d)", height(a), 5);
}
