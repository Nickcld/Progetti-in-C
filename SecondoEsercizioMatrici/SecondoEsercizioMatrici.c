/* Scrivere un programma che legga un numero intero n (numero di righe e colonne, la matrice è quadrata), generi una matrice di dimensioni n x n
 * popolata con numeri interi casuali tra 0 e 50. Il programma deve:
 * 1. Calcolare la somma degli elementi della diagonale principale (quella che va dall'angolo in alto a sinistra all'angolo in basso a destra).
 * 2. Calcolare la somma degli elementi della diagonale secondaria (quella che va dall'angolo in alto a destra all'angolo in basso a sinistra).
 * 3. Stampare entrambe le somme e indicare quale delle due è maggiore.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funzione per popolare la matrice con numeri casuali tra 0 e 50
void PopolaMatrice(int matrice[][4], int n) {
    int i = 0, j;
    srand(time(NULL));
    while (i < n) {
        j = 0;
        while (j < n) {
            matrice[i][j] = rand() % 51;
            j++;
        }
        i++;
    }
}

// Funzione per stampare la matrice
void StampaMatrice(int matrice[][4], int n) {
    int i = 0, j;
    while (i < n) {
        j = 0;
        while (j < n) {
            printf("%4d", matrice[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}

// Funzione per calcolare la somma degli elementi della diagonale principale
int CalcolaSommaPrimaDiagonale(int matrice[][4], int n) {
    int PrimaSomma = 0;
    int i = 0;
    while (i < n) {
        PrimaSomma += matrice[i][i];
        i++;
    }
    return PrimaSomma;
}

// Funzione per calcolare la somma degli elementi della diagonale secondaria
int CalcolaSommaSecondaDiagonale(int matrice[][4], int n) {
    int SecondaSomma = 0;
    int i = 0;
    while (i < n) {
        SecondaSomma += matrice[i][n - 1 - i];
        i++;
    }
    return SecondaSomma;
}

int main() {
    int matrice[4][4]; // Matrice massima 4x4
    int n;

    do {
        printf("Inserisci la dimensione della matrice (da 1 a 4): ");
        scanf("%d", &n);
        if (n < 1 || n > 4) {
            printf("Errore: la dimensione deve essere compresa tra 1 e 4.\n");
        }
    } while (n < 1 || n > 4);

    // Popolamento della matrice
    PopolaMatrice(matrice, n);

    // Stampa la matrice
    printf("La matrice generata è:\n");
    StampaMatrice(matrice, n);

    // Calcolo delle somme
    int PrimaSomma = CalcolaSommaPrimaDiagonale(matrice, n);
    int SecondaSomma = CalcolaSommaSecondaDiagonale(matrice, n);

    // Confronto e stampa delle somme
    printf("\nSomma della diagonale principale: %d\n", PrimaSomma);
    printf("Somma della diagonale secondaria: %d\n", SecondaSomma);

    if (PrimaSomma > SecondaSomma) {
        printf("\nLa somma maggiore è quella della diagonale principale: %d\n", PrimaSomma);
    } else if (SecondaSomma > PrimaSomma) {
        printf("\nLa somma maggiore è quella della diagonale secondaria: %d\n", SecondaSomma);
    } else {
        printf("\nLe due somme sono uguali: %d\n", PrimaSomma);
    }

    system("PAUSE");
    return 0;
}








