/*Realizzare le operazioni di somma di 2 matrici e prodotto scalare di una matrice per un numero reale.*/

#include <stdio.h>
#include <stdlib.h>

#define RIGHE 3
#define COLONNE 3

typedef struct {
	int righe;
	int colonne;
	int *valori;
} Matrice;

// Prototipi delle funzioni

/**** Funzioni d'accesso alla struttura Matrice ****/
int matrice_righe_leggere(Matrice matrice);
int matrice_colonne_leggere(Matrice matrice);
int matrice_valore_leggere(Matrice matrice, int posizione_riga, int posizione_colonna);
void matrice_righe_scrivere(Matrice *matrice, int valore);
void matrice_colonne_scrivere(Matrice *matrice, int valore);
void matrice_valori_scrivere(Matrice *matrice, int valore, int posizione_riga, int posizione_colonna);
void matrice_valori_stampa(Matrice *matrice);

/**** Funzioni delle operazioni sulle matrici ****/
void matrice_operazione_somma(Matrice matrice_1, Matrice matrice_2, Matrice *matrice_somma);
void matrice_operazione_prodottoscalare(Matrice matrice, int base, Matrice *matrice_prodotto_scalare);


// Funzione main

int main() {

    int base;
    // Dichiarazione di tutte le matrici
    Matrice matrice_1;
    Matrice matrice_2;
    Matrice matrice_somma;
    Matrice matrice_prodotto_scalare;

    // Allocazione dinamica di matrice.valori
    matrice_1.valori = (int*)malloc(RIGHE * COLONNE * sizeof(int));
    matrice_2.valori = (int*)malloc(RIGHE * COLONNE * sizeof(int));
    matrice_somma.valori = (int*)malloc(RIGHE * COLONNE * sizeof(int));
    matrice_prodotto_scalare.valori = (int*)malloc(RIGHE * COLONNE * sizeof(int));

    // Allocazione dei valori di righe e colonne alle matrici
    matrice_righe_scrivere(&matrice_somma, RIGHE);
    matrice_colonne_scrivere(&matrice_somma, COLONNE);
    matrice_righe_scrivere(&matrice_prodotto_scalare, RIGHE);
    matrice_colonne_scrivere(&matrice_prodotto_scalare, COLONNE);

    // Scrittura degli elementi di matrice_1
    matrice_righe_scrivere(&matrice_1, 3);
    matrice_colonne_scrivere(&matrice_1, 3);

    matrice_valori_scrivere(&matrice_1, 1, 0, 0);
    matrice_valori_scrivere(&matrice_1, 2, 0, 1);
    matrice_valori_scrivere(&matrice_1, 3, 0, 2);
    matrice_valori_scrivere(&matrice_1, 4, 1, 0);
    matrice_valori_scrivere(&matrice_1, 5, 1, 1);
    matrice_valori_scrivere(&matrice_1, 6, 1, 2);
    matrice_valori_scrivere(&matrice_1, 7, 2, 0);
    matrice_valori_scrivere(&matrice_1, 8, 2, 1);
    matrice_valori_scrivere(&matrice_1, 9, 2, 2);

    // Scrittura degli elementi di matrice_2
    matrice_righe_scrivere(&matrice_2, 3);
    matrice_colonne_scrivere(&matrice_2, 3);

    matrice_valori_scrivere(&matrice_2, 1, 0, 0);
    matrice_valori_scrivere(&matrice_2, 2, 0, 1);
	matrice_valori_scrivere(&matrice_2, 3, 0, 2);
	matrice_valori_scrivere(&matrice_2, 4, 1, 0);
	matrice_valori_scrivere(&matrice_2, 5, 1, 1);
	matrice_valori_scrivere(&matrice_2, 6, 1, 2);
	matrice_valori_scrivere(&matrice_2, 7, 2, 0);
	matrice_valori_scrivere(&matrice_2, 8, 2, 1);
	matrice_valori_scrivere(&matrice_2, 9, 2, 2);

	// Chiamata delle funzioni di operazioni
	base = 5;
	matrice_operazione_somma(matrice_1, matrice_2, &matrice_somma);
	matrice_operazione_prodottoscalare(matrice_1, base, &matrice_prodotto_scalare);

	// Stampa delle matrici
	printf("\n Matrice 1:\n");
	matrice_valori_stampa(&matrice_1);
	printf("\n");

	printf("\n Matrice 2:\n");
	matrice_valori_stampa(&matrice_2);
	printf("\n");

	printf("\n Somma delle due matrici:\n");
	matrice_valori_stampa(&matrice_somma);
	printf("\n");

	printf("\n Prodotto Scalare di Matrice 1:\n");
	matrice_valori_stampa(&matrice_prodotto_scalare);
	printf("\n");


	free(matrice_1.valori);
	free(matrice_2.valori);
	free(matrice_somma.valori);
	free(matrice_prodotto_scalare.valori);

    system("PAUSE");
	return 0;
}

