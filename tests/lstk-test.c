#include "lstk.h"
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define header(msg)\
  do {\
    printf("-----------------------------\n");\
    printf("TEST: %s\n", msg);\
    printf("-----------------------------\n");\
  } while (0)

#define c_assert(t)\
  do {\
    int result_ = t;\
    printf("%s [%s][%s][%d]\n", result_ ? "PASS" : "FAIL", #t, __FILE__, __LINE__);\
    if(result_) { pass++; } else { fail++; }\
  } while (0)

#define footer(msg)\
  do {\
    printf("-----------------------------\n");\
    printf("END: %s\n", msg);\
    printf("-----------------------------\n\n");\
  } while(0)

#define print_result\
  printf("Passed: %d\tFailed: %d\n", pass, fail)

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
    footer("T1");
  }

  print_result;
}
