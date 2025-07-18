/*Realizzare una funzione che riceve come parametro di input una matrice di numeri interi minori
di 10 e individua le colonne che contengono tre elementi consecutivi che abbiano valori
successivi.*/

#include <stdio.h>
#include <stdlib.h>
#define RIGHE 3
#define COLONNE 3
#define VERO 1
#define FALSO 0

int is_Successivo(int NUM1, int NUM2);
int is_Consecutivo(int NUM1, int NUM2);
int VerificaPrimaColonna(int Matrice[RIGHE][COLONNE], int colonna);
int VerificaSecondaColonna(int Matrice[RIGHE][COLONNE], int colonna);
int VerificaTerzaColonna(int Matrice[RIGHE][COLONNE], int colonna);



int main() {

	int Matrice[3][3] = {
			{2, 4, 6},
			{7, 5, 8},
			{9, 6, 1}
	};

	int colonna;

	if(VerificaPrimaColonna(Matrice, colonna) == VERO) {
		colonna = 0;
		printf("\n La colonna n.%d contiene tre elementi consecutivi successivi: \n %d \n %d \n %d", colonna + 1, Matrice[0][colonna], Matrice[1][colonna], Matrice[2][colonna]);
	}

	if(VerificaSecondaColonna(Matrice, colonna) == VERO) {
		colonna = 1;
		printf("\n La colonna n.%d contiene tre elementi consecutivi successivi: \n %d \n %d \n %d\n", colonna + 1, Matrice[0][colonna], Matrice[1][colonna], Matrice[2][colonna]);
	}

    if(VerificaTerzaColonna(Matrice, colonna) == VERO) {
		colonna = 2;
    	printf("\n La colonna n.%d contiene tre elementi consecutivi successivi: \n %d \n %d \n %d", colonna + 1, Matrice[0][colonna], Matrice[1][colonna], Matrice[2][colonna]);
	}


	system("PAUSE");
	return 0;
}


int is_Successivo(int NUM1, int NUM2) {
	if(NUM2 > NUM1) {
		return VERO;
	}
  return FALSO;
}

int is_Consecutivo(int NUM1, int NUM2) {
	if(NUM2 == NUM1 + 1) {
		return VERO;
	}
 return FALSO;
}

int VerificaPrimaColonna(int Matrice[RIGHE][COLONNE], int colonna) {
	colonna = 0;
	int i = 0;
	while(i < RIGHE) {
		if(is_Successivo(Matrice[i][colonna], Matrice[i+1][colonna]) && is_Consecutivo(Matrice[i][colonna], Matrice[i+1][colonna])) {
			return VERO;
		}
	i = i + 1;
	}
  return FALSO;
}

int VerificaSecondaColonna(int Matrice[RIGHE][COLONNE], int colonna) {
	colonna = 1;
	int i = 0;
	while(i < RIGHE) {
		if(is_Successivo(Matrice[i][colonna], Matrice[i+1][colonna]) && is_Consecutivo(Matrice[i][colonna], Matrice[i+1][colonna])) {
			return VERO;
		}
	i = i + 1;
	}
  return FALSO;
}

int VerificaTerzaColonna(int Matrice[RIGHE][COLONNE], int colonna) {
	colonna = 2;
	int i = 0;
	while(i < RIGHE) {
		if(is_Successivo(Matrice[i][colonna], Matrice[i+1][colonna]) && is_Consecutivo(Matrice[i][colonna], Matrice[i+1][colonna])) {
			return VERO;
		}
	i = i + 1;
	}
  return FALSO;
}
