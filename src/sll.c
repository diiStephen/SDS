#include "sll.h"
#include<stdio.h>
#include<stdlib.h>

void init_sll(struct sll *list) {
  list->size = 0;
  list->head = NULL;
  list->tail = NULL; 
}
