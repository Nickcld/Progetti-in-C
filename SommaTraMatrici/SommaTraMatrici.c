#include <stdio.h>
#include <stdlib.h>
#define RIGHE 3
#define COLONNE 3


typedef struct{
	int righe;
	int colonne;
	int *valori;
} Matrice;

//Funzioni di accesso alla matrice (lettura, scrittura e stampa dei valori)

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
}

void matrice_colonne_scrivere(Matrice *matrice, int valore) {
	matrice->colonne = valore;
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
}

//Inizializzazione delle funzioni

int matrice_righe_leggere(Matrice matrice);
int matrice_colonne_leggere(Matrice matrice);
int matrice_valore_leggere(Matrice matrice, int posizione_riga, int posizione_colonna);

void matrice_righe_scrivere(Matrice *matrice, int valore);
void matrice_colonne_scrivere(Matrice *matrice, int valore);
void matrice_valori_scrivere(Matrice *matrice, int valore, int posizione_riga, int posizione_colonna);
void matrice_valori_stampa(Matrice *matrice);


void matrice_operazione_somma(Matrice matrice_1, Matrice matrice_2, Matrice *matrice_somma);

//Funzione per sommare le due matrici

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
}


int main() {

	//Dichiarazione delle matrici

	Matrice matrice_1;
	Matrice matrice_2;
	Matrice matrice_somma;


	//Allocazione dinamica di matrice.valori

	matrice_1.valori = (int*)malloc(RIGHE * COLONNE * sizeof(int));
	matrice_2.valori = (int*)malloc(RIGHE * COLONNE * sizeof(int));
	matrice_somma.valori = (int*)malloc(RIGHE * COLONNE * sizeof(int));


	//Allocazione dei valori di righe e colonne alla matrice

	matrice_righe_scrivere(&matrice_somma, RIGHE);
	matrice_colonne_scrivere(&matrice_somma, COLONNE);


	//Scrittura degli elementi di matrice 1

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

	//Scrittura degli elementi di matrice 2

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


	//Inizializzazione della funzione somma

		matrice_operazione_somma(matrice_1, matrice_2, &matrice_somma);


	//Stampa delle matrici

		printf("Matrice 1: \n");
		matrice_valori_stampa(&matrice_1);
		printf("\n");

		printf("Matrice 2: \n");
		matrice_valori_stampa(&matrice_2);
		printf("\n");

	    printf("Somma tra le due matrici: \n");
	    matrice_valori_stampa(&matrice_somma);
	    printf("\n");




	system("PAUSE");
	return 0;
}













