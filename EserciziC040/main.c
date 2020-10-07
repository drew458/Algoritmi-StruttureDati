#include <stdio.h>

/* definisco la struttura di un nodo */
typedef struct struttura_nodo {

	struct struttura_nodo* parent;
	struct struttura_nodo* left;
	struct struttura_nodo* right;
	int info;

} nodo;

typedef nodo* albero;

typedef struct struttura_elemento {

	int info;
	struct struttura_elemento* next;
} elem;

/* Esercizio 1: Scrivi la funzione ricerca che dato un albero binario t e un intero k, restituisca 1 se
   k è contenuto in almeno un nodo di t e restituisca 0 altrimenti
		– definisci anche le strutture di dati
		– se l’albero è vuoto restituisci 0 */

/* ricerca con vista in preordine */
int ricerca(albero a, int k) {

	if (a == NULL) return 0;

	if ( a->info == k ) return 1;

	return ricerca(a->left,k) || ricerca(a->right,k);
} 


int main() {

	albero a = NULL;
	printf("Cerco 4 sull'albero vuoto = %d\n",ricerca(a,4));

	nodo b,c,d,e;
	b.parent = NULL; /* b e' la radice */
	b.info = 10;
	b.left = &c;
    b.right = &d;

	c.parent = &b; /* c e' figlio di b */
	c.info = 20;
	c.left = NULL;
    c.right = &e;

    d.parent = &b;
    d.info = 30;
    d.left = NULL;
    d.right = NULL;

    e.parent = &c;
    e.info = 40;
    e.left = NULL;
    e.right = NULL;

	printf("Cerco 4 sull'albero creato = %d\n",ricerca(&b,4));

	printf("Cerco 40 sull'albero creato = %d\n",ricerca(&b,40));
}

-------------------------------------------------------------------------------------------------------------------

/* Esercizio 2: Scrivi la funzione get_max che dato un albero binario t restituisca il valore massimo
   tra i valori contenuti nei nodi di t
     – definisci anche le strutture di dati
     – se l’albero è vuoto restituisci -1 */

int massimo(t) {
	
	if (a == NULL) return -1;

	int max = a->info;

    int l = massimo(a->left);
    int r = massimo(a->right);
    if ( max < l ) max = l;
    if ( max < r ) max = r;
    return max;
}

-------------------------------------------------------------------------------------------------------------------

/* Esercizio 3: Scrivi la funzione uguali che dati due alberi binari t1 e t2 restituisca 1 se i due alberi
 * sono uguali (stessi nodi con gli stessi valori contenuti), 0 altrimenti. */
 
