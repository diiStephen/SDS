#ifndef MSLL_H
#define MSLL_H

/* Generic singly linked list using macros for code generation. */

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




#endif
