//Scrivi un programma che prenda un numero e lo divida ripetutamente per 2 (arrotondando per difetto) fino a ottenere 1.
//Conta quante divisioni sono necessarie.
//Esempio: Numero: 100
//Output: 6 (100/2 = 50, 50/2 = 25, 25/2 = 12, 6/2 = 3, 3/2 = 1)

#include <stdio.h>
#include <stdlib.h>

int n; //numero da dividere ripetutamente per 2
int ContaDivisioni = 0; //contatore che tiene traccia delle divisioni

int main() {
    char buffer[500] = ""; //buffer per memorizzare le divisioni successive per 2 del numero inserito dall'utente
    char temp[50]; //buffer temporaneo per costruire la stringa formattata di ciascuna divisione
    scanf("%d", &n);
    printf("\n Numero: %d", n);
    while(n > 1) {
    	   sprintf(temp, "%d/2 = %d, ", n, n/2);
    	   strcat(buffer, temp); //concatenazione della stringa temp al buffer. Mi permette di stampare l'intera sequenza di operazioni eseguite
    	   n = n/2;
    	   ContaDivisioni = ContaDivisioni + 1;
    }
    if(ContaDivisioni > 0) {
    	buffer[strlen(buffer) - 2] = '\0'; //troncamento della stringa eliminando la virgola e lo spazio finali
    }

   printf("\n\n Divisioni successive per 2: %d (%s)\n", ContaDivisioni, buffer);
   system("PAUSE");
}
