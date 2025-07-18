/*Realizzare una funzione che riceve come parametro di input un array di n numeri interi ed un intero k>1, ed elimina
  dall'array tutti i multipli di k, spostando "a sinistra" gli elementi successivi.*/

#include <stdio.h>
#include <stdlib.h>
#define VERO 1
#define FALSO 0


int is_Multiplo(int num, int k);
void Elimina_Multiplo(int Array[], int Dimensione, int k);


int main() {

	int Array[6];
	Array[0] = 4;
	Array[1] = 12;
	Array[2] = 17;
	Array[3] = 20;
	Array[4] = 33;
	Array[5] = 9;

	int k = 3;
	int Dimensione = 6;

	Elimina_Multiplo(Array, Dimensione, k);

	system("PAUSE");
	return 0;
}


int is_Multiplo(int num, int k) {
	while(num >= k) {
		num = num - k;
	}
       if(num == 0) {
    	   return VERO;
       }
  return FALSO;
}

void Elimina_Multiplo(int Array[], int Dimensione, int k) {
	  k = 3;
	  Dimensione = 6;
	  int i = 0;
	  int temp;
	  while(i < Dimensione) {
		  if(is_Multiplo(Array[i], k)) {
			  temp = i;
			  while(temp < Dimensione - 1) {
				  Array[temp] = Array[temp+1];
				  temp = temp + 1;
			  }
		  Dimensione = Dimensione - 1;
		  } else {
			 i = i + 1;
	        }
	  }

printf("Array privo dei multipli di k: ");
  i = 0;
  while(i < Dimensione) {
	  printf(" %d ", Array[i]);
	  i = i + 1;
  }
	printf("\n");

return;
}

