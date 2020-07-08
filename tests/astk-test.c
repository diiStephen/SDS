#include "astk.h"
#include "tester.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char** argv) {

  {
    header("Test 1");
    astack_t s;
    init_astk(&s, 100);

    push(&s, "Hello");
    push(&s, "World");

    c_assert(size(&s) == 2);
    c_assert(strcmp((char*)top(&s), "World") == 0);

    printf("Size of s: %d\n", size(&s));
    dest_astk(&s);
    footer("Test 1");
  }

  {
    header("Test 2");
    astack_t s;
    init_astk(&s, 10);
    int *p = NULL;
    for(int i = 0; i < 5; i++) {
      p = malloc(sizeof(int));
      *p = i;
      push(&s, p);
    }
    c_assert(size(&s) == 5);
    c_assert(*(int*)pop(&s) == 4);
    dest_astk(&s);
    footer("Test 2");
  }

  print_result;
  return 0;

}
