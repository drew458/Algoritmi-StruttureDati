#include <stdlib.h>
#include <iostream>

int cerca(char A[], char stringa) {
    for (int i =0; i < sizeof(A); i++)
    {
        if (A[i]==stringa)
            return i;
    }
}

int main () {
    int elem;
    printf("Inserire numero di elementi nell' array\n");
    scanf("%d", &elem);
    char A[elem];
    for (int i = 0; i < elem; i++)
    {
        printf("Inserire elemento di posizione %d all'interno dell'array\n");
        scanf("%d", &A[i]);
    }
    char stringa;
    printf("Inserire la stringa da ricercare nell'array\n");
    scanf("%c", &stringa);
    cerca(A, stringa);    
}