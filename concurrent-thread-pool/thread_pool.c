#include "thread_pool.h"

thread_pool_t create_thread_pool()
{
    node_t dummy;
    dummy.next = NULL;

    thread_pool_t trd_pool;
    trd_pool.head = trd_pool.tail = &dummy;
    return trd_pool;
}
