#include "astk.h"
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv) {

  astack_t s;
  init_astk(&s, 100);

  dest_astk(&s);
  return 0;

}
