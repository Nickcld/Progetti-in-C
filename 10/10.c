/*Si scriva una funzione che riceva in ingresso due parole di al massimo 30 caratteri e verifichi se la seconda parola è contenuta almeno una
 volta all’interno della prima parola (ossia se la seconda parola è una sottostringa della prima parola).*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int individuare_sottostringa(char stringa_1[], int dimensione_1, char stringa_2[], int dimensione_2);


int main() {
	char stringa_1[] = "programmazione";
	char stringa_2[] = "gramma";
    int dimensione_1 = strlen(stringa_1);
	int dimensione_2 = strlen(stringa_2);
	int esito;

	esito = individuare_sottostringa(stringa_1, dimensione_1, stringa_2, dimensione_2);

	if (esito == 1) {
		printf("\nLa seconda parola(%s) è una sottostringa della prima(%s).\n", stringa_2, stringa_1);
	} else {
		printf("\nLa seconda parola(%s) NON è una sottostringa della prima(%s).\n", stringa_2, stringa_1);
	}


	system("PAUSE");
	return 0;
}


int individuare_sottostringa(char stringa_1[], int dimensione_1, char stringa_2[], int dimensione_2) {
	int i;
	int j;
	int k;
	int comuni;
	int esito;

	esito = 0;
	i = 0;
	k = 0;
	while (i < dimensione_1 && esito == 0) {
		if (stringa_1[i] == stringa_2[0]) {
			comuni = 1;
			j = 1;
			k = i + 1;
			while (j < dimensione_2 && k < dimensione_1) {
				if (stringa_1[k] == stringa_2[j]) {
					comuni = comuni + 1;
				}
			    j = j + 1;
			    k = k + 1;
			}
		    if (comuni == dimensione_2) {
		    	esito = 1;
		    }
		}
	    i = i + 1;
	}
	return esito;
}











