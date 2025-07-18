#include <stdio.h>

int main() {

	/****Dichiarazione e assegnazione di due variabili: un intero e un carattere****/

	int i = 9;
	char c = 'a';

	/****Sintassi e Operatori dei puntatori****/

	int *pi; //Puntatore ad int
	char *pc; //Puntatore a char

	pi = &i; //Prende l'indirizzo di memoria in cui è contenuta la variabile i
	pc = &c; //Prende l'indirizzo di memoria in cui è contenuta la variabile c


	printf("Indirizzo di memoria di i: %p, Indirizzo di memoria di c: %p\n\n", pi, pc);

	printf("Il valore di i: %d = %d\n", i, *pi); /*Notiamo che stampa lo stesso valore (9) in entrambi i casi: nel primo
	caso perchè abbiamo inserito direttamente la variabile i, nel secondo caso perchè abbiamo inserito il puntatore al
	contenuto dell'indirizzo di memoria pi, che è proprio il valore 9.*/
	printf("Il valore di c: %c = %c\n", c, *pc); /*...Stessa cosa*/


	/****Modificare il contenuto di una variabil utilizzando i puntatori****/
	*pi = 18; //Va alla cella di memoria puntata da pi e ne modifica il contenuto

	printf("Il valore di i: %d, il valore della cella puntata da pi: %d\n", i, *pi);


	return 0;
}

