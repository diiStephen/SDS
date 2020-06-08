#include "sll.h"
#include<stdio.h>
#include<stdlib.h>

struct Node *init_node(void *d, struct Node *n) {

  struct Node *newest = NULL;
  if ((newest = malloc(sizeof(struct Node)))== 0)
    fprintf(stderr, "Error allocating memory for new node.\n");

  newest->data = d;
  newest->next = n;

  return newest;

}

void init_sll(struct sll *list) {
  list->size = 0;
  list->head = NULL;
  list->tail = NULL;
}

void dest_sll(struct sll *list) {
  while(list->size > 0)
    rm_first(list);
}

void* first(struct sll *list) {
  if(list->size == 0) {
    return NULL;
  } else {
    return list->head->data;
  }
}

void* last(struct sll *list) {
  if(list->size == 0) {
    return NULL;
  } else {
    return list->tail->data;
  }
}

void ins_first(struct sll *list, void *data) {
  list->head = init_node(data, list->head);
  if (list->size == 0)
    list->tail = list->head;
  list->size++;
}

void ins_last(struct sll *list, void *data) {
  struct Node *newest = init_node(data, NULL);
  if(list->size == 0)
    list->head = newest;
  else
    list->tail->next = newest;
  list->tail = newest;
  list->size++;
}

void* rm_first(struct sll *list) {
  if(list->size == 0) return NULL;
  struct Node *sav = list->head;
  list->head = list->head->next;
  if(--list->size == 0) list->tail = NULL;
  void *res = sav->data;
  free(sav);
  return res;
}
