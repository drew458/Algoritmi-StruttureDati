/* Esercizio 1:
Scrivi la procedura MASSIMO(a,b) che ritorni il 
massimo tra due interi a e b */
---------------------------------------------------

MASSIMO(a,b)  // a e b sono due interi di cui devo
              // ritornare il massimo
    if (a > b)
    	return a
    return b
==============================================
/* Esercizio 2:
Scrivi la procedura MASSIMO(A) che riceva come 
parametro un array di interi A e ritorni il massimo 
dei valori contenuti */
---------------------------------------------------
MASSIMO(A)  // ritorna il massimo dei valori
            // contenuti nell'array
    max = A[0]
    for i=1 to A.length-1
    	if( A[i] > max)
    		max = A[i]
    return max
==============================================
/* Esercizio 3:
Scrivi la procedura SOMMA(M) che riceva come 
parametro una matrice (un array di array) di interi 
M e ritorni la somma dei valori contenuti */
---------------------------------------------------
SOMMA(M)  // M è un array di array di interi

    somma = 0
    for i=0 to M.length-1
    	for j=0 to M[i].length-1
    		somma += M[i][j]
    return somma
==============================================
/* Esercizio 4:
Scrivi la procedura POSITIVO(A) che riceva come 
parametro un array di interi A e ritorni true se 
A contiene solo valori maggiori di zero, false altrimenti */
---------------------------------------------------
POSITIVO(A)  // ritorna true se tutti i valori
             // di A sono maggiori di zero

    for i=0 to A.length-1
    	if( A[i] <= 0 )
    		return false
    return true
==============================================
/* Versione più prolissa dell'esercizio precedente */
---------------------------------------------------
POSITIVOA(A)  // ritorna true se tutti i valori
             // di A sono maggiori di zero

    positivo = true
    i = 0
    while (i < A.length && positivo)
    	if( A[i] <= 0)
    		positivo = false
    	i = i+1
    return positivo
==============================================
/* Esercizio 5:
Scrivi la procedura POSIZIONE-MASSIMO(A) che riceva 
come parametro un array di interi A e ritorni il valore 
massimo contenuto e la sua posizione nell'array */
---------------------------------------------------
POSIZIONE_MASSIMO(A) // ritorna il massimo e la sua posizione
                    //  out è un oggetto con due campi interi: max e 
                    // pos 
    out.max = A[0]
    out.pos = 0

    for i=1 to A.length-1
    	if (A[i] > out.max)
    		out.max = A[i]
    		out.pos = i

    return out	
==============================================

















