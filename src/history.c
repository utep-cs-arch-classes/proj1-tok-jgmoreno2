#include "history.h"

List *init_history(){
  List *list = (List *)malloc(sizeof(List));
  list->root = NULL;
  return list;
}

void add_history(List *list, char *str){
  Item *item = (Item *)malloc(sizeof(Item));
  item->str = str;
  item->next = NULL;
  Item *ptr = list->root;
  if(ptr == NULL){
    item->id = 0;
    list->root = item;
  }
  else{
    int currId = 0;
    while(ptr != NULL && ptr->next != NULL){
      currId++;
      ptr = ptr->next;
    }
    item->id = currId;
    ptr->next = item;
  }
}

char *get_history(List *list, int id){
  Item *ptr = list->root;
  while(ptr->id != id){
    ptr = ptr->next;
  }
  return ptr->str;
}

void print_history(List *list){
  Item *ptr = list->root;
  do{
    printf("%d: %s\n", ptr->id, ptr->str);
    ptr = ptr->next;
  }while(ptr != NULL && ptr->next != NULL);
}

void free_history(List *list){
  
}
