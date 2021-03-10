#include "tokenizer.c"
#include "history.c"
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
      arr[i] = '\0';
      break;
    }
  }
  List *list = init_history();
  printf("adding history");
  add_history(list, &arr[0]);
  printf("Tokenizing \"%s\"...\n", arr);
  char **toks = tokenize(&arr[0]);
  print_tokens(toks);
  printf("freeing tokens");
  free_tokens(toks);
  return;
}
