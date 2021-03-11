#include "tokenizer.c"
#include "history.c"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void main(){
  List *hist = init_history();
  while(1 == 1){
    printf("Type string to be tokenized, \"!<id>\" to tokenize something from history, or \"!!\" to exit.\n> ");
    char *str = (char *)malloc(sizeof(char *) * 100);
    char input;
    int i = 0;
    int startsWithExclamation = 0;
    int id = 0;
    int isValid = 1;
    while(1 == 1){
      input = getchar();
      if(isValid == 0){
	if(input == '\n'){
	  break;
	} else{
	  continue;
	}
      }
      if(startsWithExclamation == 1){
	if(i == 1 && input == '!'){
	  free_history(hist);
	  return;
	} else{
	  if(isdigit(input)){
	    printf("%c isdigit", input);
	    id *= 10;
	    id += (input - '0');
	  } else if(input == '\n'){
	    break;
	  }else{
	    printf("\nInvalid id.");
	    isValid = 0;
	  }
	}
      } else{
	if(i == 0 && input == '!'){
	  startsWithExclamation = 1;
	}
	if(input != '\n'){
	  str[i] = input;
	  i++;
	} else{
	  str[i] = '\0';
	  break;
	}
      }
    }
    if(isValid == 0){
      goto fin;
    }
    if(id != 0){
      str = get_history(hist, id);
    }
    add_history(hist, &str[0]);
    char **toks = tokenize(&str[0]);
    printf("\nTokenizing \"%s\"...\n", str);
    print_tokens(toks);
    free_tokens(toks);
  fin:
    printf("\nHistory:\n");
    print_history(hist);
    printf("\n\n");
  }
}
