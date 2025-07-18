/*Si scriva una funzione ricorsiva che calcoli il fattoriale di un numero intero positivo.*/

#include <stdio.h>
#include <stdlib.h>

int calcolare_fattoriale(int n);

int main() {

	int numero;
	int fattoriale;

	printf("\nInserisci un numero di cui vuoi che io calcoli il fattoriale:\n");
	scanf("%d", &numero);
	if (numero < 0) {
		printf("\nErrore! Inserire un numero positivo.\n");
		scanf("%d", &numero);
		}
	fattoriale = calcolare_fattoriale(numero);
	printf("\nIl fattoriale di %d è %d.\n", numero, fattoriale);


	system("PAUSE");
	return 0;
}

int calcolare_fattoriale(int n) {
	int fattoriale;

	if (n == 0) {
		fattoriale = 1;
	} else {
		fattoriale = n * calcolare_fattoriale(n - 1);
	}
    return fattoriale;
}

