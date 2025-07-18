/*Realizzare una funzione che riceve come parametro di input una matrice quadrata di interi positivi e verifica se ogni riga ha una somma
maggiore o uguale alla somma della riga precedente. La funzione restituisce 1 se la condizione è soddisfatta per tutte le righe, 0 altrimenti.*/


#include <stdio.h>
#include <stdlib.h>
#define RIGHE 3
#define COLONNE 3

int verificare_crescita_righe(int matrice[RIGHE][COLONNE]);

int main() {

	int matrice[3][3] = {
			{1, 2, 3},
			{4, 5, 6},
			{7, 8, 9}
	};


	if (verificare_crescita_righe(matrice)) {
		printf("\nLa somma degli elementi delle righe della matrice è crescente.\n");
	} else {
		printf("\nLa somma degli elementi delle righe della matrice non è crescente.\n");
	}



	system("PAUSE");
	return 0;
}


int verificare_crescita_righe(int matrice[RIGHE][COLONNE]) {
	int i;
	int j;
	int somma_riga_corrente;
	int somma_max;
	int esito;

	i = 0;
	esito = 1;
	j = 0;
	somma_max = 0;
	while (j < COLONNE) {
		somma_max = somma_max + matrice[i][j];
		j = j + 1;
	}
	i = i + 1;
	while (i < RIGHE && esito == 1) {
		somma_riga_corrente = 0;
		j = 0;
		while (j < COLONNE) {
			somma_riga_corrente = somma_riga_corrente + matrice[i][j];
			j = j + 1;
		}
	    if (somma_riga_corrente > somma_max) {
	    	somma_max = somma_riga_corrente;
	    } else {
	    	esito = 0;
	    }
	    i = i + 1;
	}
return esito;
}
