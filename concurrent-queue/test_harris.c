#include <pthread.h>
#include <assert.h>
#include <stddef.h>
#include "node.h"
#include "list.h"

void *thx_insert(void *p) {
    node_t n;
    n.next = NULL;
    insert_after((node_t *)p, n);
}

int main(int argc, char **argv) {

    node_t dummy;
    dummy.next = NULL;

    pthread_t thx0, thx1;

    pthread_create(&thx0, NULL, thx_insert, &dummy);
    pthread_create(&thx1, NULL, thx_insert, &dummy);
    pthread_join(thx0, NULL);
    pthread_join(thx1, NULL);

    assert(2 == calc_length(&dummy));
    return 0;
}
