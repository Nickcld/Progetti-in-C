/*Scrivere una funzione che, dato un vettore di numeri interi, individua e restituisce la lunghezza del più lungo "altopiano", definito
come una sequenza di elementi identici e consecutivi.
Esempio: V = [1, 2, 2, 2, 4, 4, 2, 5] -> La funzione deve restituire 3 (la sequenza 2, 2, 2).*/

#include <stdio.h>
#include <stdlib.h>


int trovare_altopiano_massimo(int vettore[], int dimensione);

int main() {

	int vettore[10] = {3, 3, 3, 3, 5, 9, 8, 8, 1, 7};
	int dimensione = 10;

	int lunghezza_max = trovare_altopiano_massimo(vettore, dimensione);

	printf("\nL'altopiano più lungo presente nella sequenza ha lunghezza %d.\n", lunghezza_max);


	system("PAUSE");
	return 0;
}

int trovare_altopiano_massimo(int vettore[], int dimensione) {
	int i;
	int lunghezza_corrente;
	int lunghezza_max;

	if (dimensione == 0) {
		lunghezza_max = 0;
	}
	lunghezza_max = 1;
	lunghezza_corrente = 1;
	i = 1;
	while (i < dimensione) {
		if (vettore[i] == vettore[i-1]) {
			lunghezza_corrente = lunghezza_corrente + 1;
		} else if (lunghezza_corrente > lunghezza_max) {
			lunghezza_max = lunghezza_corrente;
			lunghezza_corrente = 1;
		}
	    i = i + 1;
	}
	if (lunghezza_corrente > lunghezza_max) {
		lunghezza_max = lunghezza_corrente;
	}
return lunghezza_max;
}

