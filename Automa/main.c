/*Realizzare un automa a stati finiti in grado di riconoscere il linguaggio costruito sull’alfabeto binario, costituito da parole in cui
il numero di 0 è pari e il numero di 1 e’ dispari.
Svolgimento
Realizzare una funzione main che:
- Richiede in input la parola da riconoscere
- Richiama l’automa che ne effettua l’analisi
- Stampa a video l’esito del riconoscimento.
La soluzione deve essere organizzata in 2 moduli, oltre a quello del main*/

#include <stdio.h>
#include <stdlib.h>
#include "automa.h"
#include "utils.h"

int is_binary_string(const char* str);

int main() {

	char parola[100];
	int valida = 0;

	while (!valida) {
		printf("\nInserisci una parola binaria: ");
		scanf("%s", parola);

		if (!is_binary_string(parola)) {
			printf("\nErrore: la parola deve contenere solo 0 e 1!\n");
		} else {
			valida = 1;
		}
	}

	if (automa_riconoscitore(parola)) {
		printf("\nLa parola appartiene al linguaggio delle stringhe binarie costituite da un numero pari di 0 e dispari di 1.\n");
	} else {
		printf("\nLa parola NON appartiene al linguaggio delle stringhe binarie costituite da un numero pari di 0 e dispari di 1.\n" );
	}

	system("PAUSE");
	return 0;
}
