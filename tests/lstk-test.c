#include "lstk.h"
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define header(h)\
  do {\
    printf("-----------------------------\n");\
    printf("Test: %s\n", h);\
    printf("-----------------------------\n\n");\
  } while (0)



int main(void) {

  {
    header("Push and Pop");
    lstack_t s;
    init_stk(&s);
    for(int i = 10; i < 13; i++) {
      int *p = malloc(sizeof(int));
      *p = i;
      push(&s, p);
    }
    pop(&s);
    pop(&s);
    assert(size(&s) == 1);
    assert(*(int*)pop(&s) == 10);
    assert(size(&s) == 0);
  }




}
