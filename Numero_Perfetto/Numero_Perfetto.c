/*Un numero intero positivo n è definito perfetto se la somma dei suoi divisori propri (divisori escluso il numero
  stesso) è uguale al numero stesso. Esempio: 6 è un numero perfetto, perchè i suoi divisori propri sono 1, 2, 3 e la
  loro somma è 1 + 2 + 3 = 6. Scivi un algoritmo che calcoli quanti numeri perfetti ci sono da 1 a 100.*/

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int n = 1;
int SommaDivisori = 0;
int d = 1; //divisore

int isPerfetto(int n) {
    SommaDivisori = 0;  // Resetta la somma dei divisori ogni volta che controlli un nuovo numero
    d = 1;  // Resetta il divisore a 1 per ogni nuovo numero

    while (d < n) {
        if (n % d == 0) {
            SommaDivisori = SommaDivisori + d;
        }
        d = d + 1;  // Incrementa d
    }

    if (SommaDivisori == n) {
        return 1;  // Se la somma dei divisori è uguale al numero, è perfetto
    }
    return 0;  // Altrimenti, non è perfetto
}

int main() {
    int ContatoreNumeriPerfetti = 0;
    n = 1;

    while (n <= 100) {  // Continua a scorrere da 1 a 100
        if (isPerfetto(n)) {
            ContatoreNumeriPerfetti++;  // Incrementa il contatore se il numero è perfetto
        }
        n = n + 1;  // Incrementa n per passare al prossimo numero
    }

    printf("\nI numeri perfetti presenti nella lista da 1 a 100 sono %d\n", ContatoreNumeriPerfetti);
    return 0;
}
