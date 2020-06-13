#include "cll.h"
#include<stdio.h>
#include<stdlib.h>

#define print_header(msg)\
  printf("Beginning test: msg\n");

int main(void) {

  {
    print_header("01");
    cll_t l; // New Circularly linked list.
    init_cll(&l); // Initalize the list.
    for(int i = 0; i < 10; i++) {
      int *p = malloc(sizeof(int));
      *p = i;
      ins_first(&l, *p)
    }
    printf("First element: %d\n", *first(&l));
    printf("Last element: %d\n", *last(&l))
  }




}
