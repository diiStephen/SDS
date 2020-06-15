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

#define c_assert(t)\
  do {\
    int result = t;\
    if(result) {\
      printf("Passed: [%s]\n", #t);\
      pass++;\
    } else {\
      printf("Failed: [%s][%s][%d]\n", #t, __FILE__, __LINE__);\
      fail++;\
    }\
  } while (0)

#define print_result\
  printf("Passed: %d\nFailed: %d\n", pass, fail)

int pass = 0;
int fail = 0;

int main(void) {

  {
    header("T1");
    lstack_t s;
    init_stk(&s);
    for(int i = 10; i < 13; i++) {
      int *p = malloc(sizeof(int));
      *p = i;
      push(&s, p);
    }
    pop(&s);
    pop(&s);
    c_assert(size(&s) == 1);
    c_assert(*(int*)pop(&s) == 10);
    c_assert(size(&s) == 0);
  }

  print_result;
}
