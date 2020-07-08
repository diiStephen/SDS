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

  print_result;
  return 0;
}
