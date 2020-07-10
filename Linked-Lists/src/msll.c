#include "msll.h"


int ins_first_(char **head, char **tail, int *size, int memsz, char **sav) {
  char *newest = calloc(1, memsz);
  if (newest == NULL) return -1;
  *sav = *head;
  *head = newest;
  if(*size == 0)
    *tail = *head;
  (*size)++;
  return 0;
}
