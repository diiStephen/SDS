#include "msll.h"
#include<stdio.h>

init_node_t(int);
init_list_t(int);

int main(void) {

  sll_t l;
  init_list(&l);
  printf("Current vals: size: %d, head: %p, tail: %p\n", l.size, l.head,l.tail);
  ins_first(&l, 13);
  ins_first(&l, 15);
  ins_first(&l, 20);
  ins_first_v2(&l, 25);
  for(node_t *w = l.head; w != NULL; w = w->next) {
    printf("[%p]: data = %d\n", w, w->data);
  }
  printf("Current vals: size: %d, head: %p, tail: %p\n", l.size, l.head,l.tail);
  ins_last(&l, 76);
  ins_last(&l,32);
  printf("Current vals: size: %d, head: %p, tail: %p\n", l.size, l.head,l.tail);
  deinit_list(&l);
  return 0;
}
