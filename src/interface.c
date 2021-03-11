#include "tokenizer.c"
#include "history.c"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void main(){
  
  //create list
  List *hist = init_history();

  //loop until broken
  while(1 == 1){
    printf("Type string to be tokenized, \"!<id>\" to tokenize something from history, or \"!!\" to exit.\n> ");

    //start reading str
    char *str = (char *)malloc(sizeof(char *) * 100);
    char input;
    int i = 0; // tracks index
    int startsWithExclamation = 0; // tracks whether or not str starts with '!'
    int id = 0; //tracks the id from input
    int isValid = 1; // tracks whether or not the id input is valid

    //loop until broken
    while(1 == 1){
      input = getchar();

      //the following is done to clean out the getchar() function for the next str
      if(isValid == 0){
	if(input == '\n'){
	  break;
	} else{
	  continue;
	}
      }

      //if ID or exit command
      if(startsWithExclamation == 1){

	// if exit command "!!", exit
	if(i == 1 && input == '!'){
	  free_history(hist);
	  return;
	} else{ // if not exit command, it must be an ID
	  if(isdigit(input)){
	    printf("%c isdigit", input);
	    id *= 10;
	    id += (input - '0');
	  } else if(input == '\n'){ // if not digit but is new line
	    break;
	  }else{ // if not digit or new line, input is invalid
	    printf("\nInvalid id.");
	    isValid = 0;
	  }
	}
      } else{ // if '!' has not been seen at str[0]
	if(i == 0 && input == '!'){ // check if str[0] could be '!'
	  startsWithExclamation = 1;
	}
	if(input != '\n'){ // if not new line, place char into str
	  str[i] = input;
	  i++;
	} else{ // if new line, place terminator into str
	  str[i] = '\0';
	  break;
	}
      }
    }

    // if the input is not valid, skip all tokenizing
    if(isValid == 0){
      goto fin;
    }

    // if id has been tracked, set the str in that node as the str in question
    if(id != 0){
      str = get_history(hist, id);
    }

    // add str to history, tokenize str, print the tokenized list, and free the tokens
    add_history(hist, &str[0]);
    char **toks = tokenize(&str[0]);
    printf("\nTokenizing \"%s\"...\n", str);
    print_tokens(toks);
    free_tokens(toks);

    // show the history
  fin:
    printf("\nHistory:\n");
    print_history(hist);
    printf("\n\n");
  }
}
