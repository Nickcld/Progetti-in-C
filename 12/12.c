/*Dati in input due array di numeri floating point: A composto da n numeri disposti in ordine crescente e B composto da m numeri disposti in
ordine casuale, inserire al centro di A i numeri presenti in B mantenendo l'ordine crescente senza l'uso di un terzo array di appoggio.*/


#include <stdio.h>
#include <stdlib.h>

void ordinare_vettore(float B[]);
void fondere_vettori(float A[], float B[]);

int main() {

	float A[10] = {0.0f, 4.0f, 9.0f, 14.0f, 16.0f, 21.0f};
	float B[4] = {10.0f, 3.0f, 24.0f, 18.0f};
	int nuova_dimensione = 10;
	int i;

	ordinare_vettore(B);
	fondere_vettori(A, B);

	printf("\nIl vettore ottenuto dalla fusione dei due vettori A e B e che mantiene l'ordine crescente degli elementi è:\n");
	i = 0;
	while (i < nuova_dimensione) {
		printf("%.1f ", A[i]);
		i = i + 1;
	}
	printf("\n");

	system("PAUSE");
	return 0;
}

void ordinare_vettore(float B[]) {
	int m = 4; //dimensione di B
	int j; //individua le posizioni degli elementi di B
	float temp; //variabile utile a memorizzare il valore da ordinare
	int ordinato; //indica se il vettore contenente i valori di A e di B è ordinato o meno

	ordinato = 0;
	j = 0;
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

void fondere_vettori(float A[], float B[]) {
	int n = 6; //dimensione di A
	int m = 4; //dimensione di B
	int nuova_dimensione = m + n;
	int i; //individua le posizioni degli elementi di A
	int j; //individua le posizioni degli elementi di B
	float temp; //variabile utile a memorizzare il valore da ordinare
	int ordinato; //indica se il vettore contenente i valori di A e di B è ordinato o meno

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
			i = 0;
			ordinato = 1;
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







