#include <stdio.h>
#include <stdlib.h>

typedef struct struttura_nodo {
    struct struttura_nodo* parent;
    struct struttura_nodo* left;
    struct struttura_nodo* right;
    int key;
} nodo;

typedef nodo* albero;

/* ricerca */
int ricerca(albero a, int k) {

	if (a == NULL) return 0;

	if ( a->key == k ) return 1;

	return ricerca(a->left,k) || ricerca(a->right,k);
}

int main () {
    nodo b,c,d,e,f,g;
    b.parent=NULL;
    b.left=&c;
    b.right=&d;
    b.key=5;

    c.parent=&b;
    c.left=&e;
    c.right=&f;
    c.key=3;

    d.parent=&b;
    d.left=NULL;
    d.right=&g;
    d.key=7;

    e.parent=&c;
    e.left=NULL;
    e.right=NULL;
    e.key=2;

    f.parent=&c;
    f.left=NULL;
    f.right=NULL;
    f.key=5;

    g.parent=&d;
    g.left=NULL;
    g.right=NULL;
    g.key=8;

    int elem;
    printf("Inserire l'elemento da ricercare\n");
    scanf("%d", &elem);
    if(ricerca(&b,elem)==1)
        printf("Elemento trovato!\n");
    else printf("Elemento non trovato\n");
    return 0;
}