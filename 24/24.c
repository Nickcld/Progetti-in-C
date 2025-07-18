/*Realizzare una funzione che riceve come parametri di input una sequenza di caratteri, ed elimini i caratteri contigui ripetuti,
spostando a sinistra gli elementi restanti.*/

#include <stdio.h>
#include <stdlib.h>

int eliminare_contigui_ripetuti(char sequenza[], int dimensione);

int main() {

	char *sequenza;
	int dimensione;
	int i;

	printf("\nQuanti caratteri vuoi inserire?\n");
	scanf("%d", &dimensione);

	sequenza = (char*) malloc(dimensione * sizeof(char));

	printf("\nInserisci una sequenza di %d caratteri ed io eliminerò quelli contigui ripetuti.\n", dimensione);
	i = 0;
	while (i < dimensione) {
		scanf(" %c", &sequenza[i]);
		i = i + 1;
	}

	dimensione = eliminare_contigui_ripetuti(sequenza, dimensione);
	printf("\nEcco la sequenza priva dei caratteri contigui ripetuti:\n");
	i = 0;
	while (i < dimensione) {
		printf("%c", sequenza[i]);
		i = i + 1;
	}
	printf("\n");
	free(sequenza);

	system("PAUSE");
	return 0;
}


int eliminare_contigui_ripetuti(char sequenza[], int dimensione) {
	int i;
	int temp; //posizione del carattere da spostare

	i = 0;
	while (i < dimensione - 1) {
		if (sequenza[i] == sequenza[i + 1]) {
			temp = i + 1;
		    while (temp < dimensione - 1) {
		        sequenza[temp] = sequenza[temp + 1];
		        temp = temp + 1;
		    }
		    dimensione = dimensione - 1;
		} else {
			i = i + 1;
		}
	}
	return dimensione;
}






