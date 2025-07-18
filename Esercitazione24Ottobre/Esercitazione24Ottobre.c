/*Realizzare una funzione che riceve come parametri di input due numeri interi n
> 0 e k > 1 e costruisce un elenco A di n numeri interi casuali minori di 100 che
non siano multipli di k.*/

#include <stdio.h>
#include <stdlib.h>
#define VERO 1
#define FALSO 0


int main() {

    int Elenco[7];
    int n = 7;
    int k = 3;
    int random = (n + 4 * (n + 6)) * 2 + (n * 1);
    int i;


  CostruisciElenco(Elenco, n, random);

       printf("Elenco: ");
          i = 0;
            while(i < n) {
            printf("%d ", Elenco[i]);
            i = i + 1;
            }

                printf("\n");

    system("PAUSE");
    return 0;
}


int Multiplo(int num, int k) {
    while(num >= k) {
        num = num - k;
    }
         if(num == 0) {
            return VERO;
         }
   return FALSO;
}

void CostruisciElenco(int Elenco[], int n, int random) {
         int k = 3;
         int i = 0; //Indice che scorre l'elenco da creare
         random = (n + 4 * (n + 6)) * 2 + (n * 1);
         n = 7;

        while(i < n) {
            if(random < 100 && !Multiplo(random, k)) {
                Elenco[i] = random;
                i = i + 1;
            }
            random = random * 2 + 3;
            while(random > 100) {
            random = random - 100;
            }

        }
    return;
}
