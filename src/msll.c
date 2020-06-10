#include "sll.h"


// node_t* new_node_(node_t *n) {
//   node_t *newest = NULL;
//   if( (newest = malloc(sizeof(node_t))) == NULL) {
//     fprintf(stderr, "Could not malloc new node!\n");
//   }
//   newest->next = n;
//   return newest;
// }
//
// int ins_first_(sll_t *l, node_t *node) {
//   l->head = node;
//   if (l->size == 0)
//     l->tail = node;
//   l->size++;
//   return 0;
// }
