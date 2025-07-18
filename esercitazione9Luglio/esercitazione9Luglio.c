/*Un file contiene una sequenza di terne (i, j, x) con i e j interi positivi e x reale, separate tra loro da un punto e virgola e da uno o
più spazi, come mostrato nel seguente esempio.
1 1 3.4; 3 4 4.56; 2 2 7.03; 3 5 7.455;
La sequenza rappresenta una matrice reale quadrata M con indici da 1 ad n, in modo tale che ogni terna (i, j, x) denota che la locazione
Mij ha valore x (si assuma 1<=i<=n e 1<=j<=n). Le locazioni della matrice non contenute nella sequenza hanno tutte valore 0.000
Si scriva una funzione che prende come parametri il nome del file e un intero. Il file contiene la rappresentazione suddetta della matrice
e l’intero denota la dimensione n della matrice. La funzione deve costruire in memoria la matrice completa e scrivere su un file la
rappresentazione estesa della matrice per righe (cioè una riga della matrice su ciascuna riga del file).
Ad esempio, se n = 5 e il file di ingresso e’ quello mostrato precedentemente, il file di uscita dovrà essere
3.400 0.000 0.000 0.000 0.000
0.000 7.030 0.000 0.000 0.000
0.000 0.000 0.000 4.560 7.455
0.000 0.000 0.000 0.000 0.000
0.000 0.000 0.000 0.000 0.000*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void creare_matrice_su_file(const char *filename, int n);

int main() {

    int n;
    FILE *test = fopen("input.txt", "r");
       if (test == NULL) {
           printf("ERRORE: Il file input.txt NON esiste nella directory corrente!\n");
           printf("Crea il file input.txt con contenuto tipo: 1 1 3.4; 3 4 4.56; 2 2 7.03;\n");
           system("PAUSE");
           return 1;
       } else {
           printf("OK: Il file input.txt esiste!\n");
           fclose(test);
       }
    printf("\nInserisci la lunghezza del lato della matrice quadrata che vuoi che io crei.\n");
    scanf("%d", &n);
	creare_matrice_su_file("input.txt", n);


	system("PAUSE");
	return 0;
}

void creare_matrice_su_file(const char *filename, int n) {
    int i; //individua la riga della matrice su cui scrivere il valore x
	int j; //individua la colonna della matrice su cui scrivere il valore x
	double x; //valore da scrivere in posizione i,j della matrice


	printf("Tentativo di aprire il file: %s\n", filename);
	FILE *file_in = fopen(filename, "r");
	if (file_in == NULL) {
	    printf("Errore nell'apertura del file %s\n", filename);
	    return;
	} else {
		printf("\nOk, ho creato il file di output contenente la matrice.\n");
	}
	char riga[200];
	double matrice[n][n];
	i = 0;
	while (i < n) {
		j = 0;
	    while (j < n) {
		    matrice[i][j] = 0.0;
		    j = j + 1;
	    }
	    i = i + 1;
	}
    while (fgets(riga, 200, file_in)) {
    	char *token = strtok(riga, ";");
    	while (token != NULL) {
    		while(*token == ' ') {
    			token++;
    		}
    			if (sscanf(token, "%d %d %lf", &i, &j, &x) == 3) {
    				matrice[i-1][j-1] = x;
    			}
    			token = strtok(NULL, ";");
    	}
    }
	FILE *file_out = fopen("output.txt", "w");
    i = 0;
    while (i < n) {
    	j = 0;
    	while (j < n) {
    		fprintf(file_out, "%.3f", matrice[i][j]);
    		if (j < n-1) {
    			fprintf(file_out, " ");
    		}
    	    j = j + 1;
    	}
    	fprintf(file_out, "\n");
        i = i + 1;
    }
    fclose(file_out);
    fclose(file_in);
}





















