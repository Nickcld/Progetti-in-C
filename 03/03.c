/*Realizzare una funzione che riceve come parametro di input un array di n numeri interi ed un intero k>1, ed elimina dall’array tutti i
  multipli di k, spostando “a sinistra” gli elementi successivi.*/


#include <stdio.h>
#include <stdlib.h>

int verificare_multiplo(int n1, int n2);
int eliminare_multipli(int vettore[], int dimensione, int k);

int main() {
	int k = 5;
	int vettore[10];
	int dimensione = 10;
	printf("\n Inserisci un elenco di 10 numeri ed io eliminerò i multipli di %d\n", k);
	int i = 0;
	while (i <= dimensione - 1) {
		scanf("%d", &vettore[i]);
		i = i + 1;
	}

	printf("\n Ecco l'elenco privo dei multipli di %d:\n", k);
	int eliminati = eliminare_multipli(vettore, dimensione, k);
	dimensione = dimensione - eliminati;
	i = 0;
	while (i <= dimensione - 1) {
		printf("%d ", vettore[i]);
		i = i + 1;
	}


	system("PAUSE");
	return 0;
}

int verificare_multiplo(int n1, int n2) {

	int esito;

	while (n1 > 0) {
		n1 = n1 - n2;
	}
	if (n1 == 0) {
		esito = 1;
	} else {
		esito = 0;
	}
return esito;
}


int eliminare_multipli(int vettore[], int dimensione, int k) {
	int i;
	int temp;
	int eliminati;

	eliminati = 0;
	i = 0;
	while (i <= dimensione - 1) {
		if (verificare_multiplo(vettore[i], k) == 1) {
			temp = i;
			while (temp < dimensione - 1) {
				vettore[temp] = vettore[temp + 1];
				temp = temp + 1;
			}
		    dimensione = dimensione - 1;
		    eliminati = eliminati + 1;
		} else {
			i = i + 1;
		}
	}
return eliminati;
}








