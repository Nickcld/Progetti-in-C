/*Realizzare una funzione che riceve come parametri di input una matrice nxm di caratteri e una stringa, e calcoli
  quante volte la stringa è contenuta nelle righe della matrice.*/

#include <stdio.h>
#include <stdlib.h>
#define RIGHE 5
#define COLONNE 5
#define VERO 1
#define FALSO 0


int Ricorrenze_stringa(char Matrice[RIGHE][COLONNE], char Parola[]);
int isStringa(char Matrice[RIGHE][COLONNE], int riga);
int isParola(char Matrice[RIGHE][COLONNE], char Parola[], int riga);

int main() {

    char Matrice[RIGHE][COLONNE] = {
        {'C', 'I', 'A', 'O', '\0'},
        {'B', 'F', 'S', 'U', 'P'},
        {'Z', 'D', 'E', 'R', 'Q'},
        {'C', 'I', 'A', 'O', '\0'},
        {'C', 'O', 'D', 'E', '\0'}
    };


    char Parola[] = "CIAO";
    int Ricorrenze = Ricorrenze_stringa(Matrice, Parola);


    printf("\n La stringa '%s' è contenuta %d volte nella Matrice\n", Parola, Ricorrenze);

    system("PAUSE");
    return 0;
}

int isStringa(char Matrice[RIGHE][COLONNE], int riga) {
    if (Matrice[riga][COLONNE - 1] == '\0') {
        return VERO;
    }
    return FALSO;
}


int isParola(char Matrice[RIGHE][COLONNE], char Parola[], int riga) {
    int j = 0;


    if (!isStringa(Matrice, riga)) {
        return FALSO;
    }

    while (Parola[j] != '\0' && j < COLONNE - 1) {
        if (Matrice[riga][j] != Parola[j]) {
            return FALSO;
        }
        j = j + 1;
    }

    return VERO;
}

int Ricorrenze_stringa(char Matrice[RIGHE][COLONNE], char Parola[]) {
    int Ricorrenze = 0;
    int riga = 0;

    while (riga < RIGHE) {
        if (isParola(Matrice, Parola, riga)) {
            Ricorrenze = Ricorrenze + 1;
        }
        riga = riga + 1;
    }

    return Ricorrenze;
}



