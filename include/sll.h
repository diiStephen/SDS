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


void init_sll(struct sll *);
void dest_sll(struct sll *);

void* first(struct sll *);
void* last(struct sll *);

void add_first(struct sll *);
void add_last(struct sll *);

void* remove_first(struct sll *);


#endif
