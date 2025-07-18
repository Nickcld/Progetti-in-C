/*Data una parola P di n lettere, ottenere una nuova parola C in cui:

Le lettere in posizione dispari (1, 3, 5, …) sono sostituite con la lettera posta due posizioni avanti nell’alfabeto.
Le lettere in posizione pari (2, 4, 6, …) sono sostituite con la lettera posta una posizione indietro nell’alfabeto.
L’alfabeto è considerato come una struttura circolare.*/

#include <stdio.h>
#include <stdlib.h>
#define VERO 1
#define FALSO 0

void CifraturaParola(char P[], int LunghezzaP, char Alfabeto[], int LunghezzaAlfabeto, char C[]);

int main() {

	char P[10] = {'P', 'R', 'O', 'G', 'R', 'A', 'M', 'M', 'A', '\0'};
	int LunghezzaP = 10;
	char C[10];
	char Alfabeto[21] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'Z'};
	int LunghezzaAlfabeto = 21;

	CifraturaParola(P, LunghezzaP, Alfabeto, LunghezzaAlfabeto, C);

	printf("\n Parola originale: %s\n", P);
	printf("\n Parola cifrata: %s\n", C);


	system("PAUSE");
	return 0;
}

int isPari(int num) {
	while(num > 0) {
		num = num - 2;
	}
      if(num == 0) {
    	  return VERO;
      }
  return FALSO;
}

int isDispari(int num) {
	while(num > 0) {
		num = num - 2;
	}
      if(num != 0) {
    	  return VERO;
      }
  return FALSO;
}


void CifraturaParola(char P[], int LunghezzaP, char Alfabeto[], int LunghezzaAlfabeto, char C[]) {
	 int i; //indice per scorrere la parola P
	 int j; //indice per scorrere l'alfabeto
	 int s = 0; //individua la posizione dei nuovi elementi della parola cifrata C
     LunghezzaAlfabeto = 21;
	 i = 0;
	 while(P[i] != '\0') {
		 	j = 0;
		    while(j < LunghezzaAlfabeto) {
			    if(P[i] == Alfabeto[j]) {
				    if(isPari(i)) {
				    	C[s] = Alfabeto[j - 1];
				    	if(P[i] == 'A') {
				    		C[s] = Alfabeto[20];
				    	}
				    }  else if(isDispari(i)) {
				    	 C[s] = Alfabeto[j + 2];
				       }
		        s = s + 1;
		        }
		    j = j + 1;
		    }
	  i = i + 1;
	  }

	 C[s] = '\0';
     return;
}










