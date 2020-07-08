#include "lq.h"
#include<stdio.h>
#include<stdlib.h>

void init_lq(lqueue_t *q) {
  if ( (q->data = malloc(sizeof(sll_t))) == NULL) {
    fprintf(stderr, "Could not allocate linked list memory!\n");
    exit(0);
  }
  init_sll(q->data);
}


void dest_lq(lqueue_t *q) {
  dest_sll(q->data);
  q->data = NULL;
}

/* Accessor operations. */
int size(lqueue_t *q) { return q->data->size; }
void* front(lqueue_t *q) { return first(q->data); }

/* Mutator operations. */
void enqueue(lqueue_t *q, void *d) { ins_last(q->data, d); }
void* dequeue(lqueue_t *q) { return rm_first(q->data); }
