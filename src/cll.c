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
    //Remove nodes. 
  }
}
