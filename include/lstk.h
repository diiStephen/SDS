#ifndef L_STACK_H
#define L_STACK_H

/*
* Linked List Based Stack Interface.
* Can this be generalized to be indepedant of implementation? I.e. can we
* simulate Java interfaces?
*/


/*
* A stack interface based on adapting the singly linked list
* to the stack.
*
*
*/

#include "sll.h"

struct Stack {
  sll_t data;
};

typedef struct Stack lstack_t;

void init_stk(lstack_t *);
void dest_stk(lstack_t *);
int size(lstack_t *);
void* pop(lstack_t *);
void push(lstack_t *);
void* top(lstack_t *);

#endif
