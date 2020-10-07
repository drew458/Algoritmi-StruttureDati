#include <stdio.h>

/* Esercizio 3: Scrivi la funzione uguali che dati due alberi binari t1 e t2 restituisca 1 se i due alberi
 * sono uguali (stessi nodi con gli stessi valori contenuti), 0 altrimenti. */
 
typedef struct struttura_nodo {
	struct struttura_nodo* parent;
	struct struttura_nodo* left;
	struct struttura_nodo* right;
	int info;
}

typedef nodo* albero;

int uguali(albero t1,albero t2) {
	while(t1 != NULL && t2 != NULL){
		if(t1->info == t2->info){
			uguali(t1->left,t2->left);
			uguali(t1->right,t2->right);
			return 1;
		}
		else
			return 0;
	}
}

int main() {
	nodo b1,c1,d1,e1,f1,g1,h1
	b1.parent=NULL;
	b1.left=&c1;
	b1.right=&d1;
	b1.info=2;
	
	c1.parent=&b1;
	c1.left=&e1;
	c1.right=&f1;
	c1.info=3;
	
	d1.parent=&b1;
	d1.left=&g1;
	d1.right=&h1;
	d1.info=5;
	
	e1.parent=&c1;
	e1.left=NULL;
	e1.right=NULL;
	e1.info=8;
	
	f1.parent=&c1;
	f1.left=NULL;
	f1.right=NULL;
	f1.info=1;
	
	g1.parent=&d1;
	g1.left=NULL;
	g1.right=NULL;
	g1.info=7;
	
	h1.parent=&d1;
	h1.left=NULL;
	h1.right=NULL;
	h1.info=9;
	
	b2.parent=NULL;
	b2.left=&c2;
	b2.right=&d2;
	b2.info=2;
	
	c2.parent=&b2;
	c2.left=&e2;
	c2.right=&f2;
	c2.info=3;
	
	d2.parent=&b2;
	d2.left=&g2;
	d2.right=&h2;
	d2.info=5;
	
	e2.parent=&c2;
	e2.left=NULL;
	e2.right=NULL;
	e2.info=8;
	
	f2.parent=&c2;
	f2.left=NULL;
	f2.right=NULL;
	f2.info=1;
	
	g2.parent=&d2;
	g2.left=NULL;
	g2.right=NULL;
	g2.info=7;
	
	h2.parent=&d2;
	h2.left=NULL;
	h2.right=NULL;
	h2.info=9;
	
	if(uguali(&b1,&b2)==1)
		printf("Gli alberi sono uguali");
	else
		printf("Gli alberi non sono uguali");
	return 0;
}
