#include <stdio.h>
#define LIMIT 100
char arr[LIMIT];

void main(){
  int i = 0;
  for(char input; (input = getchar()) != '\n' && i < LIMIT; i++){
    arr[i] = input;
    putchar(input);
  }
  printf("\n");
}
