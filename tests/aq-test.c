#include "aq.h"
#include "tester.h"

int main(void) {

  {
    header("Test 1");
    aqueue_t s;
    init_aq(&s, CAPACITY);
    dest_aq(&s);
    c_assert(s.data == NULL);
    footer("Test 1");
  }

  print_result;

  return 0;

}
