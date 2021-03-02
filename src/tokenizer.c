#include <stdio.h>
#include <stdlib.h>

int space_char(char c){
  if(c == ' ' || c == '\t' || c == '\n') return 1;
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
  char* ptr = (char *)malloc(sizeof(char) * (len + 1));
  for(int i = 0; i < len && src[i] != '\0'; i++){
    ptr[i] = src[i];
  }
  ptr[len] = '\0';
  return ptr;
}

void print_tokens(char **toks){
  while(**toks != '\0'){
    char *tmp = &**toks;
    while(*tmp != '\0'){
      printf("%c", *tmp);
      tmp += 1;
    }
    printf("\n");
    toks += 1;
  }
}

void free_tokens(char **toks){
  while(**toks != '\0'){
    free(*toks);
    toks += 1;
  }
  free(*toks);
  free(toks);
}

void main(){
  char *toks[3];
  char arr[6] = "hello\0";
  char arr2[6] = "world\0";
  char arr3[2] = "\0";
  toks[0] = &arr[0];
  toks[1] = &arr2[0];
  toks[2] = &arr3[0];
  print_tokens(toks);
}
