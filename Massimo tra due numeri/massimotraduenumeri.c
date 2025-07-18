/*Determinare il massimo tra due numeri inseriti dall'utente*/
#include <stdio.h>
#include <stdlib.h>
int main() {
	int num1;
	int num2;
	printf("inserisci primo numero:\n");
	scanf("%d", &num1);
	printf("inserisici secondo numero:\n");
	scanf("%d", &num2);
	if (num1>num2)
		printf("il massimo tra i due numeri è il primo, %d\n", num1);
	else
		printf("il massimo tra i due numeri è il secondo, %d\n", num2);
	system("pause");
	return 0;
}
