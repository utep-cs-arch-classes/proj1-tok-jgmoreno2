#include <stdio.h>

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

void main(){
  char arr[12];
  arr[0] = 'h';
  arr[1] = 'e';
  arr[2] = 'l';
  arr[3] = 'l';
  arr[4] = 'o';
  arr[5] = ' ';
  arr[6] = 'w';
  arr[7] = 'o';
  arr[8] = 'r';
  arr[9] = 'l';
  arr[10] = 'd';
  arr[11] = '\0';
  int count = count_words(&arr[0]);
  printf("%d", count);
}
