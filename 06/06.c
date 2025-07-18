/*Realizzare una funzione che riceve come parametro di input una matrice di numeri interi minori di 10 e individua le colonne che contengono
tre elementi consecutivi che abbiano valori successivi.*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 2
#define NESSUNA_COLONNA 0
#define RIGHE 3
#define COLONNE 3

int consecutivi_successivi(int elenco[], int dimensione);
int individuare_colonna(int matrice[RIGHE][COLONNE]);


int main() {

	int matrice[3][3] = {
			{2, 5, 1},
			{0, 6, 8},
			{4, 7, 9}
	};

	int colonna_trovata;
	int i;
	colonna_trovata = individuare_colonna(matrice);
	printf("\nLa colonna contenente tre elementi consecutivi successivi è la colonna n.%d:\n", colonna_trovata + 1);
	i = 0;
	while(i < RIGHE) {
		printf("%d\n", matrice[i][colonna_trovata]);
		i = i + 1;
	}
	printf("\n");



	system("PAUSE");
	return 0;
}

int consecutivi_successivi(int elenco[], int dimensione) {
	int i;
	int successivi;
	int esito;

	i = 0;
	successivi = 0;
	esito = 0;
	while (i < dimensione - 1 && esito == 0) {
		if (elenco[i] == elenco[i+1] - 1) {
			successivi = successivi + 1;
			if (successivi == MAX) {
				esito = 1;
			}
		} else {
			successivi = 0;
		}
	    i = i + 1;
	}
    return esito;
}

int individuare_colonna(int matrice[RIGHE][COLONNE]) {
	int i;
	int j;
	int colonna_corrente[3];
	int colonna_trovata;

	colonna_trovata = NESSUNA_COLONNA;
	j = 0;
	while (j < COLONNE && colonna_trovata == NESSUNA_COLONNA) {
		i = 0;
		while (i < RIGHE) {
			colonna_corrente[i] = matrice[i][j];
			i = i + 1;
		}
		if (consecutivi_successivi(colonna_corrente, RIGHE) == 1) {
			colonna_trovata = j;
		}
	    j = j + 1;
	}
	return colonna_trovata;
}