int uguali(albero t1,albero t2) {
	
	if( (t1 == NULL) && (t2 == NULL) )  /* t1 e t2 sono alberi vuoti, quindi uguali */
    	return 1;

    if( (t1 == NULL) || (t2 == NULL) )  /* uno dei due e' NULL e l'altro e' diverso da NULL */
    	return 0;
	
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

-----------------------------------------------------------------------------------------------------------------------------------

/* Esercizio 4: Scrivi la funzione esiste_foglia che dato un albero binario t e un intero k 
 * restituisca 1 se esiste una foglia di t con valore k, 0 altrimenti */
 
int esiste_foglia(albero t1, int k) {

	while(t1 != NULL){
		if(t1->info == k) 
			return 1
		esiste_foglia(t1->left, k);
		esiste-foglia(t1->right, k);
	}
	return 0;
}

-----------------------------------------------------------------------------------------------------------------------------------

/* Esercizio 5. Scrivi la funzione altezza che dato un albero binario t 
 * restituisca l'altezza dell'albero. Se l'albero e' vuoto restituisce -1. */
 
 int altezza(albero t1) {
	int altezza=0;
	while(t1 != NULL) {
		t1 = t1->next;
		altezza++;
	}
	return altezza;
 }
 
-------------------------------------------------------------------------------------------------------------------------------------

/* Esercizio 6: Scrivi la funzione numero_nodi_livello che dato un albero binario t e un intero h restituisca il
 * numero dei nodi dell’albero t alla profondità h */
 
int numero_nodi_livello(albero t1, int h){
	if (t1 == NULL) return 0;  /* ci sono zero nodi a profondita' h */

	if( h == 0 ) return 1;

	return numero_nodi_livello(t1->left, h-1) +
	       numero_nodi_livello(t1->right, h-1); 
 }
 
 -------------------------------------------------------------------------------------------------------------------------------------

 /* Esercizio 7: Scrivi la funzione lista_foglie che dato un albero binario t 
  * restituisca una lista semplicemente concatenata contenente i valori 
  * di tutte le foglie di t. Definisci anche le strutture dati e 
  * le funzioni di manipolazione della lista. Se t e' vuoto restituisci 
  * una lista vuota */
  
void ricorri_lista_foglie(albero n, elem** pl) {

    if (n == NULL) return;

    if ((n->left == NULL) && (n->right == NULL)) {

    	elem* e = (elem*)malloc(sizeof(elem));
    	e->info = n->info;
    	e->next = (*pl);
    	(*pl) = e;
    }

    ricorri_lista_foglie(n->left,pl);
    ricorri_lista_foglie(n->right,pl);
} 

elem lista_foglie(albero n) {

   elem l = NULL;					//creo una lista vuota (l)
   ricorri_lista_foglie(n,&l); 
   return l;						//ritorna la litsa
}

int main() {

	albero a = NULL;

    nodo* e = (nodo*)malloc(sizeof(nodo));

	nodo b,c,d;
	b.parent = NULL; /* b e' la radice */
	b.info = 10;
	b.left = &c;
    b.right = &d;

	c.parent = &b; /* c e' figlio di b */
	c.info = 20;
	c.left = NULL;
    c.right = e;

    d.parent = &b;
    d.info = 30;
    d.left = NULL;
    d.right = NULL;

 
    (*e).parent = &c;   /* equivalente alla freccia */
    e->info = 40;
    e->left = NULL;
    e->right = NULL;

	printf("Confronto \"a\" con se stesso = %d\n",uguali(a,a));

	printf("Confronto \"b\" con se stesso = %d\n",uguali(&b,&b));

	printf("Confronto \"b\" con \"a\" = %d\n",uguali(&b,a));

	printf("Confronto \"b\" con \"d\" = %d\n",uguali(&b,&d));

	printf("Confronto \"b\" con \"c\" = %d\n",uguali(&b,&c));

	printf("Confronto \"b\" con \"e\" = %d\n",uguali(&b,e));

	printf("Cerco una foglia di \"b\" con valore 20 = %d\n",esiste_foglia(&b,20));
	printf("Cerco una foglia di \"b\" con valore 30 = %d\n",esiste_foglia(&b,30));
	printf("Cerco una foglia di \"b\" con valore 40 = %d\n",esiste_foglia(&b,40));
	printf("Cerco una foglia di \"b\" con valore 50 = %d\n",esiste_foglia(&b,50));

	printf("Altezza di \"b\" = %d (dovrebbe essere 2)\n",altezza(&b));
	printf("Altezza di \"c\" = %d (dovrebbe essere 1)\n",altezza(&c));
	printf("Altezza di \"e\" = %d (dovrebbe essere 0)\n",altezza(e));

	printf("numero nodi di \"b\" a livello 0 = %d",numero_nodi_livello(&b,0));
	printf("(dovrebbe essere 1)\n");
	printf("numero nodi di \"b\" a livello 1 = %d",numero_nodi_livello(&b,1));
	printf("(dovrebbe essere 2)\n");
	printf("numero nodi di \"b\" a livello 2 = %d",numero_nodi_livello(&b,2));
	printf("(dovrebbe essere 1)\n");
	printf("numero nodi di \"b\" a livello 3 = %d",numero_nodi_livello(&b,3));
	printf("(dovrebbe essere 0)\n");

    elem* l = lista_foglie(&b);
    while ( l != NULL) {
    	printf("trovata foglia %d\n",l->info);
    	l = l->next;
    }
}

-----------------------------------------------------------------------------------------------------------------------------------------

/* Esercizio 9: Scrivi la funzione array_nodi_livello che dato un albero binario t e un intero h 
 * restituisca un array contenente i valori dei nodi dell’albero t alla profondità h .
 * Restituisce NULL se l’albero non ha nodi alla profondità h. */
 
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

	riempi_array(A,a,h,0);    /* riempi l'array A a partire dalla  posizione 0 con i nodi 
	                             del sottoalbero radicato ad a con profondita' h */
	return A;
}