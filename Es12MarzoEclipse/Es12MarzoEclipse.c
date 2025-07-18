   /*
  Autore                : Nicola Cialdella
  Data Inizio           : 20/03/2025
  Nome File             : Es12MarzoEclipse.c
  Scopo                 : Il programma legge i dati degli studenti dal file di input "StudentiEclipse.txt".
                          Ogni riga del file contiene:
                          <nome> <cognome> <matricola> <voto1> [<voto2> <voto3>]
                          dove la matricola è composta da 5 cifre e al massimo sono presenti tre voti.
                          Il programma calcola per ogni studente la media dei voti e individua:
                          - lo studente con la media migliore;
                          - lo studente con il voto massimo ottenuto in un esame;
                          - lo studente che ha sostenuto più esami.
                          Inoltre, il programma permette all'utente di visualizzare sullo schermo eventualmente solo
                          i dati di uno specifico studente ricevendo in input da tastiera il cognome dello studente.
  Assunzioni            : Il file di input è formattato correttamente e i dati sono separati da spazi.
  Note sugli algoritmi  :
                          - La lettura dal file avviene tramite ftgets() e strtok().
                          - I dati vengono memorizzati in strutture (Esame e Studente) per facilitarne l'elaborazione.

  Modifiche             : nessuna (versione iniziale).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* Dichiarazione della struttura Esame */
typedef struct {
	char *nome; /* Nome dell'esame */
	int voto;   /* Voto ottenuto nell'esame */
	int cfu;    /* numero di CFU conseguiti con l'esame */
} Esame;

/* Dichiarazione della struttura Studente */
typedef struct {
	char *nome; /* Nome dello studente */
	char *cognome; /* Cognome dello studente */
	char matricola[6]; /* Matricola (5 cifre + terminatore '\0') */
	Esame esami[3];    /* Array degli esami sostenuti dallo studente */
	int num_esami;     /* Numero di esami sostenuti dallo studente */
} Studente;


/* Prototipi delle funzioni */

/* Funzioni d'accesso al tipo di dato Esame */

char *esame_nome_leggere(Esame esame);
int esame_voto_leggere(const Esame *esame);
int esame_cfu_leggere(Esame esame);
void esame_nome_scrivere(Esame *esame, const char *nuovo_nome);
void esame_voto_scrivere(Esame *esame, int nuovo_voto);
void esame_cfu_scrivere(Esame *esame, int nuovi_cfu);

/* Funzioni d'accesso al tipo di dato Studente */

char *studente_nome_leggere(Studente studente);
char *studente_cognome_leggere(Studente studente);
char *studente_matricola_leggere(Studente studente);

/* Funzioni per lettura da file, elaborazione e scrittura su file */

int studente_leggere_da_file(const char *filename, Studente studenti[], int *num_studenti);
float studente_media_calcolare(Studente studente);
int studente_voto_massimo_trovare(Studente studente);
void cognome_ricercare_da_file(Studente elenco[], int num_studenti);
void risultati_finali_scrivere_su_file(const char *filename, Studente studenti[], int num_studenti);

/* Funzione main */
int main() {

	Studente elenco[100];
	int num_studenti = 0;
	int i = 0;

    if (studente_leggere_da_file("StudentiEclipse.txt", elenco, &num_studenti) == 0)
    {
    	printf("Errore nella lettura del file StudentiEclipse.txt\n");
    	system("PAUSE");
    	return 1;
    }

    risultati_finali_scrivere_su_file("RisultatiEclipse.txt", elenco, num_studenti);

    printf(" Lettura completata: %d studenti letti.\n", num_studenti);
    printf(" Risultati scritti su RisultatiEclipse.txt.\n");

    /* Chiamata alla funzione di ricerca di uno studente per cognome */
    cognome_ricercare_da_file(elenco, num_studenti);

    /* Dealloca la memoria per i campi dinamici (nome e cognome) di ciascun studente */
    i = 0;
    while (i < num_studenti)
    {
    	free(elenco[i].nome);
    	free(elenco[i].cognome);
    	i = i + 1;
    }

	system("PAUSE");
	return 0;
}

/* Definizione delle funzioni */

