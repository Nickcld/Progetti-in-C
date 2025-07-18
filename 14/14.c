/*Leggere in input un elenco E di numeri interi compresi tra 18 e 90, estremi inclusi, contenente almeno 10 elementi. Considerare i controlli
sugli input. Calcolare il valore di E più presente e quello meno presente in E. Visualizzare i risultati ottenuti. Esempio:
E = (19, 23, 25, 67, 19, 67, 25, 19, 25, 19)
Valore più presente = 19
Valore meno presente = 23*/

#include <stdio.h>
#include <stdlib.h>
#define DIMENSIONE 10

// Prototipi delle funzioni
int calcolare_ricorrenze(int elenco[], int n);
int ricerca_valore_piu_presente(int E[]);
int ricerca_valore_meno_presente(int E[]);

int main() {

	int E[DIMENSIONE];
    printf("\nInserisci un elenco di %d numeri compresi tra 18 e 90.\n", DIMENSIONE);
    printf("Io calcolerò qual è il valore più presente e quale il meno presente.\n\n");

    int i = 0;
    while (i < DIMENSIONE) {
        printf("Inserisci il %d° valore: ", i + 1);
    	scanf("%d", &E[i]);
        // Controllo che l'input sia nel range corretto
    	if (E[i] >= 18 && E[i] <= 90) {
    	    i = i + 1;
        } else {
            printf("Attenzione: Il valore deve essere compreso tra 18 e 90. Riprova.\n");
        }
    }

    int valore_piu_presente = ricerca_valore_piu_presente(E);
    int valore_meno_presente = ricerca_valore_meno_presente(E);

    printf("\nRisultati:\n");
    printf("Il valore più presente nell'elenco è: %d\n", valore_piu_presente);
    printf("Il valore meno presente nell'elenco è: %d\n", valore_meno_presente);


	system("PAUSE");
	return 0;
}


int calcolare_ricorrenze(int elenco[], int n) {
	int i;
	int ricorrenze;

	ricorrenze = 0;
	i = 0;
	while (i < DIMENSIONE) {
		if (elenco[i] == n) {
			ricorrenze = ricorrenze + 1;
		}
	    i = i + 1;
	}
    return ricorrenze;
}


int ricerca_valore_piu_presente(int E[]) {
	int i;
	int valore_piu_presente;

    valore_piu_presente = E[0];
	i = 1;
	while (i < DIMENSIONE) {
		if (calcolare_ricorrenze(E, E[i]) > calcolare_ricorrenze(E, valore_piu_presente)) {
			valore_piu_presente = E[i];
		}
	    i = i + 1;
	}
    return valore_piu_presente;
}


int ricerca_valore_meno_presente(int E[]) {
	int i;
	int valore_meno_presente;

	valore_meno_presente = E[0];
	i = 1;
	while (i < DIMENSIONE) {
		if (calcolare_ricorrenze(E, E[i]) < calcolare_ricorrenze(E, valore_meno_presente)) {
			valore_meno_presente = E[i];
		}
	    i = i + 1;
	}
    return valore_meno_presente;
}






