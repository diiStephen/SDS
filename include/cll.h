#ifndef CLL_H
#define CLL_H

/* Circularly Linked list implementation. */ 

struct node {
  void *data;
  struct node* next;
};

struct cll {
  int size;
  node_t *tail;
};

typedef struct cll cll_t;
typedef struct node node_t;

#endif
