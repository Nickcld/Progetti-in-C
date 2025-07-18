/*Realizzare un programma che verifichi se una matrice è un quadrato magico o meno.*/

#include <stdio.h>
#include <stdlib.h>
#define RIGHE 4
#define COLONNE 4

int confrontare_somme_righe(int matrice[RIGHE][COLONNE]);
int confrontare_somme_colonne(int matrice[RIGHE][COLONNE]);
int confrontare_somme_diagonali(int matrice[RIGHE][COLONNE]);
int verificare_quadrato_magico(int matrice[RIGHE][COLONNE]);


int main() {

	int matrice[4][4] = {
			{0, 1, 2, 3},
			{4, 5, 6, 7},
			{8, 9, 10, 11},
			{12, 13, 14, 15}
	};

	if(verificare_quadrato_magico(matrice)) {
		printf("\nLa matrice è un quadrato magico.\n");
	} else {
		printf("\nLa matrice non è un quadrato magico.\n");
	}


	system("PAUSE");
	return 0;
}

int confrontare_somme_righe(int matrice[RIGHE][COLONNE]) {
	int i;
	int j;
	int somma_riferimento;
	int somma_valori_riga;
	int esito;

	i = 0;
	j = 0;
	esito = 1;
	somma_riferimento = 0;
	while (j < COLONNE) {
		somma_riferimento = somma_riferimento + matrice[i][j];
		j = j + 1;
	}
	i = i + 1;
	while (i < RIGHE && esito == 1) {
		j = 0;
		somma_valori_riga = 0;
		while (j < COLONNE) {
			somma_valori_riga = somma_valori_riga + matrice[i][j];
			j = j + 1;
		}
	    if (somma_valori_riga != somma_riferimento) {
	    	esito = 0;
	    }
	    i = i + 1;
	}
return esito;
}

int confrontare_somme_colonne(int matrice[RIGHE][COLONNE]) {
	int i;
	int j;
	int somma_riferimento;
	int somma_valori_colonna;
	int esito;

	i = 0;
	j = 0;
	esito = 1;
	somma_riferimento = 0;
	while (i < RIGHE) {
		somma_riferimento = somma_riferimento + matrice[i][j];
		i = i + 1;
	}
	j = j + 1;
	while (j < COLONNE && esito == 1) {
		i = 0;
		somma_valori_colonna = 0;
		while (i < RIGHE) {
			somma_valori_colonna = somma_valori_colonna + matrice[i][j];
			i = i + 1;
		}
	    if (somma_valori_colonna != somma_riferimento) {
	    	esito = 0;
	    }
	    j = j + 1;
	}
return esito;
}

int confrontare_somme_diagonali(int matrice[RIGHE][COLONNE]) {
	int i;
	int j;
	int somma_riferimento;
	int somma_valori_secondaria;
	int esito;

	i = 0;
	j = 0;
	esito = 1;
	somma_riferimento = 0;
	while (i < RIGHE && j <= COLONNE) {
		somma_riferimento = somma_riferimento + matrice[i][j];
		i = i + 1;
		j = j + 1;
	}
	i = 0;
	j = COLONNE - 1;
	somma_valori_secondaria = 0;
	while (i < RIGHE && j >= 0) {
		somma_valori_secondaria = somma_valori_secondaria + matrice[i][j];
		i = i + 1;
		j = j - 1;
	}
	if (somma_valori_secondaria != somma_riferimento) {
		esito = 0;
	}
return esito;
}

int verificare_quadrato_magico(int matrice[RIGHE][COLONNE]) {
	int esito;

	if (confrontare_somme_righe(matrice) == 1 && confrontare_somme_colonne(matrice) == 1 && confrontare_somme_diagonali(matrice) == 1) {
		esito = 1;
	} else {
		esito = 0;
	}
return esito;
}








