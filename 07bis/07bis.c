/*Realizzare un programma che verifichi se una matrice è un quadrato magico o meno.*/

#include <stdio.h>
#include <stdlib.h>
#define RIGHE 3
#define COLONNE 3

int confrontare_somme_righe(int matrice[RIGHE][COLONNE]);
int confrontare_somme_colonne(int matrice[RIGHE][COLONNE]);
int confrontare_somme_diagonali(int matrice[RIGHE][COLONNE]);
void verificare_quadrato_magico(int matrice[RIGHE][COLONNE]);


int main() {

	int matrice[RIGHE][COLONNE] = {
			{8, 1, 6},
			{3, 5, 7},
			{4, 9, 2}
	};


	verificare_quadrato_magico(matrice);

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
	somma_riferimento = 0;
	esito = 1;
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
	somma_riferimento = 0;
	esito = 1;
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
	int esito;
	int somma_riferimento;
	int somma_secondaria;

	i = 0;
	j = 0;
	somma_riferimento = 0;
	esito = 1;
	while (i < RIGHE && j < COLONNE) {
		somma_riferimento = somma_riferimento + matrice[i][j];
		i = i + 1;
		j = j + 1;
	}
	i = 0;
	j = COLONNE - 1;
	somma_secondaria = 0;
	while (i < RIGHE && j >= 0) {
		somma_secondaria = somma_secondaria + matrice[i][j];
		i = i + 1;
		j = j - 1;
	}
	if (somma_secondaria != somma_riferimento) {
		esito = 0;
	}
	return esito;
}

void verificare_quadrato_magico(int matrice[RIGHE][COLONNE]) {
	if (confrontare_somme_righe(matrice) == 1 && confrontare_somme_colonne(matrice) == 1 && confrontare_somme_diagonali(matrice) == 1) {
		printf("\nLa matrice è un quadrato magico.\n");
	} else {
		printf("\nLa matrice NON è un quadrato magico.\n");
	}
	return;
}






