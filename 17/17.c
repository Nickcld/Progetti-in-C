/*Realizzare una funzione che riceve come parametro di input una matrice di numeri interi minori di 10 e individua le righe che contengono
tre elementi consecutivi che abbiano valori successivi.*/


#include <stdio.h>
#include <stdlib.h>
#define MAX 2
#define NESSUNA_RIGA 0
#define RIGHE 3
#define COLONNE 3

int consecutivi_successivi(int elenco[], int dimensione);
int individuare_righe(int matrice[RIGHE][COLONNE]);
void stampare_riga(int matrice[RIGHE][COLONNE]);

int main() {

	int matrice[RIGHE][COLONNE] = {
		{3, 9, 2},
		{7, 4, 6},
		{1, 2, 3}
	};

	stampare_riga(matrice);

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
	    if (elenco[i + 1] == elenco[i] + 1) {
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

int individuare_righe(int matrice[RIGHE][COLONNE]) {
	int i;
	int j;
	int riga_corrente[COLONNE];
	int riga_trovata;

	i = 0;
	riga_trovata = NESSUNA_RIGA;
	while (i < RIGHE) {
		j = 0;
		while (j < COLONNE) {
			riga_corrente[j] = matrice[i][j];
			j = j + 1;
		}
	    if (consecutivi_successivi(riga_corrente, COLONNE) == 1) {
	    	riga_trovata = i;
	    }
	    i = i + 1;
	}
	return riga_trovata;
}

void stampare_riga(int matrice[RIGHE][COLONNE]) {
	int riga_trovata = individuare_righe(matrice);
	int j;

	printf("\nLa riga della matrice contenente tre valori consecutivi successivi è la riga n.%d:\n", riga_trovata + 1);
	j = 0;
	while (j < COLONNE) {
		printf("%d ", matrice[riga_trovata][j]);
		j = j + 1;
	}
	printf("\n");
}





