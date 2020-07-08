#ifndef L_QUEUE_H
#define L_QUEUE_H

/*
* Description: Linked list based implementation of the queue data structure.
* This implementation adapts the singly linked list data structure (sll.h, sll.c)
* to implement the fundamental queue operations. All queue operations run in
* O(1) time as the singly linked list operations are implemented in O(1) time.
* There is no maximum capacity, however, there are memory requirements to keep
* in mind due to the use of the singly linked list. That is, additional memory
* is maintained for the nodes of the list.
*
* Generics: Generic container achieved through the use of void *.
*
* Complexity:
*   (i)   size    -- O(1)
*   (ii)  front   -- O(1)
*   (iii) enqueue -- O(1)
*   (iv)  dequeue -- O(1)
*/

#include "sll.h"

struct lq {
  sll_t data;
};

typedef struct lq lqueue_t;

/* Constructor and Destructor. */
void init_aq(lqueue_t *);
void dest_aq(lqueue_t *);

/* Accessor operations. */
int size(lqueue_t *);
void* front(lqueue_t *);

/* Mutator operations. */
void enqueue(lqueue_t *, void *);
void* dequeue(lqueue_t *);

#endif
