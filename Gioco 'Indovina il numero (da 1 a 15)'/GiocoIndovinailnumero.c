#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    int NumeroSegreto; // Numero casuale da indovinare
    int NumeroPensato; // Numero inserito dall'utente

    // Generazione del numero casuale
    srand(time(NULL));
    NumeroSegreto = rand() % 15 + 1;

    printf("\n\nGIOCHIAMO INSIEME: INDOVINA UN NUMERO DA 1 A 15. HAI 4 TENTATIVI\n\n");

    int i = 1; // Contatore per i tentativi
    while (i <= 4) { // Mantieni il ciclo per i 4 tentativi
        printf("\nTentativo numero %d: ", i);
        scanf("%d", &NumeroPensato);

        // Se il numero inserito è corretto
        if (NumeroPensato == NumeroSegreto) {
            printf("HAI VINTO!! (-;\n\n");

            // Pausa per evitare la chiusura immediata
            while (getchar() != '\n'); // Pulizia buffer

            getchar();
            break; // Esci dal ciclo se hai vinto
        } else if (NumeroPensato > NumeroSegreto) {
            printf("\nAlto, riprova\n");
        } else {
            printf("\nBasso, riprova\n");
        }

        i++; // Incrementa il contatore dei tentativi
    }

    // Se hai esaurito i tentativi senza vincere
    if (NumeroPensato != NumeroSegreto) {
        printf("\nHAI PERSO... Il numero segreto era %d.\n", NumeroSegreto);
    }

    printf("\nFine del gioco.\n");
    system("PAUSE"); // Pausa finale su Windows
    return 0;
}
