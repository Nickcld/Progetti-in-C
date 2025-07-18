/*Il numero 197 è chiamato circolare primo perchè tutte le rotazioni delle cifre: 197, 971 e 719, sono essi stessi primi.
  Ci sono tredici numeri primi circolari sotto 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79 e 97.
  Quanti numeri primi circolari ci sono al di sotto di 1000000?*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

//funzione per verificare se un numero è primo
int isPrimo(int n) {
	int i = 2; //Divisore iniziale
	while(i < n) { //controlla tutti i numeri da 2 a n-1
		if(n % i == 0) { //se è divisibile
			return 0; // non è primo
		}
	    i = i + 1; //passa al prossimo divisore
	}
    return 1; //nessun divisore trovato: è primo
}

//Funzione per verificare se un numero è circolare primo
int isCircolarePrimo(int n) {
	int rotazione = n;
	int lunghezza = 0;
	int tmp = n;

	//Calcola la lunghezza del numero (quante cifre ha)
	  while(tmp > 0) {
		  tmp /= 10;
		  lunghezza = lunghezza + 1;
	  }

	//Calcola 10^(lunghezza - 1)
	  int potenza10 = 1, j = 1;
	  while(j < lunghezza) {
		  potenza10 *= 10;
		  j = j + 1;
	  }
	  int k = 0; //contatore per le rotazioni
	  while(k < lunghezza) { //verifica tutte le rotazioni
		  if (! isPrimo(rotazione)) {
			  return 0;
		  }
	      //ruota il numero
		  int ultimaCifra = rotazione % 10;
		  rotazione = (ultimaCifra * potenza10) + (rotazione / 10);
		  k = k + 1;
	   }
       return 1; //tutte le rotazioni sono prime
}

int main() {
	int count = 0;
	int n = 2; //inizializza n a 2

	//scansiona tutti i numeri da 2 a 1000000
	    while(n < 1000000) {
	    	if (isCircolarePrimo(n)) {
	    		count = count + 1;
	    	}
	        n++; //passa al numero successivo
	    }
        printf("\nNumero totale di numeri circolari primi sotto 1000000 = %d", count);
        return 0;
}

