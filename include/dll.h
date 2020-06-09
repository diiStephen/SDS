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

void init_dll(dll_t *);
void dest_dll(dll_t *);

#endif
