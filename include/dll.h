#ifndef DLL_H
#define DLL_H

/* Generic doubly linked list implementation. */

#define SIZE(L)\
  (L)->size

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

// Accessors for first and last elements.
void* first(dll_t *);
void* last(dll_t *);

// Insert functions at the head and tail.
void ins_first(dll_t *);
void ins_last(dll_t *);

// Insert between utility function.
void ins_btn(dll *, node_t *, node_t *);

// Remove functions at the head and tail.
void* rm_first(dll_t *);
void* rm_last(dll_t *);

#endif
