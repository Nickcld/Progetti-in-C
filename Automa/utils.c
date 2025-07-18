#include "utils.h"

int is_binary_string(const char* str) {
    int i;
    i = 0;
    int esito;
    esito = 1;
    while (str[i] != 0 && esito == 1) {
    	if (str[i] != '0' && str[i] != '1') {
    		esito = 0;
    	} else {
    		esito = 1;
    	}
        i = i + 1;
    }
	return esito;
}

int string_length(const char* str) {
    int length;
    length = 0;
    while (str[length] != '\0') {
    	length = length + 1;
    }
	return length;
}

int pari(int numero) {
	int esito;
	esito = 1;
    while (numero > 0) {
    	numero = numero - 2;
    }
    if (numero == 0) {
    	esito = 1;
    } else {
    	esito = 0;
    }
    return esito;
}
