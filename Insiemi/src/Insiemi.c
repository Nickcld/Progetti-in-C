

#include <stdio.h>
#include <stdlib.h>

int * Inersezione(int Insieme1[], int Insieme2[]);
int * Unione(int Insieme1[], int Insieme2[]);
int CercareElemento(int Insieme[], int e);

int main(void) {
	int A[100]; //primo elemento con cui giocare
	int B[100]; //
	int C[100]; //
	int D[100]; //

}



int CercareElemento(int Insieme[], int e) {
	int trovato; //indica se e appartiene a Insieme, booleano
	int i; //indica le posizioni di Insieme, naturale >0
	i=1;
	while((i<=Insieme[0]) && (trovato==0)) {
		if(e==Insieme[1]) {
			trovato=1;
		}
		i=i+1;
	}
	return trovato;

}

int * Inersezione(int Insieme1[], int Insieme2[]) {
	int i;
	int j;

	int I[100];
	i=1;
	j=1;
	while(i<=Insieme1[0]) {
		if (CercareElemento(Insieme2, Insieme1[i])==1) {
			I[j]=Insieme1[i];
			j=j+1;
		}
		i=i+1;

	}
	I[0]= j-1;
	return I;

}

int * Unione(int Insieme1[], int Insieme2[]) {
	int U[100];

	int i;
	int j;

	i=1;
	while(i<=Insieme1[0]) {
		U[i]=Insieme1[i];
		i=i+1;
	}

	i=1;
	j=Insieme1[0]+1;
	while(i<Insieme2[0]) {
		if (CercareElemento(U, Insieme2[i]==0)) {
			U[j]=Insieme2[i];
			j=j+1;
		}
        i=i+1;
	}
    U[0]=j-1;
    return U;
}
