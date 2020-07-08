#include "aq.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void init_aq(aqueue_t *q, int cap) {

  if (cap <= 0) {
    fprintf(stderr, "Queue capacity must be positive!\n");
    exit(0);
  }

  if ( (q->data = malloc(sizeof(void*)*cap)) == NULL ) {
    fprintf(stderr, "Memory could not be allocated for queue storage!\n");
    exit(0);
  }

  q->front = 0;
  q->capacity = cap;
  q->size = 0;

}

void dest_aq(aqueue_t *q) {
  if (q != NULL) {
    q->front = -1;
    q->capacity = 0;
    q->size = 0;
    free(q->data);
    q->data = NULL;
  }
}

int size(aqueue_t *q) {
  return q->size;
}

void* front(aqueue_t *q) {
  if (q->size == 0) return NULL;
  return q->data[q->front];
}

void enqueue(aqueue_t *q, void *d) {
  if (q->size == q->capacity) {
    fprintf(stderr, "Queue is full, cannot enqueue!\n");
    exit(0);
  }
  int loc = ( q->front + q->size ) % q->capacity; //treat array q->data as a ring.
  q->data[loc] = d;
  q->size++;
}

void* dequeue(aqueue_t *q) {
  if (q->size == 0) return NULL;
  void *ans = q->data[q->front];
  q->data[q->front] = NULL;
  q->front = ( q->front + 1 ) % q->capacity;
  q->size--;
  return ans;
}
