#include "astk.h"
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv) {

  astack_t s;
  init_astk(&s, 100);

  push(&s, "Hello");
  push(&s, "World");

  printf("Size of s: %d\n", size(&s));
  printf("Top of stack: %s\n", (char*)top(&s));

  dest_astk(&s);
  return 0;

}
