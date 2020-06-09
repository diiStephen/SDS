#include "dll.h"
#include<stdio.h>
#include<stdlib.h>


#define ROUNDS 10

int main(void) {

  dll_t l; //Declare new doubly linked list.
  init_dll(&l); //Initialize double linked list. This must be called FIRST.
  int *p = NULL;

  for(int i = 0; i < ROUNDS; i++) {
    p = malloc(sizeof(int));
    *p = i;
    ins_first(&l, p);
  }
  
  rm_first(&l);
  rm_last(&l);
  rm_last(&l);

  p = malloc(sizeof(int));
  *p = 100;
  ins_last(&l, p);

  for(node_t *w = l.header->next; w != l.trailer; w = w->next)
    printf("data: %d\n", *((int*)w->data));

  printf("Size of list: %d\n", SIZE(&l));
  dest_dll(&l);
}
