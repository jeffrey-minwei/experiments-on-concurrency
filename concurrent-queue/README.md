# Experiments on Lock-free Concurrent Queue

[[`中文筆記`](https://hackmd.io/@butastur/concurrent-queue)]</br>
Experiments on implements a lock-free concurrent queue based on [`Michael & Scott algorithm`](https://www.researchgate.net/publication/2804621_Simple_Fast_and_Practical_Non-Blocking_and_Blocking_Concurrent_Queue_Algorithms).

## Non-blocking singly-linked list
[`Michael & Scott algorithm`](https://www.researchgate.net/publication/2804621_Simple_Fast_and_Practical_Non-Blocking_and_Blocking_Concurrent_Queue_Algorithms) implements a non-blocking concurrent queue based on singly-linked list, here experiments on implements a non-blocking singly-linked list.

### Harris's solution
**Insert node n aftre node p**
- Step 1. node *next = p->next
- Step 2. n.next = next
- Step 3. bool result = cas(&p->next, next, n)
- Step 4. if result == false, **goto Step 1**

### Insertion
Based on [`Michael & Scott algorithm`](https://www.researchgate.net/publication/2804621_Simple_Fast_and_Practical_Non-Blocking_and_Blocking_Concurrent_Queue_Algorithms), after insert node to the list, swing tail to the inserted node, using `atomic_compare_exchange_strong(&list->tail, &tail, &new)`

## References
- [ ] Timothy L. Harris. 2001. A Pragmatic Implementation of Non-blocking Linked-Lists. In <i>Proceedings of the 15th International Conference on Distributed Computing</i> (<i>DISC '01</i>). Springer-Verlag, Berlin, Heidelberg, 300–314.
- [ ] [Wikipedia, Non-blocking linked list](https://en.wikipedia.org/wiki/Non-blocking_linked_list)
