#include <stdio.h>
#include <stdlib.h>

int main() {
    // Dichiarazioni delle variabili
    char Sequenza[100];  // Sequenza di caratteri separata da '-'
    int I;               // La base
    int L;               // Numero di numeri nella sequenza
    int j;               // Posizione del numero nella sequenza
    int Contenuto;       // Booleano che verifica che le cifre siano minori della base
    int PrimoNumero;     // Primo numero nella sequenza
    int SecondoNumero;   // Secondo numero nella sequenza
    int UltimoNumero;    // Ultimo numero nella sequenza
    int Max;             // Numero massimo

    // Impostazione della base (I) a 6
    I = 6;

    // Inizializzo j e Contenuto
    j = 1;

    // Verifica che tutte le cifre siano minori della base I
    while (j < L) {
        if (Sequenza[j] - '0' >= I) {  // Verifica che la cifra sia inferiore alla base
            Contenuto = 0;  // Se una cifra non è valida, imposto Contenuto a 0
            break;
        }
        j++;
    }


    // Estrazione dei numeri dalla sequenza, separati dal carattere '-'
    // Per semplificare, considero solo una sequenza di 3 numeri per il calcolo
    sscanf(Sequenza, "%d-%d-%d", &PrimoNumero, &SecondoNumero, &UltimoNumero);


    // Imposto Max come il primo numero
    Max = PrimoNumero;

    // Confronto con il secondo numero
    if (SecondoNumero > Max) {
        Max = SecondoNumero;
    }

    // Confronto con l'ultimo numero
    if (UltimoNumero > Max) {
        Max = UltimoNumero;
    }

    //Output
    printf("Contenuto: %d\n", Contenuto);
    if (Contenuto == 0) {
        // Caso in cui le cifre non sono valide per la base
        printf("Max = -1\n");
     Contenuto = 1;
     printf("Contenuto: %d\n", Contenuto);
    } else if (Contenuto == 1) {
        // Caso in cui le cifre sono valide per la base
        printf("Max = UltimoNumero\n");


    }

    return 0;

}


