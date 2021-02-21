#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <pthread.h>

/**
 * See also:
 *     https://github.com/jeffrey-minwei/experiments-on-concurrency/tree/master/concurrent-queue
 */
typedef struct node_t {
    volatile struct node_t *next;
    pthread_t *thread;
} node_t;

typedef struct thread_pool_t {
    node_t *head;
    node_t *tail;
} thread_pool_t;

thread_pool_t create_thread_pool();

#endif
