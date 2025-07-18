/*Scrivi un programma che prenda in input una sequenza di numeri e conti quante sequenze consecutive crescenti ci sono (senza mai scendere).
 * Una sequenza crescente è una sequenza di numeri in cui ogni numero è maggiore del precedente, e può essere interrotta da un numero inferiore.
 * Esempio: Input: [1, 3, 5, 2, 6, 7, 4, 8] Risultato: 3 (le sequenze crescenti sono: [1, 3, 5], [2, 6, 7], [4, 8]).*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	int numeri[10];
	int indice = 0;
	int sequenze_crescenti = 0;

	// Inserimento dei 10 numeri su una sola riga
	printf("\n\n Inserisci 10 numeri separati da spazio: ");
	while(indice < 10) {
		scanf("%d", &numeri[indice]);
		indice++;
	}

	// Reset dell'indice per analizzare la sequenza
	indice = 0;
	printf("\n Sequenze crescenti trovate: ");

	// Ciclo principale per trovare e stampare le sequenze crescenti
	while(indice < 9) {  // (10 elementi, quindi fino a 9 (ultimo confronto tra 9 e 10)
		if(numeri[indice] < numeri[indice + 1]) {
			printf("[");
			printf("%d", numeri[indice]);

			while(indice < 9 && numeri[indice] < numeri[indice + 1]) {
				indice++;
				printf(", %d", numeri[indice]); // Stampa il resto della sequenza
			}
				printf("]");
				sequenze_crescenti++;
				} else {
					indice++;
				}
		}

   // Se nessuna sequenza è stata trovata
   if(sequenze_crescenti == 0) {
	   printf("Nessuna sequenza crescente trovata.");
   }
   else {
	   printf("\n Numero di sequenze crescenti: %d\n", sequenze_crescenti);
   }

   system("PAUSE");
   return 0;
}





