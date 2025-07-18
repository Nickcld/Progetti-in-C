
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RIGHE 3
#define COLONNE 3


                                        /***Prototipi delle funzioni***/
void stampareTitolo();
void stampareMenu();
void stampareGriglia(char griglia[RIGHE][COLONNE]);
int trisRisolto(char matrice[RIGHE][COLONNE]);
int grigliaPiena(char griglia[RIGHE][COLONNE]);
void giocarePartita(char griglia[RIGHE][COLONNE]);

                                        /***Funzione main***/
int main() {
    srand(time(NULL));
    int scelta;

    char griglia[RIGHE][COLONNE] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    stampareTitolo();
    stampareMenu();
    scanf("%d", &scelta);

    if (scelta != 1 && scelta != 2) {
        printf("\nScelta non valida. Digita 1 per iniziare una nuova partita o 2 per uscire dal gioco.\n");
        return 1;
    }

    if (scelta == 1) {
        giocarePartita(griglia);
    } else {
        return 0;
    }

    system("PAUSE");
    return 0;
}

                                        /***Funzioni di stampa***/
void stampareTitolo() {
    printf("                                _________  ________  ___  ________      \n");
    printf("                               |\\___   ___\\\\   __  \\|\\  \\|\\   ____\\     \n");
    printf("                               \\|___ \\  \\_\\ \\  \\|\\  \\ \\  \\ \\  \\___|_    \n");
    printf("                                    \\ \\  \\ \\ \\   _  _\\ \\  \\ \\_____  \\   \n");
    printf("                                     \\ \\  \\ \\ \\  \\\\  \\\\ \\  \\|____|\\  \\  \n");
    printf("                                      \\ \\__\\ \\ \\__\\\\ _\\\\ \\__\\____\\_\\  \\ \n");
    printf("                                       \\|__|  \\|__|\\|__|\\|__|\\_________\\\n");
    printf("                                                            \\|_________|\n");
}


void stampareMenu() {
	printf("\n        Benvenuto nel gioco del TRIS! premi 1 per iniziare una nuova partita o 2 per uscire dal gioco.\n");

}

void stampareGriglia(char griglia[RIGHE][COLONNE]) {
    int k;
    k = 0;
    while (k < 5) {
    	printf("\n");
    	k = k + 1;
    }

    printf("\n\n"); // Aggiunge un po' di spazio sopra la griglia
    printf("       %c | %c | %c \n", griglia[0][0], griglia[0][1], griglia[0][2]);
    printf("      ---|---|---\n");
    printf("       %c | %c | %c \n", griglia[1][0], griglia[1][1], griglia[1][2]);
    printf("      ---|---|---\n");
    printf("       %c | %c | %c \n", griglia[2][0], griglia[2][1], griglia[2][2]);
    printf("\n");
}

                                        /***Funzioni per la risoluzione del tris***/
int trisRisolto(char matrice[RIGHE][COLONNE]) {
	int i;
	int j;
	int uguali; //tiene traccia dei simboli uguali individuati in una riga/colonna/diagonale
	int risolto = 0;

	//controllo delle colonne
	j = 0;
	while (j < COLONNE) {
		i = 0;
		uguali = 0;
		while (i < RIGHE - 1) {
		    if (matrice[i][j] != ' ' && matrice[i][j] == matrice[i+1][j]) {
			    uguali = uguali + 1;
		    }
		    i = i + 1;
	    }
		if (uguali == 2) {
			risolto = 1;
		}
		j = j + 1;
	}

	//controllo delle righe
	i = 0;
	while (i < RIGHE) {
		j = 0;
		uguali = 0;
		while (j < COLONNE - 1) {
	        if (matrice[i][j] != ' ' && matrice[i][j] == matrice[i][j+1]) {
		        uguali = uguali + 1;
			    }
			    j = j + 1;
		    }
		if (uguali == 2) {
			risolto = 1;
		}
		i = i + 1;
	}

	//controllo della diagonale principale
	i = 0;
	j = 0;
	uguali = 0;
	while (i < RIGHE - 1 && j < COLONNE - 1) {
		if (matrice[i][j] != ' ' && matrice[i][j] == matrice[i+1][j+1]) {
			uguali = uguali + 1;
		}
		i = i + 1;
		j = j + 1;
	}
	if (uguali == 2) {
		risolto = 1;
	}

    //controllo della diagonale secondaria
	i = 0;
	j = COLONNE - 1;
	uguali = 0;
	while (i < RIGHE - 1 && j > 0) {
		if (matrice[i][j] != ' ' && matrice[i][j] == matrice [i+1][j-1]) {
			uguali = uguali + 1;
		}
	    i = i + 1;
	    j = j - 1;
	}
    if (uguali == 2) {
    	risolto = 1;
    }


    return risolto;
}

