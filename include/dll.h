#ifndef DLL_H
#define DLL_H

/* Generic doubly linked list implementation. */
/* Genericity is achieved through void * field. */
/* Includes macros for accessing node fields. */

#define SIZE(L)\
  (L)->size

#define GET_NXT(N)\
  (N)->next

#define GET_PRV(N)\
  (N)->prev

#define GET_DTA(N)\
  (N)->data

struct Node {
  void *data;
  struct Node *next;
  struct Node *prev;
};

struct dll {
  int size;
  struct Node *header;
  struct Node *trailer;
};

typedef struct dll dll_t;
typedef struct Node node_t;

// Constructors and destructors
void init_dll(dll_t *);
void dest_dll(dll_t *);
node_t* new_node(node_t *, node_t *, void *);
void dest_node(node_t *);

// Accessors for first and last elements.
void* first(dll_t *);
void* last(dll_t *);

// Insert functions at the head and tail.
void ins_first(dll_t *, void *);
void ins_last(dll_t *, void *);

// Insert between utility function.
void ins_btn(dll_t *, node_t *, node_t *, void *);

// Remove functions at the head and tail.
void* rm_first(dll_t *);
void* rm_last(dll_t *);

#endif
