#include <stdio.h>
#include <stdlib.h>

#define DIMENSIONE 4
#define NOME_FILE_INPUT "matrice.txt"
#define NOME_FILE_OUTPUT "output.txt"

void EstendiMatrice() {
    // Parametri fissati
    int dimensione = DIMENSIONE;
    const char *fileInputName = NOME_FILE_INPUT;

    // Apertura file di input
    FILE *fileInput = fopen(fileInputName, "r");
    if (fileInput == NULL) {
        return;
    }

    // 1) Alloca e inizializza la matrice a zero
    double **matrice = malloc(dimensione * sizeof(double *));
    int indiceRiga = 0;
    while (indiceRiga < dimensione) {
        matrice[indiceRiga] = malloc(dimensione * sizeof(double));
        int indiceColonna = 0;
        while (indiceColonna < dimensione) {
            matrice[indiceRiga][indiceColonna] = 0.0;
            indiceColonna++;
        }
        indiceRiga++;
    }

    // 2) Leggi le terne dal file di input
    int indiceRigaInput, indiceColonnaInput;
    double valore;
    while (fscanf(fileInput, "%d %d %lf ;", &indiceRigaInput, &indiceColonnaInput, &valore) == 3) {
        if (indiceRigaInput >= 1 && indiceRigaInput <= dimensione
         && indiceColonnaInput >= 1 && indiceColonnaInput <= dimensione) {
            matrice[indiceRigaInput - 1][indiceColonnaInput - 1] = valore;
        }
    }
    fclose(fileInput);

    // 3) Scrivi la matrice estesa su file di output
    FILE *fileOutput = fopen(NOME_FILE_OUTPUT, "w");
    if (fileOutput == NULL) {
        return;
    }
    indiceRiga = 0;
    while (indiceRiga < dimensione) {
        int indiceColonna = 0;
        while (indiceColonna < dimensione) {
            fprintf(fileOutput, "%.3f", matrice[indiceRiga][indiceColonna]);
            if (indiceColonna < dimensione - 1) {
                fprintf(fileOutput, " ");
            }
            indiceColonna++;
        }
        fprintf(fileOutput, "\n\n");
        indiceRiga++;
    }
    fclose(fileOutput);

    // 4) Libera la memoria
    indiceRiga = 0;
    while (indiceRiga < dimensione) {
        free(matrice[indiceRiga]);
        indiceRiga++;
    }
    free(matrice);
}

int main() {
    EstendiMatrice();
    system("PAUSE");
    return 0;
}
