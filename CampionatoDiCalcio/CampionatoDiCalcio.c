#include <stdio.h>
#include <stdlib.h>

#define NUM_SQUADRE 4
#define NUM_GIORNATE 5

int punti[NUM_SQUADRE][NUM_GIORNATE];
char squadre[NUM_SQUADRE][50] = {"Squadra1", "Squadra2", "Squadra3", "Squadra4"};

//creo le varie funzioni che mi serviranno nel main, mi suddivido il programma in "blocchi".


int risultato_casuale() {  //funzione che genera risultati casuali (o 0 o 1 o 2)
	return rand() % 3;
}

void InserisciRisultatiCasuali() {  //funzione che inserisce i risultati casuali nella matrice
	int g = 0; //inizializziamo il numero di giornate a 0
	while(g < NUM_GIORNATE) {
		int i = 0; //inizializziamo il numero di squadre a 0
		while(i < NUM_SQUADRE) {
			punti[i][g] = risultato_casuale();
			i = i + 1;
		}
	    g = g + 1;
	}
}


void CapolistaAllaGiornata(int giornata) {  //funzione che determina la capolista ad ogni giornata
	int max_punti = -1;
	int i = 0;

	while(i < NUM_SQUADRE) {
		if(punti[i][giornata] > max_punti) {
			max_punti = punti[i][giornata];
		}
		i = i + 1;
	}


	printf("Giornata %d: ", giornata + 1);


    i = 0;
	int first = 1; //stiamo considerando la prima squadra, quindi inizializziamo first a 1

	while(i < NUM_SQUADRE) {
		if(punti[i][giornata] == max_punti) {
			if(!first) {
				printf(" e ");
			}
		    printf("%s", squadre[i]);
		    first = 0; //non stiamo più considerando la prima squadra, quindi resetta first a 0
		}
	    i = i + 1; //vai alla prossima squadra
	}
	printf("\n");

}

//ora possiamo passare al main, in cui richiameremo le funzioni ausiliarie realizzate prima

int main() {
	srand(time(NULL));

	int i = 0, g = 0;
	while (i < NUM_SQUADRE) {
		g = 0;
		while(g < NUM_GIORNATE) {
			punti [i][g] = 0;
			g++;
		}
		i++;
	}

	InserisciRisultatiCasuali();

	//calcoliamo la capolista per ogni giornata

	g = 0;
	while(g < NUM_GIORNATE) {
		CapolistaAllaGiornata(g);
		g++;
	}

    system("PAUSE");
	return 0;
}





