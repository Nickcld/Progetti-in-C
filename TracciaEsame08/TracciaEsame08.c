/*Realizzare una funzione che riceve come parametro di input una matrice di numeri interi minori
di 10 e individua le righe che contengono tre elementi consecutivi che abbiano valori
successivi.*/

#include <stdio.h>
#include <stdlib.h>
#define VERO 1
#define FALSO 0
#define RIGHE 3
#define COLONNE 3

int is_Successivo(int NUM1, int NUM2);
int is_Consecutivo(int NUM1, int NUM2);
int Verifica_PrimaRiga(int Matrice[RIGHE][COLONNE], int riga);
int Verifica_SecondaRiga(int Matrice[RIGHE][COLONNE], int riga);
int Verifica_TerzaRiga(int Matrice[RIGHE][COLONNE], int riga);

int main() {

	int Matrice[3][3] = {
			{1, 6, 8},
			{3, 4, 5},
			{7, 2, 9}
	};

	int riga;
	if(Verifica_PrimaRiga(Matrice, riga) == VERO) {
		printf("\n La prima riga contiene tre elementi consecutivi successivi: %d %d %d\n", Matrice[0][0], Matrice[0][1], Matrice[0][2]);
	}

	if(Verifica_SecondaRiga(Matrice, riga) == VERO) {
			printf("\n La seconda riga contiene tre elementi consecutivi successivi: %d %d %d\n", Matrice[1][0], Matrice[1][1], Matrice[1][2]);
	}

	if(Verifica_TerzaRiga(Matrice, riga) == VERO) {
			printf("\n La terza riga contiene tre elementi consecutivi successivi: %d %d %d\n", Matrice[2][0], Matrice[2][1], Matrice[2][2]);
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


int Verifica_PrimaRiga(int Matrice[RIGHE][COLONNE], int riga) {
	riga = 0;
	int colonna = 0;
	while(colonna < COLONNE) {
		if(is_Successivo(Matrice[riga][colonna], Matrice[riga][colonna+1]) && is_Consecutivo(Matrice[riga][colonna], Matrice[riga][colonna+1])) {
			return VERO;
		}
	colonna = colonna + 1;
	}
  return FALSO;
}

int Verifica_SecondaRiga(int Matrice[RIGHE][COLONNE], int riga) {
	riga = 1;
	int colonna = 0;
	while(colonna < COLONNE) {
		if(is_Successivo(Matrice[riga][colonna], Matrice[riga][colonna+1]) && is_Consecutivo(Matrice[riga][colonna], Matrice[riga][colonna+1])) {
			return VERO;
		}
	colonna = colonna + 1;
	}
  return FALSO;
}

int Verifica_TerzaRiga(int Matrice[RIGHE][COLONNE], int riga) {
	riga = 2;
	int colonna = 0;
	while(colonna < COLONNE) {
		if(is_Successivo(Matrice[riga][colonna], Matrice[riga][colonna+1]) && is_Consecutivo(Matrice[riga][colonna], Matrice[riga][colonna+1])) {
			return VERO;
		}
	colonna = colonna + 1;
	}
  return FALSO;
}

