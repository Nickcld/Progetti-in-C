/*Si assuma presente in memoria un vettore contenente le informazioni relative alle verbalizzazioni di un esame. Il vettore contiene le coppie
nome-voto. Ad esempio, il contenuto del vettore potrebbe essere il seguente:
(gianni 27) (marco 28) (luigi 20) (giovanni 25) (sergio 24) (luisa 29).
Realizzare il codice di un programma che riceve in input il vettore e stampi la media dei voti ottenuti dagli studenti ed il nome e il voto
dello studente col voto più alto. Se più studenti condividono il voto più alto basta stamparne uno.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definizione del tipo di dato Studente

typedef struct {
	char nome[20];
	int voto;
}Studente;

//Prototipi delle funzioni

int stud_voto_leggere(Studente* studente);
const char* stud_nome_leggere(const Studente* studente);
float media_voti_calcolare(Studente vettore_studenti[], int dimensione);
int voto_max_individuare(Studente vettore_studenti[], int dimensione);
void risultati_stampare(Studente vettore_studenti[], int dimensione);

//Funzione main

int main() {

	Studente vettore_studenti[6];
	int dimensione = 6;
	strcpy(vettore_studenti[0].nome, "gianni");
	vettore_studenti[0].voto = 27;
	strcpy(vettore_studenti[1].nome, "marco");
	vettore_studenti[1].voto = 28;
	strcpy(vettore_studenti[2].nome, "luigi");
	vettore_studenti[2].voto = 20;
	strcpy(vettore_studenti[3].nome, "giovanni");
	vettore_studenti[3].voto = 25;
	strcpy(vettore_studenti[4].nome, "sergio");
	vettore_studenti[4].voto = 24;
	strcpy(vettore_studenti[5].nome, "luisa");
	vettore_studenti[5].voto = 29;


	risultati_stampare(vettore_studenti, dimensione);

	system("PAUSE");
	return 0;
}

//Funzioni d'accesso al tipo di dato Studente

int stud_voto_leggere(Studente* studente) {
	return studente->voto;
}

const char* stud_nome_leggere(const Studente* studente) {
	return studente->nome;
}

//Funzioni per il calcolo della media dei voti e l'individuazione dello studente col voto più alto

float media_voti_calcolare(Studente vettore_studenti[], int dimensione) {
	int i;
	int somma_voti;
	float media_voti;

	i = 0;
	somma_voti = 0;
	while (i < dimensione) {
		somma_voti = somma_voti + stud_voto_leggere(&vettore_studenti[i]);
		i = i + 1;
	}
    media_voti = (float)somma_voti/dimensione;
    return media_voti;
}

int voto_max_individuare(Studente vettore_studenti[], int dimensione) {
	int i;
	int indice_stud_voto_max;

	i = 0;
	indice_stud_voto_max = i;
	while (i < dimensione - 1) {
		if (stud_voto_leggere(&vettore_studenti[indice_stud_voto_max]) < stud_voto_leggere(&vettore_studenti[i + 1])) {
			indice_stud_voto_max = i + 1;
		}
	    i = i + 1;
	}
	return indice_stud_voto_max;
}

//Funzione di stampa dei risultati

void risultati_stampare(Studente vettore_studenti[], int dimensione) {
	float media_voti = media_voti_calcolare(vettore_studenti, dimensione);
	printf("\nLa media dei voti ottenuta dagli studenti e' %.2f\n", media_voti);
    int indice_stud_voto_max = voto_max_individuare(vettore_studenti, dimensione);
    printf("\nLo studente che ha ottenuto il voto piu' alto all'esame e' %s, con voto %d, complimenti %s!\n", vettore_studenti[indice_stud_voto_max].nome, vettore_studenti[indice_stud_voto_max].voto, vettore_studenti[indice_stud_voto_max].nome);

return;
}








