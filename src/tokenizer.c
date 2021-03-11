#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "tokenizer.h"

// return 1 if c is space character, else 0
int space_char(char c){
  if (c == ' ' || c == '\t' || c == '\n') return 1;
  return 0;
}

// return 1 if c is not space character, else 0
int non_space_char(char c){
  if(c != ' ' && c != '\t' && c != '\n') return 1;
  return 0;
}

// return the pointer of where the next seen word starts
char *word_start(char *str){
  while(space_char(*str) == 1){
    str++;
  }
  return str;
}

// return the pointer of where the current word ends (where space character is encountered)
char *word_end(char *str){
  while(non_space_char(*str) == 1 && *str != '\0'){
    str++;
  }
  return str;
}


// return the number of words in str
int count_words(char *str){
  int count = 0;

  //count the number of starts and finishes found in str
  while(str && *str != '\0'){
    str = word_start(str);
    str = word_end(str);
    count++;
  }
  return count;
}

// dynamically allocates memory for a string, copies another into it, and returns a pointer to the first letter in the string
char *copy_str(char *src, short len){
  char *ptr = (char *)malloc(sizeof(char) * (len + 1));
  for(int i = 0; i < len && src[i] != '\0'; i++){
    ptr[i] = src[i];
  }
  ptr[len] = '\0';
  return ptr;
}

// prints all tokens as a list
void print_tokens(char **toks){
  int i = 0;

  // loop until the list terminator is reached
  while(toks[i][0] != '\0'){
    int j = 0;

    // move through a word until the terminator is reached, printing each character before it
    while(toks[i][j] != '\0'){
      printf("%c", toks[i][j]);
      j++;
    }
    printf("\n");
    i++;
  }
}

// frees memory allocated by previous methods for each string in toks and toks itself
void free_tokens(char **toks){
  int i = 0;

  // loop until terminator is reached, freeing each word along the way
  while(1 == 1){
    if(toks[i][0] != '\0'){
      free(toks[i]);
      i++;
    }
    else{
      // free toks itself
      free(toks);
      break;
    }
  }
}

// creates a list of tokens from the original str
char **tokenize(char *s){
  int words = count_words(s); // # of words in str
  char **toks = (char **)malloc(sizeof(char **) * (words + 1));
  int last = 0; // keeps track of where the list ends

  // loop through each word
  for(int i = 0; i < words; i++){

    // grab the string between the start and end pointers inclusively and add a pointer to it in toks
    char *start = word_start(s);
    char *end = word_end(s);
    int length = (int)(end - start) + 1;
    toks[i] = copy_str(start, length);
    s += length;
    last = i + 1;
  }

  // create memory for pointer to terminator and store it as last element in toks
  char *term = (char *)malloc(sizeof(char *));
  *term = '\0';
  toks[last] = term;
  return toks;
}
