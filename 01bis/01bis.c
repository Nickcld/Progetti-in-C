/*Realizzare lo pseudocodice e il codice di una funzione che riceve in input una stringa e verifica se e’ palindroma o no.
Nella realizzazione del codice, il main deve:
1. Richiedere all’utente la stringa
2. Richiamare la funzione passando in input la stringa e assegnare a una variabile il risultato della funzione
3. Stampare un messaggio in base al valore restituito dalla funzione.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int verificare_stringa(char stringa[]);


int main() {

	char stringa[20];
	int esito;
	printf("\nInserisci una parola ed io ti dirò se è palindroma o meno:\n");
	scanf("%s", stringa);
	esito = verificare_stringa(stringa);
	if (esito == 1) {
		printf("\nLa parola inserita è palindroma.\n");
	} else {
		printf("\nLa parola inserita non è palindroma.\n");
	}
	printf("\n");


	system("PAUSE");
	return 0;
}

int verificare_stringa(char stringa[]) {
	int i; //scorre la stringa dalla prima posizione verso il centro
	int j; //scorre la stringa dall'ultima posizione verso il centro
	int esito;
	int dimensione;

	dimensione = strlen(stringa) - 1;
	i = 0;
	j = dimensione;
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





