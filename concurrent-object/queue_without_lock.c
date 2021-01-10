#include <pthread.h>
#include <stdio.h>
#include <assert.h>

/**
 * See also:
 *    page 30, http://cs.brown.edu/courses/cs176/lectures/chapter_03.pdf
 */

int array[1000];
int capacity = 1000;
int head = 0, tail = 0;

void enqueue(int val) {
    printf("entry enqueue\n");
    assert(tail - head != capacity);
    array[tail++ % capacity] = val;
    printf("exit enqueue\n");
}

int dequeue() {
    printf("entry dequeue\n");
    assert(tail != head);
    int val = array[head++ % capacity];
    printf("exit dequeue\n");
    return val;
}

void *thx_enqueue(){
    enqueue(2);
    enqueue(10);
    pthread_exit(NULL);
}

void *thx_dequeue(){
    int val0 = dequeue();
    int val1 = dequeue();
    pthread_exit(NULL);
}

int main(int argc, char **argv){
    pthread_t thx0, thx1;

    printf("-----------------------\n");

    pthread_create(&thx0, NULL, thx_enqueue, NULL);
    pthread_create(&thx1, NULL, thx_dequeue, NULL);

    pthread_join(thx0, NULL);
    pthread_join(thx1, NULL);

    return 0;
}
