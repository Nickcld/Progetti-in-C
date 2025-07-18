#include "automa.h"
#include "utils.h"

int is_binary_string(const char* str);

int automa_riconoscitore(const char* parola) {
    /**********ALGORITMO DI CONTEGGIO**********
	int i;
    int length;
    int zeri_presenti;
    int uno_presenti;
    zeri_presenti = 0;
    uno_presenti = 0;
    length = string_length(parola);
    if (is_binary_string(parola)) {
    	i = 0;
    	while (i < length) {
    		if (parola[i] == '0') {
    			zeri_presenti = zeri_presenti + 1;
    		} else {
    			uno_presenti = uno_presenti + 1;
    		}
    	    i = i + 1;
    	}
    }
	if(pari(zeri_presenti) == 1 && pari(uno_presenti) == 0) {
		return 1;
	}
	return 0;
}*/

	int stato = 0; //stato iniziale dell'automa
	int i = 0;

	if (!is_binary_string(parola)) {
		return 0;
	}

	while (parola[i] != '\0') {
		if (parola[i] == '0') {
			if (stato == 0) {
				stato = 2; // si passa da 0_pari 1_pari a 0_dispari 1_pari
			} else if (stato == 1) {
				stato = 3; // si passa da 0_pari 1_dispari a 0_dispari 1_dispari
			} else if (stato == 2) {
				stato = 0; // si passa da 0_dispari 1_pari a 0_pari 1_pari
			} else if (stato == 3) {
				stato = 1; // si passa da 0_dispari 1_dispari a 0_pari 1_dispari
			}
		} else {
			if (stato == 0) {
				stato = 1; // si passa da o_pari 1_pari a 0_pari 1_dispari
			} else if (stato == 1) {
				stato = 0; // si passa da 0_pari 1_dispari a 0_pari 1_pari
			} else if (stato == 2) {
				stato = 3; // si passa da 0_dispari 1_pari a 0_dispari 1_dispari
			} else if (stato == 3) {
				stato = 2; // si passa da 0_dispari 1_dispari a 0_dispari 1_pari
			}
		}
	    i = i + 1;
	}


    return (stato == 1); // accetta solo se lo stato è 1 cioè 0_pari 1_dispari
}




