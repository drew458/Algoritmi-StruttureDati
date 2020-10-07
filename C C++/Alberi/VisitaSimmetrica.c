#include <stdio.h>

typedef struct struttura_nodo {
    struct struttura_nodo* parent;
    struct strutttura_nodo* left;
    struct struttura_nodo* right;
    int key;    
} nodo;

/* Visita dell'albero */
void visitaSimmetrica(nodo* a) {
    if(a!=NULL) {
        visitaSimmetrica(a->left);
        printf("%d ", a->key);
        visitaSimmetrica(a->right);
    }
}

/* Ricerca */
int cerca_simmetrica(nodo* n, int v){
    if(n==NULL)
        return 0;
    if(cerca_simmetrica(n->left, v))
        return 1;
    if(n->key==v)
        return 1;
    return cerca_simmetrica(n->right,v);
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

    printf("La visita simmetrica è: ");
    visitaSimmetrica(&b);
    int t, u;
    printf("Si vuole ricercare un elemento nell'albero?   1=SI , 0=NO");
    scanf("%d", &t);
    if(t==1)
        printf("Inserire l'elemento da cercare\n");
        scanf("%d", &u);
        cerca_simmetrica(&b, u);
    return 0;
}