int grigliaPiena(char griglia[RIGHE][COLONNE]) {
	int piena;
	int i;
	int j;

	piena = 1;
	i = 0;
	while (i < RIGHE) {
		j = 0;
		while (j < COLONNE) {
			if (griglia[i][j] == ' ') {
				piena = 0;
			}
		    j = j + 1;
		}
	    i = i + 1;
	}
	return piena;
}


void giocarePartita(char griglia[RIGHE][COLONNE]) {

     int i; //righe
	 int j; //colonne
	 char utente;
	 char macchina;
	 int turno; // 0 = giocatore, 1 = computer
	 int finePartita;

	 printf("\n Scegli il simbolo con cui vuoi giocare: X oppure O?\n");
	 scanf(" %c", &utente);
	 while (utente != 'X' && utente != 'O') { //ciclo per forzare l'utente a inserire un simbolo valido, altrimenti la partita non inizia
		 printf("\nSimbolo non valido. Inserisci o X oppure O.\n");
		 scanf(" %c", &utente);
	 }
	 if (utente == 'X') {
		 macchina = 'O';
	 } else {
		 macchina = 'X';
	 }

	 stampareGriglia(griglia);
     finePartita = 0;
     turno = 0;
     while (!finePartita) {
    	 if (turno == 0) {
    	     printf("\nDigita la riga della casella che vuoi riempire (es. 2): ");
    	     scanf("%d", &i);
    	     printf("\nDigita la colonna della casella che vuoi riempire (es. 3): ");
    	     scanf("%d", &j);
    	     if (i < 1 || i > 3 || j < 1 || j > 3) {
    	    	 printf("\nCoordinate non valide. Inserisci valori compresi tra 1 e 3.\n");
    	    	 continue;
    	     }
    	     i = i - 1;
    	     j = j - 1;
    	     if (griglia[i][j] == ' ') {
    		     griglia[i][j] = utente;

    		     stampareGriglia(griglia);

    		     if (trisRisolto(griglia) == 1) {
    		         finePartita = 1;
    		         printf("\nHai vinto, complimenti!!!\n");
    		     } else if (grigliaPiena(griglia)) {
    		    	 finePartita = 1;
    		    	 printf("\nPareggio! Nessuno ha vinto.\n");
    		     } else {
    		    	 turno = 1;
    		     }

    	     } else {
    		     printf("\nCasella già riempita. Scegline un'altra.\n");
    		     turno = 0;
    	     }
    	 } else {
             i = rand() % 3;
             j = rand() % 3;
             if (griglia[i][j] == ' ') {
                 griglia[i][j] = macchina;

                 stampareGriglia(griglia);

                 if (trisRisolto(griglia) == 1) {
                     finePartita = 1;
                     printf("\nHai perso :'( \n");
                 } else if (grigliaPiena(griglia)) {
                	    finePartita = 1;
                	    printf("\nPareggio! Nessuno ha vinto.\n");
                 } else {
                	 turno = 0;
                 }

             } else {
                   do {
            	     i = rand() % 3;
            	     j = rand() % 3;
                   } while (griglia[i][j] != ' ');

                   griglia[i][j] = macchina;

                   stampareGriglia(griglia);

                   if (trisRisolto(griglia) == 1) {
                       finePartita = 1;
                       printf("\nHai perso :'( \n");
                   } else {
                         turno = 0; // Passa il turno al giocatore
                   }
             }
         }
     }
}




































































