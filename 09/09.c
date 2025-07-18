/*Realizzare una funzione che riceve come parametro di input una matrice di n righe ed m colonne di numeri interi casuali compresi tra 0 e 20 e
individua la colonna in cui la massima differenza (in valore assoluto) tra due elementi consecutivi sia minima. Esempio:
Consideriamo la seguente matrice costituita da n = 4 righe ed m = 3 colonne:
A=
15 13 7
 6 18 4
11 4 12
13 9 5
La massima differenza tra gli elementi consecutivi della prima colonna è 9 = 15−6; per la seconda colonna è 14 = 18−4;
per la terza è 8 = |4−12|. Quindi il programma deve stampare la terza colonna la cui massima differenza è minima.*/

#include <stdio.h>
#include <stdlib.h>
#define RIGHE 3
#define COLONNE 3

int valore_assoluto(int n);
int individuare_minima(int matrice[RIGHE][COLONNE]);
void stampare_colonna(int matrice[RIGHE][COLONNE]);


int main() {

	int matrice[3][3] = {
			{7, 12, 1},
			{19, 4, 6},
			{8, 3, 20}
	};


	stampare_colonna(matrice);


	system("PAUSE");
	return 0;
}

int valore_assoluto(int n) {
	int n_val_assoluto = 0;
	if (n < 0) {
		n_val_assoluto = n_val_assoluto + n * (-1);
	} else {
		n_val_assoluto = n;
	}
return n_val_assoluto;
}

int individuare_minima(int matrice[RIGHE][COLONNE]) {
	int i;
	int j;
	int max_diff;
	int prima_colonna;
	int minima;
	int indice_colonna_minima;

	indice_colonna_minima = 0;
	j = 0;
	max_diff = 0;
	minima = max_diff;
	prima_colonna = 1;
	while (j <= COLONNE - 1) {
		i = 0;
		max_diff = 0;
		while (i < RIGHE - 1) {
			if (valore_assoluto(matrice[i][j] - matrice[i+1][j]) > max_diff) {
				max_diff = valore_assoluto(matrice[i][j] - matrice[i+1][j]);
			}
		i = i + 1;
		}
		if (prima_colonna == 1) {
			minima = max_diff;
			indice_colonna_minima = j;
			prima_colonna = 0;

		} else {
			if (max_diff < minima) {
				minima = max_diff;
				indice_colonna_minima = j;
			}
		}
	j = j + 1;
	}
printf("\n La colonna in cui la massima differenza (in valore assoluto) tra due elementi consecutivi è minima è la colonna n.%d con minima = %d\n", indice_colonna_minima + 1, minima);

return indice_colonna_minima;
}

void stampare_colonna(int matrice[RIGHE][COLONNE]) {
	 int indice_colonna_minima = individuare_minima(matrice);

	int i = 0;
	while (i <= RIGHE - 1) {
		printf("%d\n", matrice[i][indice_colonna_minima]);
		i = i + 1;
	}
return;
}








