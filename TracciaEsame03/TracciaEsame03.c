/*Si scriva una funzione che riceva in ingresso due parole di al massimo 30 caratteri e verifichi se
la seconda parola è contenuta almeno una volta all’interno della prima parola (ossia se la seconda
parola è una sottostringa della prima parola).*/

#include <stdio.h>
#include <stdlib.h>
#define VERO 1
#define FALSO 0

int is_Sottostringa(char Parola1[], char Parola2[], int Lunghezza1, int Lunghezza2);

int main() {

	char Parola1[13];
	Parola1[0] = 'P';
	Parola1[1] = 'S';
	Parola1[2] = 'E';
	Parola1[3] = 'U';
	Parola1[4] = 'D';
	Parola1[5] = 'O';
	Parola1[6] = 'C';
	Parola1[7] = 'O';
	Parola1[8] = 'D';
	Parola1[9] = 'I';
	Parola1[10] = 'C';
	Parola1[11] = 'E';
	Parola1[12] = '\0';

	char Parola2[7];
	Parola2[0] = 'C';
	Parola2[1] = 'O';
	Parola2[2] = 'D';
	Parola2[3] = 'I';
	Parola2[4] = 'C';
	Parola2[5] = 'E';
	Parola2[6] = '\0';

	int Lunghezza1 = 13;
	int Lunghezza2 = 7;

	if(is_Sottostringa(Parola1, Parola2, Lunghezza1, Lunghezza2) == VERO) {
		printf("\n La seconda parola è una sottostringa della prima.\n");
	} else {
		printf("\n La seconda parola non è una sottostringa della prima.\n");
	  }

	system("PAUSE");
	return 0;
}


int is_Sottostringa(char Parola1[], char Parola2[], int Lunghezza1, int Lunghezza2) {

	  int i; //indice che scorre Parola1
	  int j; //indice che scorre Parola2

	  i = 0;
	  while(i < Lunghezza1 - 2) {
		  j = 0;
		  while(j <= Lunghezza2 - 2) {
			  if(Parola2[j] == Parola1[i]) {
				  return VERO;
				  j = j + 1;
			  } else {
				  i = i + 1;
			  }
          }
	  }
  return FALSO;
}
