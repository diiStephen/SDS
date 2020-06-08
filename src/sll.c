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
