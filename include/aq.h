/*
* Description: Array based queue implementation. Array is treated a circular
* buffer to ensure that enqueue and dequeue operations are O(1) time each. Since
* the front of the queue may drift with dequeue operations, and we do not want
* to shift elements of the array back into place (an O(n) operation), the array
* is treated as a ring.
*
* Generics: Generic container achieved through the use of void *.
*
* Complexity:
*   (i)   size    -- O(1)
*   (ii)  front   -- O(1)
*   (iii) enqueue -- O(1)
*   (iv)  dequeue -- O(1)
*/

struct queue {
  int capacity, front, size;
  void *data;
};

typedef struct queue aqueue_t;

/* Constructor and Destructor. */
void init_aq(aqueue_t *);
void dest_aq(aqueue_t *);

/* Accessor operations. */
int size(aqueue_t *);
void* front(aqueue_t *);

/* Mutator operations. */
void enqueue(aqueue_t *, void *);
void* dequeue(aqueue_t *);
