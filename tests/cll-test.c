#include "cll.h"
#include<stdio.h>
#include<stdlib.h>

#define header(h)\
  printf("Test: %s\n", h)


int main(void) {

  {
    header("01");
    cll_t l; // New Circularly linked list.
    init_cll(&l); // Initalize the list.
    for(int i = 0; i < 10; i++) {
      int *p = malloc(sizeof(int));
      *p = i;
      ins_first(&l, (void*)p);
    }
    node_t *walk = l.tail->next;
    for(int j = 0; j < size(&l); j++) {
      printf("Data: %d\n", *(int*)walk->data);
      walk = walk->next;
    }
    printf("First element: %d\n", *((int*)first(&l)));
    printf("Last element: %d\n", *((int*)last(&l)));
    rm_first(&l);
    printf("First element: %d\n", *((int*)first(&l)));
    printf("Last element: %d\n", *((int*)last(&l)));
    rotate(&l);
    printf("First element: %d\n", *((int*)first(&l)));
    printf("Last element: %d\n", *((int*)last(&l)));
    dest_cll(&l);
  }




}
