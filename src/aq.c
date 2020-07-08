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

  q->front = -1;
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
