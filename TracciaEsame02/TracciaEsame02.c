/*Realizzare una funzione che riceve come parametro di input una matrice di n righe ed m colonne
di numeri interi casuali compresi tra 0 e 20 e individua la colonna in cui la massima differenza
(in valore assoluto) tra due elementi consecutivi sia minima.*/

#include <stdio.h>
#include <stdlib.h>
#define RIGHE 3
#define COLONNE 3

int Valore_Assoluto(int NUM1);
int MinimaTraMassime(int PrimaMaxDiff, int SecondaMaxDiff, int TerzaMaxDiff);
int MaxDiff_PrimaColonna(int Matrice[RIGHE][COLONNE], int colonna);
int MaxDiff_SecondaColonna(int Matrice[RIGHE][COLONNE], int colonna);
int MaxDiff_TerzaColonna(int Matrice[RIGHE][COLONNE], int colonna);

int main() {

	int Matrice[3][3] = {
			{8, 2, 13},
			{19, 11, 6},
			{5, 15, 18}
	};

	int colonna;
	int PrimaMaxDiff = MaxDiff_PrimaColonna(Matrice, colonna);
	int SecondaMaxDiff = MaxDiff_SecondaColonna(Matrice, colonna);
	int TerzaMaxDiff = MaxDiff_TerzaColonna(Matrice, colonna);
	int minima = MinimaTraMassime(PrimaMaxDiff, SecondaMaxDiff, TerzaMaxDiff);
    int NUM1;
	Valore_Assoluto(NUM1);

	if(minima == PrimaMaxDiff) {
		colonna = 0;
		printf("\n La minima tra le massime differenze è quella della prima colonna: %d \n %d \n %d \n %d", minima, Matrice[0][0], Matrice[1][0], Matrice[2][0]);
	}

	if(minima == SecondaMaxDiff) {
			colonna = 1;
			printf("\n La minima tra le massime differenze è quella della seconda colonna: %d \n %d \n %d \n %d", minima, Matrice[0][1], Matrice[1][1], Matrice[2][1]);
	}

	if(minima == TerzaMaxDiff) {
			colonna = 2;
			printf("\n La minima tra le massime differenze è quella della terza colonna: %d \n %d \n %d \n %d", minima, Matrice[0][2], Matrice[1][2], Matrice[2][2]);
	}


	system("PAUSE");
	return 0;
}

int Valore_Assoluto(int NUM1) {
	int ValoreAssoluto = 0;
	if(NUM1 < 0) {
	ValoreAssoluto = ValoreAssoluto +  NUM1 * (-1);
	} else {
		ValoreAssoluto = NUM1;
	}
return ValoreAssoluto;
}

int MaxDiff_PrimaColonna(int Matrice[RIGHE][COLONNE], int colonna) {
	int PrimaMaxDiff = 0;
	colonna = 0;
	int i = 0;

	while(i < RIGHE - 2) {
		if(Valore_Assoluto(Matrice[i][colonna] - Matrice[i+1][colonna]) > Valore_Assoluto(Matrice[i+1][colonna] - Matrice[i+2][colonna])) {
			PrimaMaxDiff = PrimaMaxDiff + Valore_Assoluto(Matrice[i][colonna] - Matrice[i+1][colonna]);
		} else {
			PrimaMaxDiff = PrimaMaxDiff + Valore_Assoluto(Matrice[i+1][colonna] - Matrice[i+2][colonna]);
		  }
	i = i + 1;
	}
 return PrimaMaxDiff;
}

int MaxDiff_SecondaColonna(int Matrice[RIGHE][COLONNE], int colonna) {
	int SecondaMaxDiff = 0;
	colonna = 1;
	int i = 0;

	while(i < RIGHE - 2) {
		if(Valore_Assoluto(Matrice[i][colonna] - Matrice[i+1][colonna]) > Valore_Assoluto(Matrice[i+1][colonna] - Matrice[i+2][colonna])) {
			SecondaMaxDiff = SecondaMaxDiff + Valore_Assoluto(Matrice[i][colonna] - Matrice[i+1][colonna]);
		} else {
			SecondaMaxDiff = SecondaMaxDiff + Valore_Assoluto(Matrice[i+1][colonna] - Matrice[i+2][colonna]);
		  }
	i = i + 1;
	}
 return SecondaMaxDiff;
}

int MaxDiff_TerzaColonna(int Matrice[RIGHE][COLONNE], int colonna) {
	int TerzaMaxDiff = 0;
	colonna = 2;
	int i = 0;

	while(i < RIGHE - 2) {
		if(Valore_Assoluto(Matrice[i][colonna] - Matrice[i+1][colonna]) > Valore_Assoluto(Matrice[i+1][colonna] - Matrice[i+2][colonna])) {
			TerzaMaxDiff = TerzaMaxDiff + Valore_Assoluto(Matrice[i][colonna] - Matrice[i+1][colonna]);
		} else {
			TerzaMaxDiff = TerzaMaxDiff + Valore_Assoluto(Matrice[i+1][colonna] - Matrice[i+2][colonna]);
		  }
	i = i + 1;
	}
 return TerzaMaxDiff;
}

int MinimaTraMassime(int PrimaMaxDiff, int SecondaMaxDiff, int TerzaMaxDiff) {
	int minima = 0;
	if(PrimaMaxDiff < SecondaMaxDiff) {
		minima = minima + PrimaMaxDiff;
	} else if(SecondaMaxDiff > TerzaMaxDiff) {
		minima = minima + TerzaMaxDiff;
	  } else {
		minima = minima + SecondaMaxDiff;
	  }
	return minima;
}
