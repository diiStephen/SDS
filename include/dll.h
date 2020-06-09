#ifndef DLL_H
#define DLL_H

/* Generic doubly linked list implementation. */

struct Node {
  void *data;
  struct Node *next;
  struct Node *prev;
};

struct dll {
  int size;
  struct Node *header;
  struct Node *trailer; 
}

#endif
