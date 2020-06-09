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

void* first(dll_t *);
void* last(dll_t *);

void ins_first(dll_t *);
void ins_last(dll_t *);

void* rm_first(dll_t *);
void* rm_last(dll_t *);

#endif
