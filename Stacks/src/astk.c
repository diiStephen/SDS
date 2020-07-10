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

void* top(astack_t *s) {
  if(size(s) == 0) return NULL;
  return (s->data)[s->top];
}

void push(astack_t *s, void *d) {
  if(size(s) == s->capacity) {
    fprintf(stderr, "Stack is full!\n");
    exit(0);
  }
  s->data[++s->top] = d;
}

void* pop(astack_t *s) {
  if(size(s) == 0) return NULL;
  void *ans = s->data[s->top];
  s->data[s->top] = NULL;
  s->top--;
  return ans;
}
