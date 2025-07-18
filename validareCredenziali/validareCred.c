/*Realizzare un programma che chieda all'utente di iscriversi inserendo un username ed una password e indichi se sono validi o meno.
Deve esserci una soglia massima di tentativi, dopodichè, superata quella soglia, il programma deve stampare un messaggio di errore impedendo
l'accesso all'utente. Se le credenziali inserite sono valide, devono essere salvate su un file di testo.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TENTATIVI 3

int validareUsername(char username[]);
int carattereValidoUsername(char carattere);
int validarePassword(char password[]);


int main() {

    char username[50];
    char password[50];
    int tentativi;

    printf("\nBenvenuto! Inserisci una Password e un User-name per iscriverti.\n");

    tentativi = 0;
    while (tentativi < MAX_TENTATIVI) {
            printf("\nTentativo %d di %d\n", tentativi + 1, MAX_TENTATIVI);

            printf("Username: ");
            scanf("%s", username);

            printf("Password: ");
            scanf("%s", password);


            if (validareUsername(username) && validarePassword(password)) {

    	        FILE *file_out = fopen("credenziali.txt", "w");
    	        if (file_out == NULL) {
    	            printf("\nErrore nell'apertura del file. Impossibile salvare le credenziali.\n");
    	            return 1;
    	        }
    	        fprintf(file_out, "User-name: %s\n", username);
    	        fprintf(file_out, "Password: %s\n", password);

    	        fclose(file_out);
    	        printf("\nCredenziali salvate con successo in credenziali.txt.\n");
    	        system("PAUSE");
    	        return 0;
            } else {
    	          tentativi = tentativi + 1;
    	          if (tentativi < MAX_TENTATIVI) {
    	              printf("\nCredenziali non valide. Riprova.\n");
            }
            }
    }

    printf("\nHai superato il numero massimo di tentativi. Registrazione fallita.\n");

	system("PAUSE");
	return 1;
}

int validareUsername(char username[]) {
	int i;
	int dimensione;
	int usernameValidato;

	dimensione = strlen(username);
	if (dimensione >= 6) {
		usernameValidato = 1;
	} else {
		usernameValidato = 0;
		printf("\nL'user-name deve contenere un minimo di 6 caratteri.\n");
	}


	i = 0;
	while (i < dimensione && usernameValidato == 1) {
		if (carattereValidoUsername(username[i]) == 1) {
			i = i + 1;
		} else {
			usernameValidato = 0;
			printf("\nCarattere in %d° posizione non valido, l'user-name può contenere solo numeri o lettere minuscole.\n", i + 1);
		}
	}
	return usernameValidato;
}


int carattereValidoUsername(char carattere) {
	int valido;

	if ((carattere >= 'a' && carattere <= 'z') || (carattere >= '0' && carattere <= '9')) {
	        valido = 1;
	    } else {
	        valido = 0;
	    }
	    return valido;
}

int validarePassword(char password[]) {
	int i;
	int dimensione;
	int passwordValidata;
	int maiuscolaPresente;
	int numeroPresente;
	int specialePresente;

	dimensione = strlen(password);
		if (dimensione >= 8) {
			passwordValidata = 1;
		} else {
			passwordValidata = 0;
			printf("\nLa password deve contenere un minimo di 8 caratteri.\n");
		}

		maiuscolaPresente = 0;
        numeroPresente = 0;
        specialePresente = 0;
        i = 0;

        while (password[i] != '\0') {
               if (password[i] >= 'A' && password[i] <= 'Z') {
                   maiuscolaPresente = 1;
               } else if (password[i] >= '0' && password[i] <= '9') {
                   numeroPresente = 1;
               } else if (password[i] == '!' || password[i] == '@' || password[i] == '#' ||
                          password[i] == '$' || password[i] == '%' || password[i] == '&') {
                   specialePresente = 1;
               }
               i = i + 1;
           }

           if (maiuscolaPresente && numeroPresente && specialePresente) {
               passwordValidata = 1;
           } else {
               printf("\nPassword non valida. Deve contenere almeno una lettera maiuscola, un numero e un carattere speciale (!@#$%%&).\n");
               passwordValidata = 0;
           }
           return passwordValidata;
}










