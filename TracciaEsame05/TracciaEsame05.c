/*Realizzare una funzione che riceve come parametri di input una matrice nxm di caratteri e una stringa, e calcoli
  quante volte la stringa è contenuta nelle colonne della matrice.*/

#include <stdio.h>
#include <stdlib.h>
#define VERO 1
#define FALSO 0
#define RIGHE 5
#define COLONNE 5

int is_Stringa(char Matrice[RIGHE][COLONNE], int colonna);
int is_Parola(char Matrice[RIGHE][COLONNE], char Parola[], int colonna);
int RicorrenzeStringa(char Matrice[RIGHE][COLONNE], char Parola[]);

int main() {

	char Matrice[5][5] = {
	{'C', 'S', 'V', 'C', 'C'},
	{'O', 'X', 'M', 'I', 'I'},
	{'D', 'U', 'G', 'A', 'A'},
	{'E', 'F', 'R', 'O', 'O'},
	{'\0', 'Q', 'L', '\0', '\0'}
	};

	char Parola[5];
	Parola[0] = 'C';
	Parola[1] = 'I';
	Parola[2] = 'A';
	Parola[3] = 'O';
	Parola[4] = '\0';

	int LunghezzaParola = 5;

    int Ricorrenze = RicorrenzeStringa(Matrice, Parola);
    printf("\n La stringa %s è contenuta %d volte nella matrice.\n", Parola, Ricorrenze);

     system("PAUSE");
     return 0;
}

int is_Stringa(char Matrice[RIGHE][COLONNE], int colonna) {
        if(Matrice[RIGHE - 1][colonna] == '\0') {
			return VERO;
		}
	return FALSO;
}

int is_Parola(char Matrice[RIGHE][COLONNE], char Parola[], int colonna) {
	  int riga = 0;
	  if(!is_Stringa(Matrice, colonna)) {
		  return FALSO;
	  }

	       while(Parola[riga] != '\0' && riga < RIGHE - 1) {
	    	   if(Matrice[riga][colonna] != Parola[riga]) {
	    		   return FALSO;
	    	   }
	       riga = riga + 1;
	       }
	return VERO;
}


int RicorrenzeStringa(char Matrice[RIGHE][COLONNE], char Parola[]) {
	int Ricorrenze = 0;
	int colonna = 0;
	while(colonna < COLONNE) {
		if(is_Parola(Matrice, Parola, colonna)) {
			Ricorrenze = Ricorrenze + 1;
		}
	colonna = colonna + 1;
	}
  return Ricorrenze;
}



