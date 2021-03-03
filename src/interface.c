#include "tokenizer.c"
#include "tokenizer.h"
#include <stdio.h>

void main(){
  printf("> ");
  char arr[100];
  char input;
  int i = 0;
  while(i < 100){
    input = getchar();
    if(input != '\n'){
      arr[i] = input;
      i++;
    }
    else{
      break;
    }
  }
  printf("Tokenizing \"%s\"...\n", arr);
  char **toks = tokenize(&arr[0]);
  print_tokens(toks);
  return;
}
