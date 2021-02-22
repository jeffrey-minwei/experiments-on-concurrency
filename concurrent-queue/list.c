#include <stddef.h>
#include <stdatomic.h>
#include <limits.h>
#include <assert.h>
#include <stdlib.h>
#include "node.h"
#include "list.h"

list_t *create_list() {
    node_t *dummy = malloc(sizeof(node_t));
    dummy->next = NULL;

    list_t *list = malloc(sizeof(list_t));
    list->head = dummy;
    list->tail = dummy;
    return list;
}

/**
 * See also:
 *    https://en.wikipedia.org/wiki/Non-blocking_linked_list
 *    https://www.researchgate.net/publication/2804621_Simple_Fast_and_Practical_Non-Blocking_and_Blocking_Concurrent_Queue_Algorithms
 */
void insert(list_t *list, node_t new) {
    node_t *tail;
    volatile node_t *next;
    do {
        tail = list->tail;
        next = tail->next;
        new.next = next;
    } while (! atomic_compare_exchange_strong(&tail->next, &next, &new));
    atomic_compare_exchange_strong(&list->tail, &tail, &new);
}

/**
 * O(n)
 */
unsigned int length(list_t *list) {
    assert(list != NULL);
    node_t *ptr = list->head;
    unsigned int length = 0;
    while(ptr != list->tail){
        ptr = (node_t *)ptr->next;
        ++length;
    }
    return length;
}

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
