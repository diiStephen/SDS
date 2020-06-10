#ifndef MSLL_H
#define MSLL_H

/* Generic singly linked list using macros for code generation. */

/* ISSUE: What if we need multiple lists of different types? */
/* That would incurr multiple definitions of the node_t type, an error. */

/* ISSUE: No checking the return of malloc is done. */

/*
* Is there a way to avoid having to pass the name of the type to every
* macro? It seems like the way to overcome the issues above is to use
* the string concatenation to name the nodes according to their type.
* it seems like then I would have to include that name in every macro
* call.
*
* The other issue is that the node_t type is not defined until the macro
* is called, so I cannot use that type as a parameter to any function
* with declaration in this file. This makes it difficult to put the update
* procedure into a function rather than in the macro.
*
* Ideally, we want to seperate operations involving the data of type T, and
* everything else involving pointer updates and memory manipulation into
* a function. Using an intermediate type, i.e. char * may work.
*/

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

#define unpack_(l)\
  (char**)&((l)->head), (char**)&(l)->tail, &(l)->size, sizeof((l)->head)

#define init_list(l)\
  memset((l), 0, sizeof(*(l)))

#define size(l)\
  (l)->size

#define first(l)\
  ( (l)->size == 0 ? 0 : (l)->head->data )

#define last(l)\
  ( (l)->size == 0 ? 0 : (l)->tail->data )

// This can be vastly shortend as the only time we need reference to x is
// when we assign the data field of the new node, but after the splice in,
// l->head will be a reference to this node, so we can assign it there.
#define ins_first(l,x)\
  do{\
    node_t *n = malloc(sizeof(node_t));\
    n->next = (l)->head;\
    (l)->head = n;\
    n->data = x;\
    if ((l)->size == 0) {\
      (l)->tail = n;\
    }\
    (l)->size++;\
  } while (0)

#define ins_last(l,x)\
  do{\
    node_t *n = malloc(sizeof(node_t));\
    n->next = NULL;\
    if ((l)->size != 0)\
      (l)->tail->next = n;\
    (l)->tail = n;\
    (l)->size++;\
  } while (0)

#define rm_first(l)\
  do{\
    if((l)->size > 0) {\
      node_t *sav = (l)->head;\
      (l)->head = (l)->head->next;\
      (l)->size--;\
      if((l)->size == 0)\
        (l)->tail = NULL;\
      free(sav);\
    }\
  } while (0)

#define deinit_list(l)\
  do{\
    while((l)->size > 0) {\
      node_t *sav = (l)->head;\
      (l)->head = (l)->head->next;\
      (l)->size--;\
      free(sav);\
    }\
    memset((l), 0, sizeof(*(l)));\
  } while (0)

//head, tail, size.
int ins_first_(char**, char**, int*, int);


#endif
