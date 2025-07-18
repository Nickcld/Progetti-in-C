/*Considerando i termini della sequenza di Fibonacci, i cui valori non superano i quattro milioni,
  trova la somma dei termini di valore pari.*/

#include <stdio.h>
#include <stdlib.h>

int a = 0;
int b = 1;
int SommaDeiPari = 0;
int Tmp;

int main() {
	while(b < 4000000) {
	  Tmp = b;
	  b = a + b;
	  a = Tmp;
	    if(b % 2 == 0) {
	    	SommaDeiPari = SommaDeiPari + b;
	    }
	}
                printf("\n\n Somma dei numeri pari presenti in questa sequenza di Fibonacci = %d", SommaDeiPari);

getchar();
system("PAUSE");
}
