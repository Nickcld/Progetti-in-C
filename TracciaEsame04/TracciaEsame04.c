//Stabilire se una matrice è un quadrato magico o meno

#include <stdio.h>
#include <stdlib.h>
#define RIGHE 3
#define COLONNE 3
#define VERO 1
#define FALSO 0

int Somma_righe(int Matrice[RIGHE][COLONNE], int riga);
int Confronta_righe(int Matrice[RIGHE][COLONNE]);
int Somma_colonne(int Matrice[RIGHE][COLONNE], int colonna);
int Confronta_colonne(int Matrice[RIGHE][COLONNE]);
int Somma_PrimaDiagonale(int Matrice[RIGHE][COLONNE]);
int Somma_SecondaDiagonale(int Matrice[RIGHE][COLONNE]);
int ConfrontaDiagonali(int SommaPrimaDiagonale, int SommaSecondaDiagonale);

int main() {
	int Matrice[3][3] = {
			{5, 7, 1},
			{3, 0, 9},
			{8, 4, 6}
	};

	int SommaPrimaDiagonale = Somma_PrimaDiagonale(Matrice);
	int SommaSecondaDiagonale = Somma_SecondaDiagonale(Matrice);

	   if(Confronta_righe(Matrice) == VERO && Confronta_colonne(Matrice) == VERO && ConfrontaDiagonali(SommaPrimaDiagonale, SommaSecondaDiagonale) == VERO) {
		   printf("\n La matrice è un quadrato magico.\n");
	   }   else {
		     printf("\n La matrice non è un quadrato magico.\n");
	       }


	system("PAUSE");
	return 0;
}

int Somma_righe(int Matrice[RIGHE][COLONNE], int riga) {
	 int j = 0;
	 int SommaRighe = 0;
	 while(j < COLONNE) {
		 SommaRighe = SommaRighe + Matrice[riga][j];
	     j = j + 1;
	 }
 return SommaRighe;
}

int Confronta_righe(int Matrice[RIGHE][COLONNE]) {
	int SommaRighe = Somma_righe(Matrice, 0);
	int riga = 1;
	while(riga < RIGHE) {
		if(SommaRighe != Somma_righe(Matrice, riga)) {
			return FALSO;
		}
	riga = riga + 1;
	}
  return VERO;
}

int Somma_colonne(int Matrice[RIGHE][COLONNE], int colonna) {
	 int i = 0;
	 int SommaColonne = 0;
	 while(i < RIGHE) {
		 SommaColonne = SommaColonne + Matrice[i][colonna];
	     i = i + 1;
	 }
 return SommaColonne;
}

int Confronta_colonne(int Matrice[RIGHE][COLONNE]) {
	int SommaColonne = Somma_colonne(Matrice, 0);
	int colonna = 1;
	while(colonna < COLONNE) {
		if(SommaColonne != Somma_colonne(Matrice, colonna)) {
			return FALSO;
		}
	colonna = colonna + 1;
	}
  return VERO;
}

int Somma_PrimaDiagonale(int Matrice[RIGHE][COLONNE]) {
	int i = 0;
	int j = 0;
	int SommaPrimaDiagonale = 0;
	while(i < RIGHE && j < COLONNE) {
		SommaPrimaDiagonale = SommaPrimaDiagonale + Matrice[i][j];
		i = i + 1;
		j = j + 1;
	}
 return SommaPrimaDiagonale;
}

int Somma_SecondaDiagonale(int Matrice[RIGHE][COLONNE]) {
	int i = 0;
	int j = 2;
	int SommaSecondaDiagonale = 0;
	while(i < RIGHE && j >= 0) {
		SommaSecondaDiagonale = SommaSecondaDiagonale + Matrice[i][j];
		i = i + 1;
		j = j - 1;
	}
 return SommaSecondaDiagonale;
}

int ConfrontaDiagonali(int SommaPrimaDiagonale, int SommaSecondaDiagonale) {
	if(SommaPrimaDiagonale == SommaSecondaDiagonale) {
		return VERO;
	}
  return FALSO;
}