// Definizione di tutte le funzioni

/**** Definizione delle funzioni d'accesso alla struttura Matrice ****/
int matrice_righe_leggere(Matrice matrice) {
	return matrice.righe;
}

int matrice_colonne_leggere(Matrice matrice) {
	return matrice.colonne;
}

int matrice_valore_leggere(Matrice matrice, int posizione_riga, int posizione_colonna) {
	int valore = matrice.valori[posizione_riga * COLONNE + posizione_colonna];
	return valore;
}

void matrice_righe_scrivere(Matrice *matrice, int valore) {
	matrice->righe = valore;
	return;
}

void matrice_colonne_scrivere(Matrice *matrice, int valore) {
	matrice->colonne = valore;
	return;
}

void matrice_valori_scrivere(Matrice *matrice, int valore, int posizione_riga, int posizione_colonna) {
	matrice->valori[posizione_riga * COLONNE + posizione_colonna] = valore;
}

void matrice_valori_stampa(Matrice *matrice) {
	int posizione_riga = 0;
	while(posizione_riga < RIGHE) {
		int posizione_colonna = 0;
		while(posizione_colonna < COLONNE) {
			int valore_da_stampare = matrice->valori[posizione_riga * COLONNE + posizione_colonna];
			printf("%d ", valore_da_stampare);
			posizione_colonna = posizione_colonna + 1;
		}
	printf("\n");
	posizione_riga = posizione_riga + 1;
	}
return;
}

/**** Definizione delle funzioni per operare sulle matrici ****/
void matrice_operazione_somma(Matrice matrice_1, Matrice matrice_2, Matrice *matrice_somma) {
	int posizione_riga;
	int posizione_colonna;
	int valore;

	posizione_riga = 0;
	while(posizione_riga < RIGHE) {
		posizione_colonna = 0;
		while(posizione_colonna < COLONNE) {
			valore = matrice_valore_leggere(matrice_1, posizione_riga, posizione_colonna) + matrice_valore_leggere(matrice_2, posizione_riga, posizione_colonna);
			matrice_valori_scrivere(matrice_somma, valore, posizione_riga, posizione_colonna);
			posizione_colonna = posizione_colonna + 1;
		}
	posizione_riga = posizione_riga + 1;
	}
return;
}

void matrice_operazione_prodottoscalare(Matrice matrice, int base, Matrice *matrice_prodotto_scalare) {
	int posizione_riga;
	int posizione_colonna;
	int valore;

	posizione_riga = 0;
	while(posizione_riga < RIGHE) {
			posizione_colonna = 0;
			while(posizione_colonna < COLONNE) {
				valore = matrice_valore_leggere(matrice, posizione_riga, posizione_colonna);
				matrice_valori_scrivere(matrice_prodotto_scalare, valore * base, posizione_riga, posizione_colonna);
				posizione_colonna = posizione_colonna + 1;
			}
		posizione_riga = posizione_riga + 1;
		}
	return;
}







