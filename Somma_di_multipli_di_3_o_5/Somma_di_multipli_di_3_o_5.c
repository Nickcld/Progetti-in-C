#include <stdio.h>
#include <stdlib.h>

int main() {
    int somma = 0;
    int i = 1;

    while (i < 1000) {
        if (i % 3 == 0 || i % 5 == 0) {
            somma = somma + i;
        }
        i++;
    }

    printf("Somma dei multipli di 3 o 5 inferiori a 1000 = %d\n", somma);
    getchar();
    system("PAUSE");
}
