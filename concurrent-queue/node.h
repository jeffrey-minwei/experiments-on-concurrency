#ifndef NODE_H
#define NODE_H

typedef struct node_t {
    volatile struct node_t *next;
} node_t;

#endif
