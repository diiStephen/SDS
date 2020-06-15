#include "lstk.h"
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define create_int(n)\
  memset(malloc(sizeof(int)), n, sizeof(int))

int main(void) {

  {
    lstack_t s;
    init_stk(&s);
    push(&s, create_int(10));
    push(&s, create_int(11));
    push(&s, create_int(12));
    printf("Size: %d\n", size(&s));
    printf("First: %d\n", *((int*)first(s.data)));
  }
}
