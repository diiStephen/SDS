#ifndef MSLL_H
#define MSLL_H

/* Generic singly linked list using macros for code generation. */

#include<string.h>

#define init_list_t(T)\
  typedef struct {\
    int size;\
    node_t *head;\
    node_t *tail;\
  } sll_t\


#define init_node_t(T)\
  struct Node {\
    T *data;\
    struct Node *next;\
  };\
  typedef struct Node node_t


#define init_list(l)\
  memset((l), 0, sizeof(*(l)))

#define size(l)\
  (l)->size

#define first(l)\
  ( (l)->size == 0 ? NULL : (l)->head->data )

#define last(l)\
  ( (l)->size == 0 ? NULL : (l)->tail->data )


#endif
