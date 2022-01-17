/* 1. Implementa in linguaggio C uno stack di interi con le funzioni NEW_STACK,
   IS_EMPTY, PUSH, e POP e con la gestione telescopica della memoria

 * 2. Implementa in linguaggio C una coda di interi con le funzioni NEW_QUEUE, IS_EMPTY,
   ENQUEUE, e DEQUEUE e con la gestione telescopica della memoria

 * */

#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

stack NEW_STACK() {

	stack s = (stack)malloc(sizeof(struttura_stack));
	s->A = (int*)calloc(4,sizeof(int));
	s->A_length = 4;
	s->top = -1;
    return s;
}

/* verifica se lo stack e' vuoto */

int IS_EMPTY(stack s) {

   return s->top == -1;
}

/* inserisce un intero nello stack */

void PUSH(stack s, int x) {

	if( s->top == s->A_length-1 ) {
		// printf("errore: overflow!\n");
		// exit(1);
		s->A_length = 2 * s->A_length;
		s->A = (int*)realloc(s->A,s->A_length*sizeof(int));
		printf("ora lo stack ha dimensione %d\n",s->A_length);
	}
	s->top = s->top+1;
	s->A[s->top] = x;
}

void PRINT_STACK(stack s) {

	printf("Stack attuale: ");
	int i;
	for (i = 0; i <= s->top; i++) {
		printf("%d ",s->A[i]);
	}
	printf(" <--- top\n");
}

int POP(stack s) {

	if( s->top == -1) {  // lo stack e' vuoto
		printf("errore: POP da uno stack vuoto!\n");
		exit(1);
	}
	int x = s->A[s->top];
	s->top = s->top-1;
	return x;

	//return s->A[--s->top];
}

/******* USA STACK ************/

int main() {

	stack s = NEW_STACK(); 
	printf("ho allocato uno stack\n");
	printf("lo stack e' vuoto = %d\n",IS_EMPTY(s));

	PUSH(s,10);
	printf("ho inserito 10 nello stack\n");
	PRINT_STACK(s);
	PUSH(s,20);
	printf("ho inserito 20 nello stack\n");
	printf("lo stack e' vuoto = %d\n",IS_EMPTY(s));
	PRINT_STACK(s);


	PUSH(s,30);
	printf("ho inserito 30 nello stack\n");
	PRINT_STACK(s);
	PUSH(s,40);
	printf("ho inserito 40 nello stack\n");
	PRINT_STACK(s);

	printf("ora inserisco 50 nello stack\n");
	PUSH(s,50);
	PRINT_STACK(s);

	printf("ora inserisco 60 nello stack\n");
	PUSH(s,60);
	PRINT_STACK(s);

	printf("ora inserisco 70 nello stack\n");
	PUSH(s,70);
	PRINT_STACK(s);

	printf("ora inserisco 80 nello stack\n");
	PUSH(s,80);
	PRINT_STACK(s);

	printf("ora inserisco 90 nello stack\n");
	PUSH(s,90);
	PRINT_STACK(s);

	printf("Eseguo un pop: %d\n",POP(s));
	PRINT_STACK(s);
	

}


/******* QUEQUE *********/

queue NEW_QUEUE() {

  queue q = (queue)malloc(sizeof(struttura_coda));

  q->A = (int*)calloc(4,sizeof(int));
  q->A_length = 4;
  q->head = 0;
  q->tail = 0;
  // q->head = q->tail = 0;
}

void PRINT_QUEUE(queue q) {

    int i;
    printf("Coda attuale: ");
	if( q->tail >= q->head ) {
		for(i = q->head; i < q->tail; i++ ) {
			printf("%d ",q->A[i]);
		}
	} else {
		for(i = q->head ; i < q->A_length; i++) {
			printf("%d ",q->A[i]);			
		}
		for(i = 0 ; i < q->tail; i++) {
			printf("%d ",q->A[i]);			
		}
	} 
    printf(" <--- ultimo [");
	for(i = 0; i < q->A_length; i++ ) {
		printf("%d ",q->A[i]);
	}
    printf("]\n");

}

void ENQUEUE(queue q, int x) {

    if( 
    	(q->head == q->tail+1) || 
    	((q->tail == q->A_length-1) && (q->head == 0) ) 
      )  {
    	//printf("errore: enqueue in una coda piena\n");
    	//exit(1);
    	q->A_length= 2 * q->A_length;
    	printf("raddoppio l'array: ora e' lungo %d\n",q->A_length);
    	q->A = (int*)realloc(q->A,q->A_length*sizeof(int));
    	if( q->head == q->tail+1) {
    		int i;
    		for( i=0; i < q->tail; i++) {
    			q->A[(q->A_length/2)+i] = q->A[i];
    		}
    		q->tail = (q->A_length/2)+i;
    	}
    }

    q->A[q->tail] = x;
    q->tail = q->tail + 1;
    if( q->tail == q->A_length )
    	q->tail = 0;
}

int DEQUEUE(queue q) {

	if( q->head == q->tail ) {
		printf("errore: dequeue da coda vuota\n");
		exit(1);
	}
	int x = q->A[q->head];
	q->head = q->head+1;
	if(q->head == q->A_length)
		q->head = 0;
	return x;
}



/******* USA QUEQUE *******/

int main() {

	queue q = NEW_QUEUE();

	PRINT_QUEUE(q);

	printf("inserisco un elemento\n");
	ENQUEUE(q,10);
	PRINT_QUEUE(q);

	printf("eseguo un dequeue: %d\n",DEQUEUE(q));
	PRINT_QUEUE(q);

	printf("inserisco un elemento\n");
	ENQUEUE(q,20);
	PRINT_QUEUE(q);

	printf("inserisco un elemento\n");
	ENQUEUE(q,30);
	PRINT_QUEUE(q);

	printf("eseguo un dequeue: %d\n",DEQUEUE(q));
	PRINT_QUEUE(q);

	printf("inserisco un elemento\n");
	ENQUEUE(q,40);
	PRINT_QUEUE(q);

	printf("inserisco un elemento\n");
	ENQUEUE(q,50);
	PRINT_QUEUE(q);

	printf("inserisco un elemento\n");
	ENQUEUE(q,60);
	PRINT_QUEUE(q);

}