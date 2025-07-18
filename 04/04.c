/*Realizzare una sorta di cifrario di Cesare:
Data una parola P di n lettere ottenere una parola C in cui ogni lettera sia sostituita dalla lettera x posti avanti nell’alfabeto.
Considerare l’alfabeto come una struttura circolare.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cifrare_parola(char parola[], int dimensione_parola, char alfabeto_italiano[], int dimensione_alfabeto, char c[]);
void stampare_parola(char parola[], int dimensione_parola, char alfabeto_italiano[], int dimensione_alfabeto, char c[]);

int main() {

	char parola[15];
	char alfabeto_italiano[21] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'z'};
	int dimensione_alfabeto = 21;
    char c[15];

    printf("\nInserisci una parola ed io ti darò la sua versione cifrata.\n");
    scanf("%s", parola);
    int dimensione_parola = strlen(parola);
    stampare_parola(parola, dimensione_parola, alfabeto_italiano, dimensione_alfabeto, c);

	system("PAUSE");
	return 0;
}


void cifrare_parola(char parola[], int dimensione_parola, char alfabeto_italiano[], int dimensione_alfabeto, char c[]) {

	int i; //individua le posizioni dei caratteri di parola
	int j; //individua le posizioni dei caratteri di alfabeto_italiano
	int posP; //individua la posizione di una lettera di parola nell'alfabeto
	int k; //individua le posizioni dei caratteri della parola cifrata
    int trovato; //indica se è stato trovato il carattere corrispondente nell'alfabeto

    i = 0;
    k = 0;
    while (i <= dimensione_parola - 1 && k <= dimensione_parola) {
    	j = 0;
    	trovato = 0;
    	while (j <= dimensione_alfabeto - 1 && trovato == 0) {
    		if (parola[i] == alfabeto_italiano[j]) {
    			posP = j;
    			trovato = 1;
    			if (posP == dimensione_alfabeto - 1) {
    				c[k] = alfabeto_italiano[0];
    			} else {
    				c[k] = alfabeto_italiano[posP + 1];
    			}
    		} else {
    			j = j + 1;
    		}
    	}
    i = i + 1;
    k = k + 1;
    }
return;
}

void stampare_parola(char parola[], int dimensione_parola, char alfabeto_italiano[], int dimensione_alfabeto, char c[]) {

		cifrare_parola(parola, dimensione_parola, alfabeto_italiano, dimensione_alfabeto, c);
		printf("Ecco %s in versione cifrata:\n", parola);
		int i = 0;
		while (i <= dimensione_parola - 1) {
			printf("%c", c[i]);
			i = i + 1;
		}

		printf("\n");
return;
}

