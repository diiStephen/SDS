#include "cll.h"
#include<stdio.h>
#include<stdlib.h>

int main(void) {

  {
    cll_t l; // New Circularly linked list.
    init_cll(&l); // Initalize the list.
    for(int i = 0; i < 10; i++) {
      int *p = malloc(sizeof(int));
      *p = i;
      ins_first(&l, (void*)p);
    }
    printf("First element: %d\n", *((int*)first(&l)));
    printf("Last element: %d\n", *((int*)last(&l)));
  }




}
