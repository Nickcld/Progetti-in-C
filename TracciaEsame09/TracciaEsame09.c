/*Dati in input due array di numeri floating point: A composto da n numeri disposti in ordine crescente e B
  composto da m numeri disposti in ordine casuale, inserire al centro di A i numeri presenti in B mantenendo l'ordine
  crescente senza l'uso di un terzo array di appoggio.*/


#include <stdio.h>
#include <stdlib.h>

// Prototipi delle funzioni
void spostareElementi(float A[], int numElementi_A, int numElementi_B);
void inserireElementi(float A[], float B[], int dimensioneB);
void riordinareElementi(float A[], int dimensioneA);
void stampareVettore(float A[], int dimensioneA);

int main() {

float A[10] = {1, 4, 9, 12, 18, 25};
float B[4] = {13, 10, 3, 22};
int dimensioneA = 10;
int dimensioneB = 4;
int numElementi_A = 6;
int numElementi_B = 4;

spostareElementi(A, numElementi_A, numElementi_B);
inserireElementi(A, B, dimensioneB);
riordinareElementi(A, dimensioneA);

printf("\n Vettore contenente gli elementi di A e di B disposti in ordine crescente: \n");
printf("\n ");
stampareVettore(A, dimensioneA);


system("PAUSE");
return 0;
}

void spostareElementi(float A[], int numElementi_A, int numElementi_B) {
    int i = numElementi_A - 1;
    while (i >= 0) {
        A[i + numElementi_B] = A[i];
        i = i - 1;
    }
return;
}

void inserireElementi(float A[], float B[], int dimensioneB) {
     int i = 0; //scorre gli elementi di A
     int j = 0; //scorre gli elementi di B
     while (i < dimensioneB && j < dimensioneB) {
         A[i] = B[j];
         i = i + 1;
         j = j + 1;
     }
return;
}

void riordinareElementi(float A[], int dimensioneA) {
     int i;
     int temp;
     int passate = 0;
     while (passate < dimensioneA - 1) {
        i = 0;
        while (i < dimensioneA - 1 - passate) {
            if (A[i] > A[i + 1]) {
                temp = A[i];
                A[i] = A[i + 1]; //effettuo lo scambio in caso l'elemento in posizione i sia maggiore del suo adiacente successivo
                A[i + 1] = temp;
            }
        i = i + 1;
        }
    passate = passate + 1;
    }
return;
}

void stampareVettore(float A[], int dimensioneA) {
    int i = 0;
    while (i < dimensioneA) {
        printf("%.2f ", A[i]);
        i = i + 1;
    }
return;
}

