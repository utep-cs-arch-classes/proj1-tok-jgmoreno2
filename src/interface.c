#include <interface.c>
#include <stdio.h>

void interface(){
  printf("> ");
  char arr[100];
  char input;
  int i = 0;
  while(i < 100 && input != '\n'){
    input = getchar();
    arr[i] = input;
    i++;
    putchar(input);
  }
}