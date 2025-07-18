#include <stdio.h>
#include <stdlib.h>
#define RIGHE 3
#define COLONNE 3

int main() {

	int Matrice[3][3] = {
			{15, 2, 13},
			{4, 15, 9},
			{12, 8, 19}
	};



}

int differenza_colonna1(int Matrice[RIGHE][COLONNE]) {
	int i;
	int j;
	int valore;
	i = 0;
	while(i < RIGHE) {
		j = 0;
		while(j < COLONNE) {
		if(abs(Matrice[i][j] - Matrice[i+1][j]) > abs(Matrice[i + 1][j] - Matrice[i + 2][j])) {
			   valore = abs(Matrice[i][j] - Matrice[i+1][j]);
		} else {
			valore = abs(Matrice[i + 1][j] - Matrice[i + 2][j]);
		  }

	    }
}
return valore;
}

int differenza_colonna2(int Matrice[RIGHE][COLONNE]) {
	int i;
	int j;
	int valore;
	i = 0;
	while(i < RIGHE) {
		j = 0;
		while(j < COLONNE) {
		if(abs(Matrice[i][j+1] - Matrice[i+1][j + 1]) > abs(Matrice[i + 1][j + 1] - Matrice[i + 2][j + 1])) {
			   valore = abs(Matrice[i][j + 1] - Matrice[i+1][j + 1]);
		} else {
			valore = abs(Matrice[i + 1][j + 1] - Matrice[i + 2][j + 1]);
		  }

	    }
}
return valore;
}

int differenza_colonna3(int Matrice[RIGHE][COLONNE]) {
	int i;
	int j;
	int valore;
	i = 0;
	while(i < RIGHE) {
		j = 0;
		while(j < COLONNE) {
		if(abs(Matrice[i][j + 2] - Matrice[i+1][j + 2]) > abs(Matrice[i + 1][j + 2] - Matrice[i + 2][j + 2])) {
			   valore = abs(Matrice[i][j + 2] - Matrice[i+1][j + 2]);
		} else {
			valore = abs(Matrice[i + 1][j + 2] - Matrice[i + 2][j + 2]);
		  }

	    }
}
return valore;
}

void confronta_differenze(int Matrice[RIGHE][COLONNE]) {
	int x = differenza_colonna1;
	int y = differenza_colonna2;
	int z = differenza_colonna3;


}
