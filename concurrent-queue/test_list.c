#include <pthread.h>
#include <assert.h>
#include <stddef.h>
#include "node.h"
#include "list.h"

void *thx_insert(void *p_list) {
    node_t n;
    n.next = NULL;
    insert((list_t *)p_list, n);
}

int main(int argc, char **argv) {

    pthread_t thx0, thx1;

    list_t list = create_list();

    pthread_create(&thx0, NULL, thx_insert, &list);
    pthread_create(&thx1, NULL, thx_insert, &list);
    pthread_join(thx0, NULL);
    pthread_join(thx1, NULL);

    assert(2 == length(&list));
    return 0;
}
