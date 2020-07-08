#include "lq.h"
#include "tester.h"
#include<stdio.h>
#include<stdlib.h>

int main(void) {

  {
    header("BLOCK 1");
    lqueue_t lq;
    init_lq(&lq);
    c_assert(size(&lq) == 0);
    dest_lq(&lq);
    footer("BLOCK 1");
  }

  {
    header("BLOCK 2");
    lqueue_t s;
    init_lq(&s);
    int *p = NULL;
    for(int i = 0; i < 641; i++) {
      p = malloc(sizeof(int));
      *p = i;
      enqueue(&s, p);
    }
    c_assert(size(&s) == 641);
    c_assert(*(int*)front(&s) == 0);
    dest_lq(&s);
    c_assert(s.data == NULL);
    footer("BLOCK 2");
  }


  print_result;
  return 0;
}
