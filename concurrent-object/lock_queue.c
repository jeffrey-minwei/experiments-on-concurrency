#include <pthread.h>
#include <stdio.h>
#include <assert.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int array[1000];
int capacity = 1000;
int head = 0, tail = 0;

void enqueue(int val) {
    pthread_mutex_lock( &mutex );
    printf("lock-enque\n");

    // queue is full: tail - head == capacity
    assert(tail - head != capacity);   

    array[tail % capacity] = val;
    ++tail;

    printf("            unlock-enque\n");
    pthread_mutex_unlock( &mutex );
}

int dequeue() {
    pthread_mutex_lock( &mutex );
    printf("lock-deque\n");

    // queue is empty: head == tail
    assert(head != tail);

    int val = array[head % capacity];
    ++head;

    printf("            unlock-deque\n");
    pthread_mutex_unlock( &mutex );
    return val;
}

void *thx_enqueue(void *ptr){
    enqueue(*(int*)ptr);
    pthread_exit(NULL);
}

void *thx_dequeue(){
    int val = dequeue();
    pthread_exit(NULL);
}

int main(int argc, char **argv){
    pthread_t thx0, thx1, thx2, thx3;

    int arg0[1] = {2};
    int arg1[1] = {10};

    printf("-----------------------\n");

    pthread_create(&thx0, NULL, thx_enqueue, arg0);
    pthread_create(&thx1, NULL, thx_enqueue, arg1);
    pthread_create(&thx2, NULL, thx_dequeue, NULL);
    pthread_create(&thx3, NULL, thx_dequeue, NULL);

    pthread_join(thx0, NULL);
    pthread_join(thx1, NULL);
    pthread_join(thx2, NULL);
    pthread_join(thx3, NULL);

    return 0;
}
