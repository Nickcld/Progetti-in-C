
#include<stdio.h>
#include<stdlib.h>

int main() {
    int Somma = 0;
	int i;
    long long int Prodotto;

	Prodotto = 1;
	i = 1;
	while(i < 10) {
	    Prodotto = Prodotto * i;
       i = i + 1;
	}

    printf("\n Prodotto fattoriale = %dll", Prodotto);

    int a = 3;
    int b = 6;
    int c = 2;
    int d = 8;
    int e = 8;
    int f = 0;
    int g = 0;

    Somma = a + b + c + d + e + f + g;

    printf("\n\n Somma delle cifre fattoriali = %d", Somma);

       return 0;
}

