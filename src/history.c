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
    item->id = 1;
    list->root = item;
  }
  else{
    int currId = 2;
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
  while(ptr != NULL){
    printf("%d: %s\n", ptr->id, get_history(list, ptr->id));
    ptr = ptr->next;
    if(ptr == NULL){
      break;
    }
  }
}

void free_history(List *list){
  Item *ptr = list->root;
  while(ptr != NULL){
    Item *last = ptr;
    ptr = ptr->next;
    free(last->str);
    free(last);
  }
  free(list);
}
