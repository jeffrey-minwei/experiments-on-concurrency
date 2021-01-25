#include <stddef.h>
#include <limits.h>
#include <assert.h>
#include "node.h"
#include "list.h"

unsigned int calc_length(node_t *head) {
    assert(head != NULL);
    node_t *ptr = head;
    unsigned int length = 0;
    while(ptr->next != NULL && length < INT_MAX){
        ptr = (node_t *)ptr->next;
        ++length;
    }
    return length;
}
