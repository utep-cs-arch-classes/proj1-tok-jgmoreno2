#include <stdio.h>

#define MAX 100

void main(){
  printf("Input: ");
  char input[MAX];
  fgets(input, MAX, stdin);
  printf("\nOutput: %s\n", input);
  return;
}
