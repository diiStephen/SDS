#include "lq.h"
#include "tester.h"
#include<stdio.h>
#include<stdlib.h>

int main(void) {

  {
    header("BLOCK 1");
    lqueue_t lq;
    init_lq(&lq);
    dest_lq(&lq);
    footer("BLOCK 1");
  }


  return 0;
}
