/*Realizzare un programma che, ricevuto come parametro di input un vettore di interi, lo ordini in modo tale che i numeri multipli di 3
vengano disposti in fondo al vettore.*/

#include <stdio.h>
#include <stdlib.h>

int multiplo_di_3(int num);
void riordinare_vettore(int vettore[], int dimensione);


int main() {

	int *vettore;
	int dimensione;
    int i;

    printf("\nQuanti numeri vuoi inserire?\n");
    scanf ("%d", &dimensione);

    //allocazione dinamica del vettore
    vettore = (int*) malloc(dimensione * sizeof(int));

	printf("\nInserisci un elenco di %d numeri ed io sposterò a destra tutti i numeri multipli di 3.\n", dimensione);
	 i = 0;
	while (i < dimensione) {
		scanf("%d", &vettore[i]);
		i = i + 1;
	}
	riordinare_vettore(vettore, dimensione);
	printf("\nEcco l'elenco con i multipli di 3 spostati in fondo:\n");
	i = 0;
	while (i < dimensione) {
		printf("%d ", vettore[i]);
		i = i + 1;
	}
    printf("\n");

    free(vettore);
	system("PAUSE");
	return 0;
}

int multiplo_di_3(int num) {
	int esito;

	if (num < 0) {
		num = - num;
	}
	while (num > 0) {
		num = num - 3;
	}
	if (num == 0) {
		esito = 1;
	} else {
		esito = 0;
	}
	return esito;
}

void riordinare_vettore(int vettore[], int dimensione) {
	int i;
	int j;
	int temp;

	i = 0;
	j = dimensione - 1;
	while (i < j) {
		while (i < j && multiplo_di_3(vettore[i]) == 0) {
			i = i + 1;
		}
		while (i < j && multiplo_di_3(vettore[j]) == 1) {
			j = j - 1;
		}
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








