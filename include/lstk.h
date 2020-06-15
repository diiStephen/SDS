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
  int size, capacity; 
}

#endif
