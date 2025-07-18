/*Realizzare una funzione che riceve come parametri di input una matrice nxm di caratteri e una stringa, e calcoli
  quante volte la stringa è contenuta nelle colonne della matrice.*/

#include <stdio.h>
#include <stdlib.h>
#define RIGHE 5
#define COLONNE 5
#define VERO 1
#define FALSO 0

int isStringa(char Matrice[RIGHE][COLONNE], int colonna);
int isParola(char Matrice[RIGHE][COLONNE], char Parola[], int colonna);
int Ricorrenze_stringa(char Matrice[RIGHE][COLONNE], char Parola[]);

int main() {

	char Matrice[5][5] = {
	{'C', 'E', 'C', 'C', 'C'},
	{'I', 'F', 'O', 'I', 'I'},
	{'A', 'S', 'D', 'A', 'A'},
	{'O', 'I', 'E', 'O', 'O'},
	{'\0', 'Z', '\0', '\0', '\0'}
	};

	char Parola[] = "CIAO";

	int Ricorrenze = Ricorrenze_stringa(Matrice, Parola);

	printf("\n La stringa %s è contenuta %d volte nella Matrice\n", Parola, Ricorrenze);


	system("PAUSE");
	return 0;
}


int isStringa(char Matrice[RIGHE][COLONNE], int colonna) {
	if(Matrice[RIGHE - 1][colonna] == '\0') {
		return VERO;
	}
 return FALSO;
}

int isParola(char Matrice[RIGHE][COLONNE], char Parola[], int colonna) {
	int i = 0;
	if(!isStringa(Matrice, colonna)) {
		return FALSO;
	}

	while(Parola[i] != '\0' && i < RIGHE - 1) {
		if(Matrice[i][colonna] != Parola[i]) {
			return FALSO;
		}
	i = i + 1;
	}

	return VERO;
}

int Ricorrenze_stringa(char Matrice[RIGHE][COLONNE], char Parola[]) {
	int Ricorrenze = 0;
	int colonna = 0;
	while(colonna < COLONNE) {
		if(isParola(Matrice, Parola, colonna)) {
			Ricorrenze = Ricorrenze + 1;
		}
	colonna = colonna + 1;
	}
  return Ricorrenze;
}
