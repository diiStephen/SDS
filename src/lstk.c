#include "lstk.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void init_stk(lstack_t *s) {
  memset(s, 0, sizeof(lstack_t));
  s->data = malloc(sizeof(sll_t));
  if(s->data == NULL) {
    fprintf(stderr, "Could not allocate space for linked list storage");
    exit(1);
  }
  init_sll(s->data); //Initialize singly linked list component.
}

void dest_stk(lstack_t *s) {
  dest_sll(s->data);
}

int size(lstack_t *s) {
  return s->data->size;
}

void* pop(lstack_t *s) {
  return rm_first(s->data);
}

void push(lstack_t *s, void *d) {
  ins_first(s->data, d);
}

void* top(lstack_t *s) {
  return first(s->data);
}
