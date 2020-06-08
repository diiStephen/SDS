#ifndef SLL_H
#define SLL_H

/* Generic singly linked list implementation. */

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

void init_sll(struct sll *);
void dest_sll(struct sll *);

void* first(struct sll *);
void* last(struct sll *);

void ins_first(struct sll *, void *);
void ins_last(struct sll *, void *);

void* rm_first(struct sll *);


#endif
