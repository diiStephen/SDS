#include "cll.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define header(h)\
  do {\
    printf("-----------------------------\n");\
    printf("Test: %s\n", h);\
    printf("-----------------------------\n");\
  } while (0)

#define create_int(n)\
  memset(malloc(sizeof(int)), n, sizeof(int))

int main(void) {

  {
    header("Insertion Test");
    cll_t l; // New Circularly linked list.
    init_cll(&l); // Initalize the list.
    dest_cll(&l);
  }

  {
    header("Rotation Test");
    cll_t l;
    init_cll(&l);
    ins_first(&l, create_int(32));
    ins_first(&l, create_int(100));
    ins_first(&l, create_int(42));
    rotate(&l);
    dest_cll(&l);
  }


}
