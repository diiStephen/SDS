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
  printf("Current vals: size: %d, head: %p, tail: %p\n", l.size, l.head,l.tail);

  return 0;
}
