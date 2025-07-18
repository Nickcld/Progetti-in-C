/*Leggere da file una sequenza di numeri reali.
Individuare il massimo, il minimo e la media degli elementi della sequenza.
Stampare le sotto-sequenze individuate su file, diverso da quello di input.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int individuare_max(int elenco[], int dimensione);
int individuare_min(int elenco[], int dimensione);
float calcolare_media(int elenco[], int dimensione);
void scrivere_risultati_su_file(const char *filename);


int main() {


    scrivere_risultati_su_file("sequenza.txt");


	system("PAUSE");
	return 0;
}



int individuare_max(int elenco[], int dimensione) {
	int i;
	int max;

	i = 0;
	max = elenco[0];
	while (i < dimensione) {
		if (elenco[i] > max) {
			max = elenco[i];
		}
	    i = i + 1;
	}
	return max;
}

int individuare_min(int elenco[], int dimensione) {
	int i;
	int min;

	i = 0;
	min = elenco[0];
	while (i < dimensione) {
		if (elenco[i] < min) {
			min = elenco[i];
		}
	    i = i + 1;
	}
	return min;
}

float calcolare_media(int elenco[], int dimensione) {
	float media;
	int i;
	int somma;

	media = 0.0;
	i = 0;
	somma = 0;
	while (i < dimensione) {
		somma = somma + elenco[i];
		i = i + 1;
	}
    media = (float)somma / dimensione;
    return media;
}

void scrivere_risultati_su_file(const char *filename) {
	char riga[100];
	int elenco[50];
	int max;
	int min;
	float media;
	int dimensione = 0;

	FILE *file_in = fopen(filename, "r");
	if (file_in == NULL) {
		printf("\nErrore nell'apertura del file %s.\n", filename);
	} else {
		printf("\nFile di input aperto correttamente. Avvio elaborazione...\n");
	}

	fgets(riga, sizeof(riga), file_in);
	char *token = strtok(riga, " ");
	while (token != NULL) {
		elenco[dimensione] = atoi(token);
		dimensione = dimensione + 1;
		token = strtok(NULL, " ");
	}

	FILE *file_out = fopen("risultati.txt", "w");
	if (file_out == NULL) {
	    printf("Errore nell'apertura del file di output.\n");
	    fclose(file_in);
	    return;
	}

	max = individuare_max(elenco, dimensione);
	min = individuare_min(elenco, dimensione);
    media = calcolare_media(elenco, dimensione);
    fprintf(file_out, "Massimo: %d\n", max);
    fprintf(file_out, "Minimo: %d\n", min);
    fprintf(file_out, "Media: %.2f\n", media);

    printf("\nRisultati scritti correttamente sul file risultati.txt.\n");
    fclose(file_in);
    fclose(file_out);

    return;
}




















































