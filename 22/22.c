/*Scrivere una funzione che, preso in input un vettore di numeri interi, lo modifichi (senza creare un vettore di appoggio) in modo che tutti
i numeri pari precedano tutti i numeri dispari. L'ordine relativo tra i numeri pari non è importante, così come non è importante l'ordine
relativo tra i numeri dispari.
Esempio: Se il vettore in input è V = [3, 5, 2, 8, 1, 4, 7], un possibile risultato dopo l'esecuzione della procedura è:
V = [4, 8, 2, 5, 1, 3, 7].*/

#include <stdio.h>
#include <stdlib.h>

int pari(int num);
void ordinare_vettore(int vettore[], int dimensione);

int main() {

	int vettore[10];
	int dimensione = 10;

	printf("\nInserisci un elenco di 10 numeri e li riordinerò mettendo quelli pari prima di quelli dispari.\n");
	int i = 0;
	while(i < dimensione) {
		scanf("%d", &vettore[i]);
		i = i + 1;
	}

	ordinare_vettore(vettore, dimensione);
	printf("\nEcco l'elenco ordinato in modo tale che i pari precedano i dispari:\n");
	i = 0;
	while(i < dimensione) {
		printf("%d ", vettore[i]);
		i = i + 1;
	}
    printf("\n");

	system("PAUSE");
	return 0;
}


int pari(int num) {
	int esito;
	if (num < 0) {
		num = - num;
	}
	while (num > 0) {
		num = num - 2;
	}
	if (num == 0) {
		esito = 1;
	} else {
		esito = 0;
	}
    return esito;
}

void ordinare_vettore(int vettore[], int dimensione) {
	int i = 0;
	int j = dimensione - 1;
	int temp;

	while (i < j) {
		// Vai avanti finché trovi numeri pari
		while (i < j && pari(vettore[i]) == 1) {
			i =  i + 1;
		}
		// Vai indietro finché trovi numeri dispari
		while (i < j && pari(vettore[j]) == 0) {
			j = j - 1;
		}
		// Se hai trovato una coppia da scambiare
		if (i < j) {
			temp = vettore[i];
			vettore[i] = vettore[j];
			vettore[j] = temp;
			i = i + 1;
			j = j - 1;
		}
	}
    return;
}







