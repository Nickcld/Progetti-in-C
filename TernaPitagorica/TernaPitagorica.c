#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0


int isTerna(int a, int b, int c) {
	if((a*a) + (b*b) == c*c) {
		return 1;
	}
        return 0;
}

int main() {
    int a, b, c;
    a = 1;
    while(a < 1000) {
    	b = 1;
    	while(b < 1000) {
    		c = 1000 - a - b;

    		if(isTerna(a,b,c)) {
    			printf("Prodotto abc = %d\n", a * b * c);
    			return 0;
    		}
    	    b = b + 1;

    	}
    	a = a + 1;
    }
    return 0;
}
