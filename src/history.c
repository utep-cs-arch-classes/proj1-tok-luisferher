#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List* init_history();
void add_history(List *list, char *str);
char *get_history(List *list, int id);
void print_history(List *list);
void free_history(List *list);

int main(){
}
List* init_history(){
  List *list = (List*) malloc(sizeof(List) * 1);
  list->root = NULL;
  return list;
}
void add_history(List *list, char *str){
  int i = 0;
  Item *item = list->root;
  while(item != NULL && item->next != NULL){
    i++;
    item = item->next;
  }
  Item* new = (Item*) malloc (sizeof(Item) * 1);
  new->str = str;
  new->id = i;
  new->next = NULL;
}
char *get_history(List *list,int id){
  Item* item = list->root;
  while(item != NULL && id > 0){
    id--;
    item = item->next;
  }
  return item->str;
}
void print_history(List *list){
  Item *item = list->root;
  while(item != NULL){
    printf("%d,%s\n", item->id, item->str);
    item = item->next;
  }
}
void free_history(List *list){
  list->root = NULL;
  free(list->root);
  free(list);
}
