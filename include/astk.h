#ifndef ASTK_H
#define ASTK_H

/*
* Generic array based stack data structure. A fixed-sized array of void* is used for
* underlying storage. Default capacity, provided as a symbolic constant, is
* 1000.
*
*
* When push is called on a full stack, then the program shuts down with
* an error. When pop is called on an empty stack, then NULL is returned. 
*/

#define CAPACITY 1000

struct Stack {
  int top, capacity;
  void **data;
};

typedef struct Stack astack_t;

//Constructor and destructor
void init_astk(astack_t *);
void dest_astk(astack_t *);

//Accessor functions.
int size(astack_t *);
void* top(astack_t *);

//Mutator functions.
void push(astack_t *, void *);
void* pop(astack_t *);

#endif
