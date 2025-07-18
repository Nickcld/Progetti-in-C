/*Dati in input due array di numeri floating point: A composto da n numeri disposti in ordine crescente e B composto da m numeri disposti
in ordine casuale, inserire al centro di A i numeri presenti in B mantenendo l'ordine crescente senza l'uso di un terzo array di appoggio.*/

#include <stdio.h>
#include <stdlib.h>

void ordinare_vettore(float B[], int m);
void fondere_vettori(float A[], int n, float B[], int m);

int main() {

	float A[12] = {1.0, 4.0, 9.0, 10.0, 14.0, 16.0, 23.0, 30.0};
	float B[4] = {26.0, 2.0, 13.0, 21.0};
	int n = 8;
	int m = 4;
	int nuova_dimensione = n + m;
	int i;

	printf("\nElenco A aggiornato contenente anche gli elementi dell'elenco B e che mantiene l'ordine crescente:\n");

	ordinare_vettore(B, m);
	fondere_vettori(A, n, B, m);

	i = 0;
	while (i < nuova_dimensione) {
		printf("%.1f ", A[i]);
		i = i + 1;
	}
	printf("\n");


	system("PAUSE");
	return 0;
}

void ordinare_vettore(float B[], int m) {
	int j;
	float temp;
    int ordinato;

    j = 0;
    ordinato = 0;
    while (ordinato == 0) {
    	j = 0;
    	ordinato = 1;
    	while (j < m - 1) {
    		if (B[j] > B[j + 1]) {
    			temp = B[j];
    			B[j] = B[j + 1];
    			B[j + 1] = temp;
    			ordinato = 0;
    		}
    	    j = j + 1;
    	}
    }
    return;
}


void fondere_vettori(float A[], int n, float B[], int m) {
	int nuova_dimensione;
	int i;
	int j;
	float temp;
	int ordinato;

	nuova_dimensione = n + m;
	i = nuova_dimensione - 1;
	j = m - 1;
	while (i > n - 1 && j >= 0) {
		A[i] = B[j];
		i = i - 1;
		j = j - 1;
	}
	ordinato = 0;
	i = 0;
	while (ordinato == 0) {
		ordinato = 1;
		i = 0;
	    while (i < nuova_dimensione - 1) {
            if (A[i] > A[i + 1]) {
        	    temp = A[i];
        	    A[i] = A[i + 1];
        	    A[i + 1] = temp;
        	    ordinato = 0;
            }
	        i = i + 1;
	    }
	}
    return;
}



