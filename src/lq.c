#include "lq.h"
#include<stdlib.h>

void init_lq(lqueue_t *q) {
  init_sll(q->data);
}

void dest_lq(lqueue_t *q) {
  dest_sll(q->data);
  q->data = NULL;
}

/* Accessor operations. */
int size(lqueue_t *q) {
  return q->data->size;
}

//void* front(lqueue_t *);

/* Mutator operations. */
//void enqueue(lqueue_t *, void *);
//void* dequeue(lqueue_t *);
