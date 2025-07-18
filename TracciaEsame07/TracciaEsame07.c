/*Realizzare una funzione che riceve come parametri di input una sequenza di caratteri, ed elimini i caratteri
 contigui ripetuti, spostando a sinistra gli elementi restanti.*/

#include <stdio.h>
#include <stdlib.h>

void EliminaContigui(char Sequenza[], int Dimensione);

int main() {

	char Sequenza[6];
	Sequenza[0] = 'D';
	Sequenza[1] = 'D';
	Sequenza[2] = 'L';
	Sequenza[3] = 'U';
	Sequenza[4] = 'Z';
	Sequenza[5] = 'Z';

	int Dimensione = 6;

	printf("Sequenza priva dei caratteri contigui ripetuti: ");
	EliminaContigui(Sequenza, Dimensione);

	system("PAUSE");
	return 0;
}


void EliminaContigui(char Sequenza[], int Dimensione) {
	     Dimensione = 6;
	     int i = 0;
	     int temp;
	     while(i < Dimensione) {
	    	 if(Sequenza[i] == Sequenza[i+1]) {
	    		 temp = i;
	    		 while(temp < Dimensione - 1) {
	    			 Sequenza[temp] = Sequenza[temp+1];
	    			 temp = temp + 1;
	    		 }
	    	 Dimensione = Dimensione - 1;
	    	 }
	     i = i + 1;
	     }
  i = 0;
  while(i < Dimensione) {
	  printf("%c", Sequenza[i]);
	  i = i + 1;
  }
     printf("\n");

   return;
}
