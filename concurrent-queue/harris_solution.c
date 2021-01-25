#include <stdatomic.h>
#include "node.h"

/**
 * See also:
 *    https://en.wikipedia.org/wiki/Non-blocking_linked_list
 */
void insert_after(node_t *p, node_t new) {
    volatile node_t *next;
    do {
        next = p->next;
        new.next = next;
    } while (! atomic_compare_exchange_strong(&p->next, &next, &new));
}
