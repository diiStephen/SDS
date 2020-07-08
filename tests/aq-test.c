#include "aq.h"
#include "tester.h"
#include<stdlib.h>
#include<string.h>


int main(void) {

  {
    header("BLOCK 1");
    aqueue_t s;
    init_aq(&s, CAPACITY);
    int *p = NULL;
    for(int i = 0; i < 641; i++) {
      p = malloc(sizeof(int));
      *p = i;
      enqueue(&s, p);
    }
    c_assert(size(&s) == 641);
    c_assert(*(int*)front(&s) == 0);
    dest_aq(&s);
    c_assert(s.data == NULL);
    footer("BLOCK 1");
  }

  {
    header("BLOCK 2");
    aqueue_t s;
    init_aq(&s, 10);
    int *p = NULL;
    for(int i = 0; i < 5; i++) {
      p = malloc(sizeof(int));
      *p = i;
      enqueue(&s, p);
    }
    c_assert(*(int*)dequeue(&s) == 0);
    c_assert(*(int*)dequeue(&s) == 1);
    c_assert(*(int*)dequeue(&s) == 2);
    c_assert(size(&s) == 2);
    dest_aq(&s);
    footer("BLOCK 2");
  }

  {
    header("BLOCK 3");
    aqueue_t s;
    init_aq(&s, 25);
    enqueue(&s, "A");
    enqueue(&s, "B");
    enqueue(&s, "C");
    dequeue(&s);
    dequeue(&s);
    dequeue(&s);
    enqueue(&s, "D");
    c_assert(size(&s) == 1);
    c_assert(strcmp(dequeue(&s), "D") == 0);
    dest_aq(&s);
    footer("BLOCK 3");
  }

  print_result;

  return 0;

}
