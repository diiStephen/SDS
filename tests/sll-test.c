#include "sll.h"
#include<stdio.h>

#define SIZE(L)\
  printf("Size of list: %d\n", (L).size);
  
int main(void) {
  printf("Starting singly linked list test!\n");

  int i = 0;
  int j = 1;
  int k = 2;

  sll_t list;
  init_sll(&list);
  SIZE(list);

  ins_first(&list, &i);
  ins_first(&list, &j);
  ins_first(&list, &k);
  ins_last(&list, &i);
  ins_last(&list, &j);
  ins_last(&list, &k);

  SIZE(list);

  rm_first(&list);
  rm_first(&list);
  rm_first(&list);
  rm_first(&list);
  rm_first(&list);
  rm_first(&list);

  SIZE(list);

  ins_first(&list, &i);
  ins_first(&list, &i);
  ins_first(&list, &i);
  ins_first(&list, &i);

  SIZE(list);

  return 0;
}
