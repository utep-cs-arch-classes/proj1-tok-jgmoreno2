#include <stdio.h>

void main(){
  printf("Input (enter '@' to exit): ");
  char input;
  while(input != '@'){
    input = getchar();
    printf("\nRecent entry: ");
    putchar(input);
    printf("\t");
  }
  return;
}
