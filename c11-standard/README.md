# Experiments on [C11 standard](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1570.pdf)

[`中文版`](https://hackmd.io/@butastur/concurrency-happens-before)

## Introduction
[`C11 standard`](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1570.pdf) defines `multi-threaded executions and data races` at `§5.1.2.4` which specifies the detail regarding `modification order`, `happens before`, `sequenced before`<sub>(§5.1.2.3)</sub>. 

## Modification order
Consider a binary relation *R* over a set *X* which *R* is total order if *R* satify:
- ∀  *a, b* ∈  *X*, *aRb and bRa* ⇒  *a* = *b*
- ∀  *a, b, c* ∈  *X*, *aRb* and *bRc* ⇒  *aRc*
- ∀  *a, b* ∈  *X*, *aRb* or *bRa*

Consider a set *X* which elements are modifications of an atomic object, and a binary relation `happens before` over the set *X*, then, we can see the `modification order` defined in `C11 standard`.

[`C11 standard, §5.1.2.4/7`](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1570.pdf) defines `modification order`
> All modifications to a particular atomic object M occur in some particular total order, called the modification order of M. If A and B are modifications of an atomic object M, and A happens before B, then A shall precede B in the modification order of M...

Which means if *A* and *B* are modifications of an atomic object M:
- `happens before` is a binary relation *R* over some particular total order set
- If *A* happens before B ⇒  *A* shall precede *B* in modification order of M

```shell
$ gcc modification_order.c -std=c11 -S -masm=intel -O2 -o modification_order_O2.s
```

```
test_atomic:
    ...
    lock add    DWORD PTR b[rip], 5
    mov eax, DWORD PTR b[rip]
    mov DWORD PTR a[rip], eax
    mfence
    mov DWORD PTR b[rip], 42
    ...
test:
    ...
    mov eax, DWORD PTR d[rip]
    mov DWORD PTR d[rip], 42
    add eax, 5
    ...
```

As the experimental above, we can see that the `modification orders` must respect the `happens before` relation, even using `-O2`.</br>
[[`C11 standard, §5.1.2.4/8`](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1570.pdf)]
> This states that the modification orders must respect the happens before relation.

## References
- [ ] [ISO/IEC 9899:201x, N1570, C11 standard](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1570.pdf)
- [ ] [並行和多執行緒程式設計 (上)](https://www.youtube.com/watch?v=i23aGY2173g)
- [ ] [Preshing on Programming, Memory Ordering at Compile Time, JUN 25, 2012](https://preshing.com/20120625/memory-ordering-at-compile-time/)
- [ ] [Concurrency系列(二): 從Sequenced-Before開始說起](http://opass.logdown.com/posts/788206-concurrency-series-2-starting-from-sequenced-before)
