/*Realizzare un programma che, prese in input due stringhe:
- la prima contenente il nome e il cognome di una persona separata da uno o più spazi;
- la seconda contenente il soprannome di una persona,
restituisca in output una nuova stringa in cui tra il nome ed il cognome viene inserito il soprannome; inoltre devono essere eliminati gli
spazi vuoti.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generare_stringa(char stringa_1[], char stringa_2[], int dimensione_1, int dimensione_2, char nuova_stringa[]);

int main() {

   char stringa_1[40];
   char stringa_2[40];
   char nuova_stringa[80];

      printf("\nInserisci un nome ed un cognome (separati da quanti spazi vuoi):\n");
	  fgets(stringa_1, sizeof(stringa_1), stdin);
	  stringa_1[strcspn(stringa_1, "\n")] = '\0';

	  printf("Ok, ora inserisci un soprannome a tua scelta:\n");
	  fgets(stringa_2, sizeof(stringa_2), stdin);
	  stringa_2[strcspn(stringa_2, "\n")] = '\0';

	  int dimensione_1 = strlen(stringa_1);
	  int dimensione_2 = strlen(stringa_2);

	  generare_stringa(stringa_1, stringa_2, dimensione_1, dimensione_2, nuova_stringa);

	  printf("Risultato: %s\n", nuova_stringa);

    system("PAUSE");
	return 0;
}


void generare_stringa(char stringa_1[], char stringa_2[], int dimensione_1, int dimensione_2, char nuova_stringa[]) {
	int i;
	int j;
	int k;
	int dimensione_nuova_stringa;

	dimensione_nuova_stringa = (dimensione_1 + dimensione_2) - 1;
	i = 0;
	k = 0;
	while (stringa_1[i] != ' ' && k < dimensione_nuova_stringa) {
		nuova_stringa[k] = stringa_1[i];
		i = i + 1;
		k = k + 1;
	}
	j = 0;
	while (j < dimensione_2 && k < dimensione_nuova_stringa) {
		nuova_stringa[k] = stringa_2[j];
		j = j + 1;
		k = k + 1;
	}
	while (stringa_1[i] == ' ') {
		i = i + 1;
	}
	while (i < dimensione_1 && k < dimensione_nuova_stringa) {
		nuova_stringa[k] = stringa_1[i];
		i = i + 1;
		k = k + 1;
	}

	nuova_stringa[k] = '\0';
return;
}


