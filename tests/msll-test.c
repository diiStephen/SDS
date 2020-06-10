#include "msll.h"
#include<stdio.h>

init_node_t(int);
init_list_t(int);

int main(void) {

  sll_t l;
  init_list(&l);
  printf("Current vals: size: %d, head: %p, tail: %p\n", l.size, l.head,l.tail);

  int t = -1;
  t = first(&l);

  printf("Current value of t: %d\n", t);
  printf("Current size of the list is: %d\n", size(&l));

  return 0;
}
