#include "lq.h"

void init_lq(lqueue_t *q) {
  init_sll(q->data);
}

void dest_lq(lqueue_t *q) {
  dest_sll(q->data);
  q->data = NULL;
}
