#include "cll.h"
#include<stdio.h>
#include<stdlib.h>

node_t* create_node(node_t *n, void *d) {
  node_t *newest = malloc(sizeof(node_t));
  if(newest == NULL) {
    fprintf(stderr, "could not allocate memory for new node!\n");
    exit(1);
  }
  newest->next = n;
  newest->data = d;
  return newest;
}

void dest_node(node_t **n) {
  if (*n != NULL) {
    free(n);
    *n = NULL;
  }
}

void init_cll(cll_t *list) {
  memset(list, 0, sizeof(cll_t));
}

void dest_cll(cll_t *list) {
  while(size(l) > 0) {
    rm_first(list);
  }
}

void* first(cll_t *list) {
  if (size(l) == 0) return NULL;
  return list->tail->next->data;
}

void* last(cll_t *list) {
  if (size(l) == 0) return NULL;
  return list->tail->data;
}

void ins_first(cll_t *list, void *d) {
  node_t newest = create_node(NULL, d);
  if(size(l) == 0) {
    newest->next = newest; //Circular
    list->tail = newest;
  } else {
    newest->next = list->tail->next;
    list->tail->next = newest;
  }
  size++;
}

void ins_last(cll_t *list, void *d) {
  ins_first(list, d);
  list->tail = list->tail->next;
}

void rotate(cll_t *list) {
  if(list->tail != NULL)
    list->tail = list->tail->next;
}

void* rm_first(cll_t *list) {
  void *response = NULL;
  if(size(list) > 0) {
    node_t *sav = list->tail->next; // head of the list.
    list->tail->next = list->tail->next->next; // new head of the list.
    if(--list->size == 0) {
      list->tail = NULL;
    }
    response = sav->data;
    dest_node(&sav);
  }
  return response;
}
