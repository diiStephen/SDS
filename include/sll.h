#ifndef SLL_H
#define SLL_H

/* Generic singly linked list (sll) implementation. */
/* All operations supported are O(1), except for dest_sll, which is O(n). */
/* We assume that free(N), for a node N, is an O(1) operation. */

#define node_init(T) \
  struct node { \
    T data; \
     struct node *next; \
  };

struct Node {
  void *data;
  struct Node *next;
};

struct sll {
  int size;
  struct Node *head;
  struct Node *tail;
};

typedef struct sll sll_t;

/* Initialize the singly linked list. */
void init_sll(struct sll *);

/* Destroy the singly linked list. */
void dest_sll(struct sll *);

/* Get data field of first element of the list. */
void* first(struct sll *);

/* Get data field of the last element of the list. */
void* last(struct sll *);

/* Insert a new node at the head of the list. */
void ins_first(struct sll *, void *);

/* Insert a new node at the tail of the list. */
void ins_last(struct sll *, void *);

/* Remove the node at the head of the list and destroy it. */
void* rm_first(struct sll *);


#endif
