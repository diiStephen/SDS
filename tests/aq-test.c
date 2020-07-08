#include "aq.h"
#include "tester.h"
#include<stdlib.h>
#include<string.h>


int main(void) {

  {
    header("Test 1");
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
    footer("Test 1");
  }

  print_result;

  return 0;

}
