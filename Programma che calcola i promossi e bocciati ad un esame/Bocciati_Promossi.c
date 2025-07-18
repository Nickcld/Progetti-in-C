#include <stdio.h>
#include <stdlib.h>

//la funzione main inizia l'esecuzione del programma
int main(void){
	//inizializza le variabili nelle definizioni
	int promozioni = 0;
	int bocciature = 0;
	int studenti = 1;

	//processa 10 studenti usando un ciclo controllato da contatore
	while(studenti<=10) {
		//richiedi all'utente un valore in ingresso
		printf("%s", "Inserisici risultato (1=promosso,2=bocciato): ");
		int risultato = 0; //risultato di un esame
		scanf("%d", &risultato);

		//se il risultato è 1, incrementa il numero di promozioni
		if(risultato==1) {
			promozioni = promozioni+1;
		} //fine di if
		else { //altrimenti, incrementa il numero di bocciature
		   bocciature = bocciature+1;
		} //fine di else
		studenti = studenti+1; //incrementa il contatore degli studenti
	} //fine di while

	// fase di terminazione; stampa i risultati
	printf("Promossi %d\n", promozioni);
	printf("Bocciati %d\n", bocciature);

	// se sono stati promossi più di 8 studenti, stampa "Bonus all'insegnante!"
	if (promozioni>8) {
		printf("Bonus all'insegnante!");
	} //fine di if

	system("PAUSE");
} //fine della funzione main
