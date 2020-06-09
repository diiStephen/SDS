#include "dll.h"
#include<stdio.h>
#include<stdlib.h>

node_t* new_node(node_t * p, node_t * n, void * d) {
  node_t *newest = malloc(sizeof(node_t));
  if(newest == NULL)
    fprintf(stderr, "Could not allocate memory for new node!\n");
  newest->prev = p;
  newest->next = n;
  newest->data = d;
  return newest;
}

void dest_node(node_t *node) {
  free(node);
}

//Note: This dll uses head and tail sentinel nodes.
void init_dll(dll_t *list) {
  list->size = 0;
  list->header = new_node(NULL, NULL, NULL); // head sentinel
  list->trailer = new_node(list->header, NULL, NULL); // tail sentinel
  list->header->next = list->trailer; // header -> trailer
}

void dest_dll(dll_t *list) {
  while(SIZE(list) > 0)
    rm_first(list);
  dest_node(list->header);
  dest_node(list->trailer);
  list->header = NULL;
  list->trailer = NULL;
}

int is_empty(dll_t *list) {
  return SIZE(list);
}

void* first(dll_t *list) {
  if(SIZE(list) > 0)
    return list->header->next->data;
  else
    return NULL;
}

void* last(dll_t *list) {
  if(SIZE(list) > 0)
    return list->trailer->prev->data;
  else
    return NULL;
}

void ins_btn(dll_t *list, node_t *pred, node_t *succ, void *d) {
  node_t *newest = new_node(pred, succ, d);
  pred->next = newest;
  succ->prev = newest;
  list->size++;
}

void ins_first(dll_t *list, void *d) {
  ins_btn(list, list->header, GET_NXT(list->header), d);
}

void ins_last(dll_t *list, void *d) {
  ins_btn(list, GET_PRV(list->trailer), list->trailer, d);
}

void* rm(dll_t *list, node_t *node) {
  void* res = node->data;
  node->prev->next = node->next;
  node->next->prev = node->prev;
  list->size--;
  dest_node(node);
  return res;
}

void* rm_first(dll_t *list) {
  return rm(list, GET_NXT(list->header));
}

void *rm_last(dll_t *list) {
  return rm(list, GET_PRV(list->trailer));
}
