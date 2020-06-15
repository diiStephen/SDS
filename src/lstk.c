#include "lstack.h"



void init_stk(lstack_t *s) {
  memset(s, 0, sizeof(lstack_t));
  init_sll(&(s->data)); //Initialize singly linked list component.
}

void dest_stk(lstack_t *s) {
  dest_sll(&(s->data));
}
