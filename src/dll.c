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

//Note: This dll uses head and tail sentinel nodes. 
void init_dll(dll_t *list) {
  list->size = 0;
  list->header = new_node(NULL, NULL, NULL); // head sentinel
  list->trailer = new_node(list->header, NULL, NULL); // tail sentinel
  list->header->next = list->trailer; // header -> trailer
}
