/*Realizzare una funzione che riceve come parametro di input una matrice di n righe ed m colonne
*di numeri interi casuali compresi tra 0 e 20 e individua la colonna in cui la massima differenza
*(in valore assoluto) tra due elementi consecutivi sia minima.
Esempio Consideriamo la seguente matrice costituita da n = 4 righe ed m = 3 colonne:
15 13 7
 6 18 4
11 4 12
13 9 5
La massima differenza tra gli elementi consecutivi della prima colonna è 9 = 15−6; per la
seconda colonna è 14 = 18−4; per la terza è 8 = |4−12|. Quindi il programma deve stampare
la terza colonna la cui massima differenza è minima.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funzione per popolare la matrice con numeri casuali compresi tra 0 e 20

void PopolaMatrice(int matrice[] [20], int n, int m) {
	int i = 0, j = 0; // Indici per scorrere le righe e le colonne
	srand(time(NULL)); // Inizializza il generatore di numeri casuali
	while(i < n) {
		j = 0;
		while(j < m) {
			matrice[i][j] = rand() % 21; // Assegna un numero casuale tra 0 e 20
			j++;

		}
	    i++;
	}
}


// Funzione per stampare la matrice

void StampaMatrice(int matrice[][20], int n, int m) {
	int i = 0, j = 0; // Indici per scorrere le righe e le colonne
	while(i < n) {
		j = 0;
		while(j < m) {
			printf("%d ", matrice[i][j]); // Stampa l'elemento corrente seguito da uno spazio
			j++;
		}
		printf("\n"); // Passa alla riga successiva
		i++;

	}
}


// Funzione per calcolare la differenza massima in una colonna

int CalcolaMassimaDifferenza(int matrice[][20], int n, int colonna) {
	int maxDiff = 0; // Inizializza la differenza massima a 0
	int i = 0; // Indice per scorrere le righe
	int diff = 0; // Variabile per memorizzare la differenza calcolata
	while(i < n - 1) { // Scorriamo le righe della colonna, fino alla penultima
		// Calcola la differenza assoluta tra due elementi consecuitivi
		diff = abs(matrice[i][colonna] - matrice[i+1][colonna]);
		// Aggiorna maxDiff se la differenza calcolata è maggiore della differenza massima attuale
		if(diff > maxDiff) {
			maxDiff = diff;
		}
	    i++; // Passa alla coppia successiva di elementi consecutivi
	}
    return maxDiff; // Restituisce la differenza massima trovata
}


// Funzione per trovare la colonna con la differenza massima più piccola

int TrovaColonna(int matrice[][20], int n, int m) {
	int ColonnaMinima = 0; // Indice della colonna con differenza minima (inizialmente la prima colonna)
	int diffMinima = __INT_MAX__; // Inizializza la differenza minima al massimo valore possibile
	int colonna = 0; // Indice per scorrere le colonne
	int diff = 0; // Variabile per memorizzare la differenza massima calcolata per una colonna

	while(colonna < m) { // Scorriamo tutte le colonne
		// Calcola la differenza massima per la colonna corrente
		diff = CalcolaMassimaDifferenza(matrice, n, colonna);

		// Se la differenza massima della colonna corrente è più piccola di diffMinima
		if(diff < diffMinima) {
			diffMinima = diff; // Aggiorna la differenza minima
			ColonnaMinima = colonna; // Aggiorna l'indice della colonna minima
		}
		colonna++; // Passa alla colonna successiva


	}
    return ColonnaMinima; // Restituisce l'indice della colonna con differenza minima
}

// Funzione principale

int main() {
	int n, m; // Variabili per il numero di righe e colonne
	int ColonnaMinima; // Variabile per memorizzare l'indice della colonna con differenza minima
	int matrice[20][20]; // Matrice con massimo 20 righe e 20 colonne

	// Chiede all'utente il numero di righe e colonne
	printf("Inserisci il numero di righe: ");
	scanf("%d", &n); // Legge il numero di righe
	printf("Inserisci il numero di colonne: ");
	scanf("%d", &m); // Legge il numero di colonne

	// Popola la matrice con numeri casuali
	PopolaMatrice(matrice, n, m);

	// Stampa la matrice generata
	printf("La matrice generata è:\n");
	StampaMatrice(matrice, n, m);

	// Trova la colonna con la differenza massima più piccola

	ColonnaMinima = TrovaColonna(matrice, n, m);

	// Stampa il risultato
	printf("La colonna con la differenza massima più piccola è: %d\n", ColonnaMinima);

	system("PAUSE");
	return 0; // Termina il programma
}














