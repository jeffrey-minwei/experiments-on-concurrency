#ifndef LIST_H
#define LIST_H

#include "node.h"

unsigned int calc_length(node_t *);
void insert_after(node_t *, node_t);

typedef struct list_t {
    node_t *head;
    node_t *tail;
} list_t;

list_t *create_list();

void insert(list_t *, node_t);

unsigned int length(list_t *);

#endif
