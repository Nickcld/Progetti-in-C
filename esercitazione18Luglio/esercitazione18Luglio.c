/*Un anagramma è una parola ottenuta riordinando le lettere di un'altra, usando esattamente le stesse lettere e lo stesso numero di occorrenze,
ma in un ordine diverso (ad esempio "roma" e "amor"). Scrivere un programma che chieda all'utente di inserire due parole e verifichi se sono
anagrammi o meno.*/

/***INCLUSIONE DELLE LIBRERIE***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***PROTOTIPI DELLE FUNZIONI***/

int calcolare_ricorrenze(char parola[], int dimensione_parola, char lettera);
int verificare_anagramma(char parola_1[], char parola_2[]);

/***FUNZIONE MAIN***/

int main() {

	int esito;
	char parola_1[20];
	char parola_2[20];

	printf("\nInserisci due parole ed io ti dirò se sono anagrammi o meno.\n\n");
	printf("Prima parola: ");
	scanf ("%s", parola_1);
	printf("\n");
	printf("Seconda parola: ");
	scanf("%s", parola_2);
	printf("\n");

	esito = verificare_anagramma(parola_1, parola_2);
	if (esito == 1) {
		printf("\nLe due parole sono anagrammi.\n");
	} else {
		printf("\nLe due parole non sono anagrammi.\n");
	}


	system("PAUSE");
	return 0;
}

/***FUNZIONI NECESSARIE PER IL CORRETTO FUNZIONAMENTO DEL PROGRAMMA***/

int calcolare_ricorrenze(char parola[], int dimensione_parola, char lettera) {
	int ricorrenze;
	int i;

	ricorrenze = 0;
	i = 0;
	while (i < dimensione_parola) {
		if (parola[i] == lettera) {
			ricorrenze = ricorrenze + 1;
		}
	    i = i + 1;
	}
	return ricorrenze;
}


int verificare_anagramma(char parola_1[], char parola_2[]) {
	int esito;
	int dimensione_1;
	int dimensione_2;
	int i; //scorre le lettere di parola_1
	int j; //scorre le lettere di parola_2
	int trovata; //indica se una lettera di parola_1 è stata trovata all'interno di parola_2

	esito = 1;
	dimensione_1 = strlen(parola_1);
	dimensione_2 = strlen(parola_2);

	if (dimensione_1 != dimensione_2) {
		esito = 0;
	}


	i = 0;
	while (i < dimensione_1) {
		j = 0;
		trovata = 0;
		while (j < dimensione_2 && esito == 1) {
		    if (parola_1[i] == parola_2[j]) {
		    	trovata = 1;
		    	if (calcolare_ricorrenze(parola_1, dimensione_1, parola_1[i]) != calcolare_ricorrenze(parola_2, dimensione_2, parola_2[j])) {
		    		esito = 0;
		    	}
		    }
		    j = j + 1;
		}
		if (trovata == 0) {
			esito = 0;
		}

        i = i + 1;
	}
	return esito;
}

























