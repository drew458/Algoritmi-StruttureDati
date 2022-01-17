#include <stdio.h>

/* Scrivi una funzione in linguaggio C 
che verifichi se in un array di interi 
ci sia almeno un intero ripetuto due volte */

int ripetuto(int* array, int dim); // dichiarazione
int ripetuto_tre(int* array, int dim); // dichiarazione

int main(int argc, char** argv) {

	int A[10];
	int i;
	for( i=0; i<10; i++) {
		A[i] = i;
	}
	printf("ripetuto(A,10) = %d (false)\n",ripetuto(A,10));
    printf("ripetuto_tre(A,10) = %d (false)\n",ripetuto_tre(A,10));

    printf("setto A[9]=0\n");
    A[9] = 0;
	printf("ripetuto(A,10) = %d (true)\n",ripetuto(A,10));
    printf("ripetuto_tre(A,10) = %d (false)\n",ripetuto_tre(A,10));

    printf("setto A[5]=0\n");
    A[5] = 0;
	printf("ripetuto(A,10) = %d (true)\n",ripetuto(A,10));
    printf("ripetuto_tre(A,10) = %d (true)\n",ripetuto_tre(A,10));
 

}


int ripetuto(int* array, int dim) { // definizione

   int trovata_ripetizione = 0;  // 0 == false
   int i, j;   // indici
   for( i=0; i<dim-1; i++) {
   		for( j=i+1; j<dim; j++) {
   			if(array[i]==array[j])
   				trovata_ripetizione = 1;  // 1 == true
   		}
   }
   return trovata_ripetizione;
}

int ripetuto_tre(int* array, int dim) { // definizione

   int trovata_ripetizione = 0;  // 0 == false
   int i, j;   // indici
   for( i=0; i<dim-1; i++) {
   	    int cont = 0;
   		for( j=i+1; j<dim; j++) {
   			if(array[i]==array[j])
   				cont++;  
   		}
   		if( cont > 1 ) trovata_ripetizione = 1;
   }
   return trovata_ripetizione;
}