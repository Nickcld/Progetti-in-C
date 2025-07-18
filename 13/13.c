/*Realizzare le operazioni di somma, e prodotto di 2 matrici, trasposta di una matrice e prodotto scalare di una matrice con uno scalare.
La matrice deve essere realizzata con un vettore statico a 2 dimensioni.*/


#include <stdio.h>
#include <stdlib.h>
#define RIGHE 3
#define COLONNE 3


//PROTOTIPI DELLE FUNZIONI
void somma_matrici(int matrice_1[RIGHE][COLONNE], int matrice_2[RIGHE][COLONNE], int matrice_somma[RIGHE][COLONNE]);
void prodotto_matrici(int matrice_1[RIGHE][COLONNE], int matrice_2[RIGHE][COLONNE], int matrice_prodotto[RIGHE][COLONNE]);
void trasposta_matrice(int matrice_1[RIGHE][COLONNE], int matrice_trasposta[RIGHE][COLONNE]);
void prodotto_scalare_matrice(int matrice_1[RIGHE][COLONNE], int matrice_prodotto_scalare[RIGHE][COLONNE], int scalare);
void stampare_matrice(const char* nome, int matrice[RIGHE][COLONNE]);

//FUNZIONE MAIN
int main() {

	int matrice_1[3][3] = {
			{1, 2, 3},
			{4, 5, 6},
			{7, 8, 9}
	};

	int matrice_2[3][3] = {
			{9, 8, 7},
			{6, 5, 4},
			{3, 2, 1}
	};

	int matrice_somma[RIGHE][COLONNE];
	int matrice_prodotto[RIGHE][COLONNE];
	int matrice_trasposta[RIGHE][COLONNE];
	int matrice_prodotto_scalare[RIGHE][COLONNE];
    int scalare = 10;

    somma_matrici(matrice_1, matrice_2, matrice_somma);
    prodotto_matrici(matrice_1, matrice_2, matrice_prodotto);
    trasposta_matrice(matrice_1, matrice_trasposta);
    prodotto_scalare_matrice(matrice_1, matrice_prodotto_scalare, scalare);

    stampare_matrice("Somma", matrice_somma);
    stampare_matrice("Prodotto", matrice_prodotto);
    stampare_matrice("Trasposta", matrice_trasposta);
    stampare_matrice("Prodotto scalare", matrice_prodotto_scalare);


	system("PAUSE");
	return 0;
}

//FUNZIONI SECONDARIE DA RICHIAMARE NEL MAIN (FUNZIONI PER OPERAZIONI SU MATRICI + FUNZIONE DI STAMPA)
void somma_matrici(int matrice_1[RIGHE][COLONNE], int matrice_2[RIGHE][COLONNE], int matrice_somma[RIGHE][COLONNE]) {
	int i; //individua le righe della matrice
	int j; //individua le colonne della matrice

	i = 0;
	while (i <= RIGHE - 1) {
		j = 0;
		while (j <= COLONNE - 1) {
			matrice_somma[i][j] = matrice_1[i][j] + matrice_2[i][j];
			j = j + 1;
		}
	    i = i + 1;
	}
return;
}

void prodotto_matrici(int matrice_1[RIGHE][COLONNE], int matrice_2[RIGHE][COLONNE], int matrice_prodotto[RIGHE][COLONNE]) {
	int i; //individua le righe di matrice_1
	int j; //individua le colonne di matrice_2
	int k; //scorre contemporaneamente la riga di matrice_1 e la colonna di matrice_2
	int val; //valore temporaneo per l'accumulo del prodotto scalare

	i = 0;
	while (i <= RIGHE - 1) {
		j = 0;
		while (j <= COLONNE - 1) {
			val = 0;
			k = 0;
			while (k <= COLONNE - 1) {
				val = val + matrice_1[i][k] * matrice_2[k][j];
				k = k + 1;
			}
            matrice_prodotto[i][j] = val;
            j = j + 1;
		}
	    i = i + 1;
	}
return;
}

void trasposta_matrice(int matrice_1[RIGHE][COLONNE], int matrice_trasposta[RIGHE][COLONNE]) {
	int i; //individua le righe della matrice
	int j; //individua le colonne della matrice

	i = 0;
    while (i <= COLONNE - 1) {
    	j = 0;
    	while (j <= RIGHE - 1) {
    		matrice_trasposta[i][j] = matrice_1[j][i];
    		j = j + 1;
    	}
        i = i + 1;
    }
return;
}

void prodotto_scalare_matrice(int matrice_1[RIGHE][COLONNE], int matrice_prodotto_scalare[RIGHE][COLONNE], int scalare) {
	int i; //individua le righe della matrice
	int j; //individua le colonne della matrice

	i = 0;
	while (i <= RIGHE - 1) {
		j = 0;
		while (j <= COLONNE - 1) {
			matrice_prodotto_scalare[i][j] = matrice_1[i][j] * scalare;
			j = j + 1;
		}
	    i = i + 1;
	}
return;
}

void stampare_matrice(const char* nome, int matrice[RIGHE][COLONNE]) {
	int i;
	int j;
	i = 0;
	printf("%s:\n", nome);
	while (i < RIGHE) {
		j = 0;
		while (j < COLONNE) {
			printf("%4d ", matrice[i][j]);
		    j = j + 1;
		}
	    printf("\n");
		i = i + 1;
	}
	printf("\n---------------------------\n\n");
return;
}






