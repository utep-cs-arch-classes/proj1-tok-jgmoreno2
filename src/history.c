#include "history.h"

// allocates memory for the list, populates the root with null, and returns a pointer to it
List *init_history(){
  List *list = (List *)malloc(sizeof(List));
  list->root = NULL;
  return list;
}

// adds a node to the end of the list
void add_history(List *list, char *str){

  // create memory for node and define it with what we know (str and next)
  Item *item = (Item *)malloc(sizeof(Item));
  item->str = str;
  item->next = NULL;

  // create a pointer to the root element
  Item *ptr = list->root;

  // if root is empty, place new element at root and set id to 1
  if(ptr == NULL){
    item->id = 1;
    list->root = item;
  } else{ // if root is not empty
    int currId = 2; // keeps track of current id

    // loop until the current node is empty or the next node is empty
    while(ptr != NULL && ptr->next != NULL){
      currId++;
      ptr = ptr->next;
    }

    //set the new node's id then the current node's next node as the new node
    item->id = currId;
    ptr->next = item;
  }
}

// returns a pointer to a node containing a desired id in the list
char *get_history(List *list, int id){
  Item *ptr = list->root;

  // move from root to the desired id
  while(ptr->id != id){
    ptr = ptr->next;
  }
  return ptr->str;
}

// prints all id: string pairs in the list
void print_history(List *list){
  Item *ptr = list->root;

  // move from root until the current node is empty, printing id: string pairs along the way
  while(ptr != NULL){
    printf("%d: %s\n", ptr->id, get_history(list, ptr->id));
    ptr = ptr->next;
    if(ptr == NULL){
      break;
    }
  }
}

// frees memory for strings, nodes, and the list created for history
void free_history(List *list){
  Item *ptr = list->root;

  // move from root until the current node is empty
  while(ptr != NULL){
    Item *last = ptr; // keeps track of the previous node

    // move forward and free the string and node space for the previous node
    ptr = ptr->next;
    free(last->str);
    free(last);
  }

  // free the list
  free(list);
}
