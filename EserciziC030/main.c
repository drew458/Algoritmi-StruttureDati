#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

void INSERT(lista* pl, int v) {

	elem* e = (elem*)malloc(sizeof(elem));

	e->info = v;
	e->prev = NULL;
	e->next = (*pl);

	if((*pl) != NULL )    /* c'era gia' un elemento in lista */
		(*pl)->prev = e;  /* ho aggiornato il suo campo prev */

	(*pl) = e;
}

void PRINT(lista l) {

	printf("la lista contiene: ");
	if (l != NULL) {
		printf("%d",l->info);
	    l = l->next;
	}
	while (l != NULL) {
		printf(", %d",l->info);
		l = l->next;
	}
	printf(".\n");
}

void DELETE(lista* pl, int v){

	elem* e = (*pl);
	while (e != NULL ) {

		if( e->info == v ) {   /* devo rimuovere questo elemento */

			if ( e->prev != NULL )
				e->prev->next = e->next;
			else
				(*pl) = e->next;

			if ( e->next != NULL )
				e->next->prev = e->prev;

			free(e);
			return;
		}
		e = e->next;
	}


}
