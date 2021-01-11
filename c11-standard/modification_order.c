#include <stdatomic.h>

atomic_int a = ATOMIC_VAR_INIT(0);
atomic_int b = ATOMIC_VAR_INIT(0);

int c, d;

void test_atomic() {
    atomic_fetch_add(&b, 5);
    atomic_store(&a, b);
    b = ATOMIC_VAR_INIT(42);
}

/**
 * See also:
 *    https://preshing.com/20120625/memory-ordering-at-compile-time/
 */
void test(){
    c = d + 5;
    d = 42;
}

int main(int argc, char **argv) {
    test();
    test_atomic();
    return 0;
}
