#include "lstk.h"
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void) {

  {
    lstack_t s;
    init_stk(&s);
    for(int i = 10; i < 13; i++) {
      int *p = malloc(sizeof(int));
      *p = i;
      push(&s, p);
    }
    printf("Size: %d\n", size(&s));
    printf("First: %d\n", *((int*)first(s.data)));
  }
}
