#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0


/*
la funzione convert, capovolge il numero, quindi 123 nella funzione convert diventa 321,
ma non ci interessa perché stiamo controllando se il numero é palindromo,
e i palindromi si leggono allo stesso modo sia in un verso che nell altro.
*/

void convert(int n, char str[]) {
  int i = 0;
  while(n>0) {
    str[i] = n%10 + '0';
    n = n/10;
    i = i + 1;
  }
  str[i] = '\0';
}

int isPalindrome(int n) {
  int i = 0;
  char str[10];
  convert(n, str);
  int lenght = strlen(str);
    while(i < lenght/2) {
      if (str[i] != str[lenght-i-1])
        return false;
      i = i + 1;
    }
  return true;
}

void findLargestPalindrome(int *largest){
  int i, j;
  i = 999;
  while(i>100) {
    j = 999;
      while(j>100) {
          if(isPalindrome(i*j) && i*j > *largest){
          *largest = i*j;
      }
        j = j - 1;
    }
      i = i - 1;
  }
}


int main(){
  int largest = 0;
  findLargestPalindrome(&largest);
  printf("%d\n", largest);
  return 0;
}