/* Funzione d'accesso: esame_nome_leggere */
char *esame_nome_leggere(Esame esame) {
	return esame.nome;
}

/* Funzione d'accesso: esame_voto_leggere */
int esame_voto_leggere(const Esame *esame) {
	return esame->voto;
}

/* Funzione d'accesso: esame_cfu_leggere */
int esame_cfu_leggere(Esame esame) {
	return esame.cfu;
}

/* Funzione d'accesso: esame_nome_scrivere */
void esame_nome_scrivere(Esame *esame, const char *nuovo_nome) {
	strcpy(esame->nome, nuovo_nome);
	return;
}

/* Funzione d'accesso: esame_voto_scrivere */
void esame_voto_scrivere(Esame *esame, int nuovo_voto) {
	esame->voto = nuovo_voto;
	return;
}

/* Funzione d'accesso: esame_cfu_scrivere */
void esame_cfu_scrivere(Esame *esame, int nuovi_cfu) {
	esame->cfu = nuovi_cfu;
}

/* Funzione d'accesso: studente_nome_leggere */
char *studente_nome_leggere(Studente studente) {
	return studente.nome;
}

/* Funzione d'accesso: studente_cognome_leggere */
char *studente_cognome_leggere(Studente studente) {
	return studente.cognome;
}

/* Funzione d'accesso: studente_matricola_leggere */
char *studente_matricola_leggere(Studente studente) {
	return studente.matricola;
}

/* Funzione: studente_leggere_da_file */
int studente_leggere_da_file(const char *filename, Studente studenti[], int *num_studenti)
{
	FILE *fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("Errore nell'aprire il file %s\n", filename);
		return 0;
	}

    *num_studenti = 0;
    char line[200];

    while (fgets(line, sizeof(line), fp) != NULL)
    {
    	if (strlen(line) <= 1)
    		continue;

        char tempNome[15], tempCognome[15], tempMatricola[6];
        if (sscanf(line, "%14s %14s %5s", tempNome, tempCognome, tempMatricola) < 3)
           continue;

        studenti[*num_studenti].nome = (char*)malloc(strlen(tempNome) + 1);
        if (studenti[*num_studenti].nome == NULL)
        {
           printf("Errore di allocazione per il nome.\n");
           fclose(fp);
           return 0;
        }
        strcpy(studenti[*num_studenti].nome, tempNome);

        studenti[*num_studenti].cognome = (char*)malloc(strlen(tempCognome) + 1);
        if (studenti[*num_studenti].cognome == NULL)
        {
           printf("Errore di allocazione per il cognome.\n");
           fclose(fp);
           return 0;
        }
        strcpy(studenti[*num_studenti].cognome, tempCognome);

        strcpy(studenti[*num_studenti].matricola, tempMatricola);

        char *token;
        int cont = 0;
        token = strtok(line, " \t\n");
        while (token != NULL && cont < 3)
        {
        	token = strtok(NULL, " \t\n");
        	cont = cont + 1;
        }

        int numEsami = 0;
        while (token != NULL && numEsami < 3)
        {
        	int voto = atoi(token);
        	studenti[*num_studenti].esami[numEsami].voto = voto;
        	studenti[*num_studenti].esami[numEsami].cfu = 0;
        	studenti[*num_studenti].esami[numEsami].nome = NULL;
        	numEsami = numEsami + 1;
        	token = strtok(NULL, " \t\n");
        }
        studenti[*num_studenti].num_esami = numEsami;
        *num_studenti = *num_studenti + 1;
    }

    fclose(fp);
    return 1;

}

/* Funzione: studente_media_calcolare */
float studente_media_calcolare(Studente studente)
{
	int somma = 0;
	int i = 0;

	while (i < studente.num_esami)
	{
		somma = somma + studente.esami[i].voto;
		i = i + 1;
	}

    if (studente.num_esami == 0)
        return 0.0;

        return (float)somma / studente.num_esami;
}

/* Funzione: studente_voto_massimo_trovare */
int studente_voto_massimo_trovare(Studente studente)
{
	if(studente.num_esami == 0)
		return 0;
	int max = studente.esami[0].voto;
	int i = 1;
	while (i < studente.num_esami)
	{
       if (studente.esami[i].voto > max)
       {
    	   max = studente.esami[i].voto;
       }
	i = i + 1;
	}
return max;
}

