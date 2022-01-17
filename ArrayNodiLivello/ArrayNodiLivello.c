#include <stdlib.h>
#include <stdio.h>

typedef struct nodo_albero_struct {

	 struct nodo_albero_struct* left;
	 struct nodo_albero_struct* right;
	 int info;
} nodo;

typedef nodo* albero;


int conta_nodi_livello(nodo* n, int h) {

	if( n == NULL ) return 0;
	if( h == 0 ) return 1;
	return conta_nodi_livello(n->left,h-1) +
	       conta_nodi_livello(n->right,h-1);
}


int riempi_array(int* A, albero a, int h, int i)  {

  	if ( a == NULL ) return i;
    if ( h == 0 ) {
      	A[i] = a->info;
      	return i+1;
    }
    i = riempi_array(A, a->left, h-1,i);
    i = riempi_array(A, a->right, h-1,i);

    return i;
}



int* array_nodi_livello(albero a, int h) {

	int num_nodi = conta_nodi_livello(a, h);

	int* A = (int*)calloc(num_nodi, sizeof(int));

	riempi_array(A,a,h,0);    /* riempi l'array A a partire dalla 
	                             posizione 0 con i nodi 
	                             del sottoalbero radicato ad a
	                             a profondita' h */

    return A;
}