/*Realizzare una funzione che riceve come parametri di input due numeri interi n > 0 e k > 1 e costruisce un elenco A di n numeri interi
casuali minori di 100 che non siano multipli di k.*/

#include <stdio.h>
#include <stdlib.h>

void costruire_elenco(int n, int k, int elenco[]);
void stampare_elenco(int n, int k);

int main() {

	int n = 10;
	int k = 3;

	printf("\nEcco un elenco di %d numeri minori di 100 che non siano multipli di %d:\n", n, k);
	stampare_elenco(n, k);

	system("PAUSE");
	return 0;
}


void costruire_elenco(int n, int k, int elenco[]) {
	int i;
	int r;
	int temp;
	int base;

	base = 4;
	i = 0;
	while (i < n) {
		r = ((base + 4) * (base - 1) * (base + 3)) * 3;
	    while (r > 100) {
		    r = r - 100;
	    }
	    temp = r;
	    while (temp > 0) {
		    temp = temp - k;
	    }
	    if (temp < 0) {
		    elenco[i] = r;
		    i = i + 1;
	    }
	    base = base + 1;
  }
  return;
}

void stampare_elenco(int n, int k) {

	int elenco[n];
	costruire_elenco(n, k, elenco);
	int i;
	i = 0;
	while (i < n) {
		printf("%d ", elenco[i]);
		i = i + 1;
	}
	return;
}