/* Funzione: cognome_ricercare_da_file */
void cognome_ricercare_da_file(Studente elenco[], int num_studenti)
{
	char temp[15]; /* Variabile per memorizzare il cognome da cercare */
	int trovato = 0; /* Flag per indicare se lo studente è stato trovato */
	int i = 0; /* Indice per scorrere l'array degli studenti */

	/* Chiedo all'utente di inserire il cognome da cercare */
	printf("\n Inserisci il cognome dello studente di cui vuoi visualizzare i dati universitari: ");
	scanf("%14s", temp); /* Uso %14s per evitare overflow (15 - 1 per il terminatore) */

	/* Scorro l'array di studenti e confronto il cognome inserito con quello dello studente corrente */
	while(i < num_studenti)
	{
		if (strcmp(temp, elenco[i].cognome) == 0)
		{
			/* Studente trovato: stampa i dati */
			printf("\nNome: %s", elenco[i].nome);
			printf("\nCognome: %s", elenco[i].cognome);
			printf("\nMatricola: %s", elenco[i].matricola);
			printf("\nNumero di esami sostenuti: %d\n", elenco[i].num_esami);

			/* Stampo i voti degli esami */
			{
				int j = 0;
				while (j < elenco[i].num_esami)
				{
					printf("\nEsame %d - Voto %d", j + 1, elenco[i].esami[j].voto);
					j = j + 1;
				}
			}
		    printf("\n");
		    trovato = 1;
		}
	i = i + 1;
	}
    /* Se nessuno studente corrisponde al cognome inserito, stampo un messaggio */
	if (trovato == 0)
	{
		printf("\nNessuno studente con il cognome \"%s\" è stato trovato.\n", temp);
	}
return;
}

/* Funzione: risultati_finali_scrivere_su_file */
void risultati_finali_scrivere_su_file(const char *filename, Studente studenti[], int num_studenti)
{
	int i = 0;
	int indiceStudMedMigliore = 0;
	float mediaMigliore = studente_media_calcolare(studenti[0]);
	while (i < num_studenti)
	{
		float mediaCorrente = studente_media_calcolare(studenti[i]);
		if (mediaCorrente > mediaMigliore)
		{
			mediaMigliore = mediaCorrente;
			indiceStudMedMigliore = i;
		}
	i = i + 1;
	}

    i = 0;
    int indiceStudVotoMassimo = 0;
    int votoMassimo = studente_voto_massimo_trovare(studenti[0]);
    while (i < num_studenti)
    {
    	float votoCorrente = studente_voto_massimo_trovare(studenti[i]);
    	if (votoCorrente > votoMassimo)
    	{
    		votoMassimo = votoCorrente;
    		indiceStudVotoMassimo = i;
    	}
    i = i + 1;
    }

    i = 0;
    int indiceStudPiuEsami = 0;
    int numeroPiuEsami = studenti[0].num_esami;
    while(i < num_studenti)
    {
    	if(studenti[i].num_esami > numeroPiuEsami)
    	{
    		numeroPiuEsami = studenti[i].num_esami;
    		indiceStudPiuEsami = i;
    	}
        i = i + 1;
    }

    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
       printf("Errore nell'aprire il file di output &s\n", filename);
       return;
    }

    fprintf(fp, "Studente con la media migliore: %s %s (Matricola %s) con media %.2f\n",
        studenti[indiceStudMedMigliore].nome, studenti[indiceStudMedMigliore].cognome,
	    studenti[indiceStudMedMigliore].matricola, mediaMigliore);

    fprintf(fp, "Studente con il voto massimo ottenuto in un esame: %s %s (matricola %s) con voto %d\n",
        studenti[indiceStudVotoMassimo].nome, studenti[indiceStudVotoMassimo].cognome,
	    studenti[indiceStudVotoMassimo].matricola, votoMassimo);

    fprintf(fp, "Studente con più esami sostenuti: %s %s (matricola %s) con %d esami\n",
        studenti[indiceStudPiuEsami].nome, studenti[indiceStudPiuEsami].cognome,
	    studenti[indiceStudPiuEsami].matricola, numeroPiuEsami);

    fclose(fp);
}

