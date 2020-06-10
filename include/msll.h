#ifndef MSLL_H
#define MSLL_H

/* Generic singly linked list using macros for code generation. */

#include<string.h>
#include<stdlib.h>

#define init_list_t(T)\
  typedef struct {\
    int size;\
    node_t *head;\
    node_t *tail;\
  } sll_t\


#define init_node_t(T)\
  struct Node {\
    T data;\
    struct Node *next;\
  };\
  typedef struct Node node_t


#define init_list(l)\
  memset((l), 0, sizeof(*(l)))

#define size(l)\
  (l)->size

#define first(l)\
  ( (l)->size == 0 ? 0 : (l)->head->data )

#define last(l)\
  ( (l)->size == 0 ? 0 : (l)->tail->data )

#define ins_first(l,x)\
  do{\
    node_t *n = malloc(sizeof(node_t));\
    n->data = x;\
    n->next = (l)->head;\
    (l)->head = n;\
    (l)->size++;\
  } while (0)


#endif
