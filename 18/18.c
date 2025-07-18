/*Realizzare un programma che, dato in input un vettore di caratteri, individui e stampi il carattere che è seguito più frequentemente
dal carattere successivo in ordine alfabetico.*/

#include <stdio.h>
#include <stdlib.h>
#define DIM_ALFABETO 26


int successivo_alfabeto(char prima_lettera, char seconda_lettera, char alfabeto[]);
int ricorrenze_coppia(char vettore[], int dim_vettore, char alfabeto[], char l1, char l2);
char individuare_carattere(char vettore[], int dim_vettore, char alfabeto[]);

int main() {


	char alfabeto[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	char vettore[11] = {'b', 'c', 'l', 'd', 'k', 'b', 'c', 'o', 'p', 'b', 'c'};
	int dim_vettore = 11;

	char carattere_ricorrente = individuare_carattere(vettore, dim_vettore, alfabeto);
	printf("\nIl carattere seguito più frequentemente dal suo successivo in ordine alfabetico è %c.\n", carattere_ricorrente);


	system("PAUSE");
	return 0;
}

int successivo_alfabeto(char prima_lettera, char seconda_lettera, char alfabeto[]) {
	int i;
	char lettera_successiva;
	int esito;

	i = 0;
	while (i < DIM_ALFABETO) {
		if (alfabeto[i] == prima_lettera) {
			if (i == DIM_ALFABETO - 1) {
				lettera_successiva = alfabeto[0];
			} else {
				lettera_successiva = alfabeto[i+1];
			}
			if (seconda_lettera == lettera_successiva) {
				esito = 1;
			} else {
				esito = 0;
			}
		}
	    i = i + 1;
	}
return esito;
}

int ricorrenze_coppia(char vettore[], int dim_vettore, char alfabeto[], char l1, char l2) {
	int i;
	char primo;
	char secondo;
	int num_ricorrenze;

	i = 0;
	num_ricorrenze = 0;
	while (i < dim_vettore - 1) {
		primo = vettore[i];
		secondo = vettore[i + 1];
		if (primo == l1 && secondo == l2) {
			if (successivo_alfabeto(primo, secondo, alfabeto) == 1) {
				num_ricorrenze = num_ricorrenze + 1;
			}
		}
	    i = i + 1;
	}
return num_ricorrenze;
}

char individuare_carattere(char vettore[], int dim_vettore, char alfabeto[]) {
	int i;
	int max_ricorrenze;
	int ricorrenze_attuali;
	char carattere_ricorrente;

	max_ricorrenze = 0;
	carattere_ricorrente = vettore[0];
	i = 0;
	while (i < dim_vettore - 1) {
		ricorrenze_attuali = ricorrenze_coppia(vettore, dim_vettore, alfabeto, vettore[i], vettore[i + 1]);
		if (ricorrenze_attuali > max_ricorrenze) {
			max_ricorrenze = ricorrenze_attuali;
			carattere_ricorrente = vettore[i];
		}
	    i = i + 1;
	}
return carattere_ricorrente;
}






