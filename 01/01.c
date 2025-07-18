/*Realizzare lo pseudocodice e il codice di una funzione che riceve in input una stringa e verifica se e’ palindroma o no.
Nella realizzazione del codice, il main deve:
1. Richiedere all’utente la stringa
2. Richiamare la funzione passando in input la stringa e assegnare a una variabile il risultato della funzione
3. Stampare un messaggio in base al valore restituito dalla funzione*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verificare_stringa(char stringa[]);

int main() {

	char stringa[50];

	printf("\n Inserisci una stringa e ti dirò se è palindroma o meno:\n");
	scanf("%s", stringa);
	if (verificare_stringa(stringa) == 1) {
		printf("\n La stringa inserita è palindroma.\n");
	} else {
		printf("\n La stringa inserita non è palindroma.\n");
	}

	system("PAUSE");
	return 0;
}


int verificare_stringa(char stringa[]) {
	int i;
	int j;
	int esito;

	i = 0;
	j = strlen(stringa) - 1;
	esito = 1;
	while (i < j && esito == 1) {
		if (stringa[i] != stringa[j]) {
			esito = 0;
		}
	    i = i + 1;
	    j = j - 1;
	}
return esito;
}


