/*
* Description: Array based queue implementation. Array is treated a circular
* buffer to ensure that enqueue and dequeue operations are O(1) time each. Since
* the front of the queue may drift with dequeue operations, and we do not want
* to shift elements of the array back into place (an O(n) operation), the array
* is treated as a ring.
*
* Additionally, the array storage for the data of the queue is a fixed sized
* and will not be reallocated. This also ensures that the supported operations
* can be implemented in O(1) time. Functions that are in error state when the
* queue is full will either shut the program down with an error.
*
* Default symbolic constant is given by CAPACITY for the user.
*
* Generics: Generic container achieved through the use of void *.
*
* Complexity:
*   (i)   size    -- O(1)
*   (ii)  front   -- O(1)
*   (iii) enqueue -- O(1)
*   (iv)  dequeue -- O(1)
*/

#define CAPACITY 1000

struct queue {
  int capacity, front, size;
  void **data;
};

typedef struct queue aqueue_t;

/* Constructor and Destructor. */
void init_aq(aqueue_t *, int);
void dest_aq(aqueue_t *);

/* Accessor operations. */
int size(aqueue_t *);
void* front(aqueue_t *);

/* Mutator operations. */
void enqueue(aqueue_t *, void *);
void* dequeue(aqueue_t *);
