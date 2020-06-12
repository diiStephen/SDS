#ifndef CLL_H
#define CLL_H

/* Circularly Linked list implementation. */

struct node {
  void *data;
  struct node *next;
};

struct cll {
  int size;
  node_t *tail;
};

typedef struct cll cll_t;
typedef struct node node_t;

void init_cll(cll_t *);
void dest_cll(cll_t *);

void* first(cll_t *);
void* last(cll_t *);

void ins_first(cll_t *, void *);
void ins_last(cll_t *, void *);
void rotate(cll_t *);

void* rm_first(cll_t *);



#endif
