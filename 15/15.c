/*Si realizzi un algoritmo per poter analizzare una sequenza di numeri. Letti N numeri interi, calcolare e visualizzare i seguenti risultati:
• quanti sono i numeri positivi, nulli e negativi
• quanti sono i numeri pari e dispari
• se la sequenza dei numeri inseriti è crescente, decrescente oppure né crescente né decrescente.*/


#include <stdio.h>
#include <stdlib.h>
const int N = 10;

//PROTOTIPI DELLE FUNZIONI
int individuare_positivi(int sequenza[]);
int individuare_nulli(int sequenza[]);
int individuare_negativi(int sequenza[]);
int pari(int n);
int individuare_pari(int sequenza[]);
int individuare_dispari(int sequenza[]);
int analizzare_ordine_crescente(int sequenza[]);
int analizzare_ordine_decrescente(int sequenza[]);


//FUNZIONE MAIN
int main() {

	int sequenza[10];

	printf("\nInserisci una sequenza di 10 numeri ed io ti dirò quanti numeri positivi, negativi, nulli, pari e dispari ci sono. Inoltre dirò se la sequenza è crescente o decrescente.\n");
	int i = 0;
	while (i < N) {
		scanf("%d", &sequenza[i]);
		i = i + 1;
	}

	int num_positivi = individuare_positivi(sequenza);
	int num_nulli = individuare_nulli(sequenza);
	int num_negativi = individuare_negativi(sequenza);
	int num_pari = individuare_pari(sequenza);
	int num_dispari = individuare_dispari(sequenza);

	printf("Ci sono %d numeri positivi, %d numeri nulli e %d numeri negativi. I numeri pari sono %d, mentre quelli dispari sono %d.\n", num_positivi, num_nulli, num_negativi, num_pari, num_dispari);

	int crescente = analizzare_ordine_crescente(sequenza);
	int decrescente = analizzare_ordine_decrescente(sequenza);

	if (crescente) {
	    printf("La sequenza è crescente.\n");
	} else if (decrescente) {
	    printf("La sequenza è decrescente.\n");
	} else {
	    printf("La sequenza non è nè crescente nè decrescente.\n");
	}


	system("PAUSE");
	return 0;
}


//FUNZIONI SECONDARIE DA RICHIAMARE NEL MAIN PER LA CORRETTA ESECUZIONE DEL PROGRAMMA RICHIESTO
int individuare_positivi(int sequenza[]) {
	int i;
	int num_positivi;

	num_positivi = 0;
	i = 0;
	while (i <= N - 1) {
		if (sequenza[i] > 0) {
			num_positivi = num_positivi + 1;
		}
	    i = i + 1;
	}
return num_positivi;
}


int individuare_nulli(int sequenza[]) {
	int i;
	int num_nulli;

	num_nulli = 0;
	i = 0;
	while (i <= N - 1) {
		if (sequenza[i] == 0) {
			num_nulli = num_nulli + 1;
		}
		i = i + 1;
	}
return num_nulli;
}


int individuare_negativi(int sequenza[]) {
	int i;
	int num_negativi;

	num_negativi = 0;
	i = 0;
	while (i <= N - 1) {
		if (sequenza[i] < 0) {
			num_negativi = num_negativi + 1;
		}
	    i = i + 1;
	}
return num_negativi;
}

int pari(int n) {
    int esito = 0;
    if (n < 0) {
        n = -n;
    }
    if (n == 0) {
        return 1;
    }
    while (n > 0) {
        n = n - 2;
        if (n == 0) {
            esito = 1;
        } else {
            esito = 0;
        }
    }
    return esito;
}

int individuare_pari(int sequenza[]) {
	int i;
	int num_pari;

	num_pari = 0;
	i = 0;
	while (i <= N - 1) {
		if (pari(sequenza[i]) == 1) {
			num_pari = num_pari + 1;
		}
	    i = i + 1;
	}
return num_pari;
}

int individuare_dispari(int sequenza[]) {
	int i;
	int num_dispari;

	num_dispari = 0;
	i = 0;
	while (i <= N - 1) {
		if (pari(sequenza[i]) == 0) {
			num_dispari = num_dispari + 1;
		}
	    i = i + 1;
	}
return num_dispari;
}

int analizzare_ordine_crescente(int sequenza[]) {
	int i;
	int esito;

	i = 0;
	esito = 1;
	while (i < N - 1 && esito == 1) {
		if (sequenza[i] >= sequenza[i+1]) {
			esito = 0;
		}
	    i = i + 1;
	}
return esito;
}

int analizzare_ordine_decrescente(int sequenza[]) {
	int i;
	int esito;

	i = 0;
	esito = 1;
	while (i < N - 1 && esito == 1) {
		if (sequenza[i] <= sequenza[i+1]) {
			esito = 0;
		}
	    i = i + 1;
	}
return esito;
}







