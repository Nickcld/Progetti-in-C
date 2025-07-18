/*Scrivere una funzione che riceve in input un array di numeri interi A e verifica se gli elementi formano una sequenza alternata di pari e
dispari (es. pari, dispari, pari, dispari...) oppure viceversa. Restituisce 1 se la condizione è rispettata, 0 altrimenti.*/

#include <stdio.h>
#include <stdlib.h>
#define DIMENSIONE 10


int pari(int n);
int verificare_alternanza(int vettore[DIMENSIONE]);

int main() {

	int vettore[10] = {7, 4, 11, 8, 13, 20, 17, 2, 5, 11};
	if (verificare_alternanza(vettore) == 1) {
		printf("\nLa serie è alternata.\n");
	} else {
		printf("\nLa serie non è alternata.\n");
	}

	system("PAUSE");
	return 0;
}

int pari(int n) {
	int esito;
	if (n < 0) {
		n = - n;
	}
	while (n > 0) {
		n = n - 2;
	}
	if (n == 0) {
		esito = 1;
	} else {
		esito = 0;
	}
return esito;
}

int verificare_alternanza(int vettore[DIMENSIONE]) {
	int i;
	int esito;

	i = 0;
	esito = 1;
	while (i < DIMENSIONE - 1 && esito == 1) {
		if (pari(vettore[i]) == 1 && pari(vettore[i + 1]) == 1) {
			esito = 0;
		}
		if (pari(vettore[i]) == 0 && pari(vettore[i + 1]) == 0) {
			esito = 0;
	    }
	    i = i + 1;
	}
return esito;
}






