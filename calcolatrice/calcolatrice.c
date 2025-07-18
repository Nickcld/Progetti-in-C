/*Realizzare una calcolatrice semplice che sia in grado di risolvere qualsiasi operazione inserita in input dall'utente (somma, sottrazione,
prodotto, divisione)*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void stampareCalcolatrice();
float effettuareCalcoli(float n1, float n2, char operatore);

int main() {
    float n1;
    float n2;
    char operatore;
    float operazione;
    char scelta[5] = "";

    stampareCalcolatrice();

    while (strcmp(scelta, "OFF") != 0) {
    	 printf("\n\nDigita ON se vuoi inserire l'operazione tra due numeri e OFF se vuoi uscire dal programma.\n");
    	 scanf("%4s", scelta);

    	    if (strcmp(scelta, "ON") == 0) {
    	    	printf("\nDigita un'operazione (somma, sottrazione, prodotto o divisione): ");
    	    	scanf("%f %c %f", &n1, &operatore, &n2);
	            operazione = effettuareCalcoli(n1, n2, operatore);

                printf("\nRisultato: %.2f\n", operazione);
    	    } else if (strcmp(scelta, "OFF") != 0) {

        	    printf("\nInput non valido. Digita ON o OFF.\n");
            }
    }

    printf("\nSto chiudendo la calcolatrice...\n");

    system("PAUSE");
	return 0;
}


void stampareCalcolatrice() {
	printf("\n--------------------------------");
	printf("\n|         CALCOLATRICE         |");
	printf("\n--------------------------------");
	printf("\n|                 [ON]   [OFF] |");
    printf("\n|   [7]    [8]    [9]    [+]   |");
    printf("\n|   [4]    [5]    [6]    [-]   |");
    printf("\n|   [1]    [2]    [3]    [x]   |");
    printf("\n|   [0]    [.]    [=]    [/]   |");
    printf("\n|                              |");
    printf("\n--------------------------------");


}

float effettuareCalcoli(float n1, float n2, char operatore) {
	float operazione;
	operazione = 0;

	switch (operatore) {
	    case '+':
	        operazione = n1 + n2;
	        break;
	    case '-':
	    	operazione = n1 - n2;
	    	break;
	    case 'x':
	    	operazione = n1 * n2;
	        break;
	    case '/':
	    	if (n2 != 0) {
	    		operazione = n1 / n2;
	    	} else {
	    		printf("Errore: divisione per zero.\n");

	    	}
	    	break;

	    default:
	    	printf("Operatore non valido.\n");

	}
    return operazione;
}





















































