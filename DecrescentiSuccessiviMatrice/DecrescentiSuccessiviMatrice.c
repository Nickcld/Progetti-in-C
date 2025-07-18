/*Scrivi una funzione in C che riceve in input una matrice di numeri interi minori di 10 e individua le
colonne che contengono tre elementi consecutivi che siano in ordine strettamente decrescente
(cioè, ogni numero è più piccolo di quello sopra di lui).*/

#include <stdio.h>
#include <stdlib.h>
#define RIGHE 3
#define COLONNE 3

int main() {

	int Matrice[3][3] = {
			{1, 9, 4},
			{6, 7, 2},
			{8, 3, 5}
	};

      printf(" \nColonna con tre elementi successivi decrescenti: ");
      individua_colonne(Matrice);


	  system("PAUSE");
      return 0;
}

void individua_colonne(int Matrice[RIGHE][COLONNE]) {
	int j = 0;
	int decrescenti = 1;

	while(j < COLONNE - 1) {
		int i = 0;
		while(i < RIGHE - 1) {
			if(Matrice[i][j] > Matrice[i + 1][j]) {
				decrescenti = decrescenti + 1;
			} else {
				decrescenti = 1;
			  }
	        if(decrescenti == 3) {
	        	printf("\n Colonna %d: %d, %d, %d", j, Matrice[i-1][j], Matrice[i][j], Matrice[i+1][j]);
	        	break;
	        }

		i = i + 1;
		}
	j = j + 1;
	}
}
