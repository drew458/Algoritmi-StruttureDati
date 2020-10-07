/* Struttura di un nodo del grafo*/
typedef struct nodo_struct {
    elem_nodi* pos;                 //posizione del nodo nella lista del grafo
    elem_nodi* archi;               //lista archi incidenti
    int color;
} nodo;

/* La struttura di un arco */
typedef struct arco_struct {
    elem_archi* pos;                //posizione dell'arco nella lista del grafo
    nodo*from;
    nodo*to;
    elem_archi* frompos;            //posizione arco nodo from
    elem_archi* topos;              //posizione arco nodo to
} arco;

/* Struttura di una lista di nodi */
typedef struct elementi_lista_nodi {
    struct elem_lista_nodi* prev;
    struct elem_lista_nodi* next;
    nodo*info;
} elem_nodi;

/* Struttura di una lista di archi */
typedef struct elementi_lista_archi {
    struct elem_lista_archi* prev;
    struct elem_lista_archi* next;
    arco*info;
} elem_archi;

/* Struttura di un grafo rappresentato con oggetti */
typedef struct {
    int numero_nodi;
    int numero_archi;
    elem_archi* archi;              //lista degli archi
    elem_nodi* nodi;                //lista dei nodi
} grafo_oggetti;

/* La struttura di un albero con struttura figlio sinistro e destro*/
typedef struct nodo_albero_struct {
    struct nodo_albero_struct* left;
    struct nodo_albero_struct* right;
    int info;
} nodo_albero;

/* La struttura di un albero con struttura figlio sinistro(left_child) e fratello destro(right_sibling)*/
typedef struct nodo_albero_struct2 {
    struct nodo_albero_struct2* left_child;
    struct nodo_albero_struct2* right_sibling;
    int info;
} nodo_albero2;

/* La struttura di un albero con struttura figlio sinistro(left) e figliodestro(right) 
*  con il campo parent */
typedef struct nodo_albero_struct {
    struct nodo_albero_struct* left;
    struct nodo_albero_struct* right;
    struct nodo_albero_struct* parent;
    int info;
} nodo_albero3;