#include "astk.h"
#include<stdio.h>
#include<stdlib.h>

void init_astk(astack_t *s, int cap) {
  if (cap <= 0) {
    fprintf(stderr, "Stack capacity must be positive!\n");
    exit(0);
  }

  if ((s->data = malloc(sizeof(void*)*cap)) == NULL) {
    fprintf(stderr, "Could not Allocate memory for stack storage.\n");
    exit(0);
  }

  s->capacity = cap;
  s->top = -1;
}

void dest_astk(astack_t *s) {
  free(s->data);
  s->top = -1;
  s->capacity = 0;
}

int size(astack_t *s) {
  return s->top + 1;
}
