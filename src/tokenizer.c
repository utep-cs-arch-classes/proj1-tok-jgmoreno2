#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "tokenizer.h"

int space_char(char c){
  if (c == ' ' || c == '\t' || c == '\n') return 1;
  return 0;
}

int non_space_char(char c){
  if(c != ' ' && c != '\t' && c != '\n') return 1;
  return 0;
}

char *word_start(char *str){
  while(space_char(*str) == 1){
    str++;
  }
  return str;
}

char *word_end(char *str){
  while(non_space_char(*str) == 1 && *str != '\0'){
    str++;
  }
  return str;
}

int count_words(char *str){
  int count = 0;
  while(str && *str != '\0'){
    str = word_start(str);
    str = word_end(str);
    count++;
  }
  return count;
}

char *copy_str(char *src, short len){
  char *ptr = (char *)malloc(sizeof(char) * (len + 1));
  for(int i = 0; i < len && src[i] != '\0'; i++){
    ptr[i] = src[i];
  }
  ptr[len] = '\0';
  return ptr;
}

void print_tokens(char **toks){
  int i = 0;
  while(toks[i][0] != '\0'){
    int j = 0;
    while(toks[i][j] != '\0'){
      printf("%c", toks[i][j]);
      j++;
    }
    printf("\n");
    i++;
  }
}

void free_tokens(char **toks){
  int i = 0;
  while(1 == 1){
    if(toks[i][0] != '\0'){
      free(toks[i]);
      i++;
    }
    else{
      free(toks);
      break;
    }
  }
}

char **tokenize(char *s){
  int words = count_words(s);
  char **toks = (char **)malloc(sizeof(char **) * (words + 1));
  int last = 0;
  for(int i = 0; i < words; i++){
    char *start = word_start(s);
    char *end = word_end(s);
    int length = (int)(end - start) + 1;
    toks[i] = copy_str(start, length);
    s += length;
    last = i + 1;
  }
  char *term = (char *)malloc(sizeof(char *));
  *term = '\0';
  toks[last] = term;
  return toks;
}
