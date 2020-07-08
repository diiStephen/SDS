#ifndef TESTER_H
#define TESTER_H

#include<stdio.h>

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

#endif
