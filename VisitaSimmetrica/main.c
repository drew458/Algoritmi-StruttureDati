#include <stdio.h>

typedef struct struttura_nodo {
	struct struttura_nodo* parent;
	struct struttura_nodo* left;
	struct struttura_nodo* right;
	int key;
} nodo;

typedef nodo* albero;

void simmetrica(nodo* a) {
	if(a != NULL) {
		simmetrica(a->left);
		printf("%d", a->key);
		simmetrica(a->right);
	}
}

int main() {
	nodo b,c,d,e,f,g;
	b.parent = NULL; /* b e' la radice */
	b.key = 5;
	b.left = &c;
    b.right = &d;

	c.parent = &b; /* c e' figlio di b */
	c.key = 3;
	c.left = &e;
    c.right = &f;

    d.parent = &b;
    d.key = 7;
    d.left = NULL;
    d.right = &g;

    e.parent = &c;
    e.key = 2;
    e.left = NULL;
    e.right = NULL;
	
	f.parent = &c;
    f.key = 5;
    f.left = NULL;
    f.right = NULL;
	
	g.parent = &d;
    g.key = 8;
    g.left = NULL;
    g.right = NULL;
	
	printf("La visita in ordine simmetrico è: \n");
	simmetrica(&b);
	return 0;
	
}