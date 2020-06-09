#ifndef MSLL_H
#define MSLL_H

/* Generic singly linked list using macros for code generation. */

#define node_init(T) \
  struct node { \
    T data; \
    struct node *next; \
  };




#endif
