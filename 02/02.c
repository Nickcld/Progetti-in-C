/*Realizzare l’algoritmo di una funzione che valuti quanti caratteri iniziali sono in comune tra due parole date.
Ad esempio:
• se la funzione ricevesse in input le parole "ciao" e "cielo" dovrebbe restituire 2 in quanto i primi due caratteri sono identici.
• se la funzione ricevesse in input le parole "ciao" e "salve" dovrebbe restituire 0 in quanto nessun carattere iniziale è in comune.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int confrontare_parole(char parola_1[], char parola_2[]);

int main() {

	char parola_1[15];
	char parola_2[15];

	printf("\n Inserisci due parole e ti dirò quanti caratteri iniziali in comune ci sono tra loro:\n");
	scanf("%s\n", parola_1);
	scanf("%s", parola_2);
	int comuni = confrontare_parole(parola_1, parola_2);
	printf("\n Le due parole da te inserite hanno %d caratteri iniziali in comune.\n", comuni);

	system("PAUSE");
	return 0;
}


int confrontare_parole(char parola_1[], char parola_2[]) {
	int uguali;
	int comuni;
	int i;
	int j;
	int dimensione_1 = strlen(parola_1);
	int dimensione_2 = strlen(parola_2);

	comuni = 0;
	uguali = 1;
	i = 0;
	j = 0;
	while (i <= dimensione_1 - 1 && j <= dimensione_2 - 2 && uguali == 1) {
		if (parola_1[i] == parola_2[j]) {
			comuni = comuni + 1;
		} else {
			uguali = 0;
		}
	i = i + 1;
    j = j + 1;
	}
return comuni;
}


