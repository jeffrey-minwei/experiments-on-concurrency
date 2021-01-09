# Experiments on Concurrent

This repository is **focus on experimental** regarding several concurrent topics including `synchronization`, `concurrent object`, `linearizability`, `universal construction`, `wait-free`, `shared memory`, `message passing`, `concurrent container`, ... etc. Most are implemented by `C99/C11` or `C++11`, some in `Java`.

## Concurrent Object
Consider a lock-based FIFO queue, it works correct concurrently. But, `enqueue` and `dequeue` *can't takes effect concurrently*, they are still sequential. This section will implements a concurrent FIFO queue without lock, compared with a lock-based implementation <sup>[[`1`](http://cs.brown.edu/courses/cs176/lectures/chapter_03.pdf)]</sup>.
- Lock-based FIFO queue</br>
  It *can't takes effect concurrently*, still sequential, one possibility could be like that:
  ```
    thread 1:                   lock enque unlock
    thread 2: lock enque unlock
    thread 3:                                                       lock deque unlock
    thread 4:                                     lock deque unlock
  ```
- FIFO queue without lock</br>
  In this simple implementation, it only works on two threads, one for `enqueue` ONLY, another for `dequeue` ONLY.</br>
  It *takes effect concurrently*,  one possibility could be like that:
  ```
   thread 1: enque  enque
   thread 2:   deque  deque
  ```

`Linearizability` is a correctness condition for concurrent objects <sup>[[`2`](https://cs.brown.edu/~mph/HerlihyW90/p463-herlihy.pdf)]</sup>, this section will experiments it through study the paper [`Linearizability: A Correctness Condition for Concurrent Objects`](https://cs.brown.edu/~mph/HerlihyW90/p463-herlihy.pdf).

## Wait-Free Synchronization
This paper [`Wait-free synchronization`](https://dl.acm.org/doi/10.1145/114005.102808) shows a simple universal objects from which one can construct a wait-free implementation of any sequential object <sup>[[`3`](https://dl.acm.org/doi/10.1145/114005.102808), [`4`](http://cs.brown.edu/courses/cs176/lectures/chapter_05.pdf)]</sup>. This section will implements it by C11.

## Universal Construction
This paper [`WaitFreeHierarchy`](https://www.cs.yale.edu/homes/aspnes/pinewiki/WaitFreeHierarchy.html) describes `consensus number`, `consensus objects` and `universality of consensus`, after experiments on consensus this section will implements a `wait-free universal construction` <sup>[[`5`](https://www.semanticscholar.org/paper/A-Universal-Construction-for-Concurrent-Objects-Guerraoui-Raynal/a2b636c979c2581eff2e0d67dea269fb4d8067d1/figure/0), [`6`](http://cs.brown.edu/courses/cs176/lectures/chapter_06.pdf)]</sup> by C11.

## Concurrent Collections in Java
As mentioned above we see a lock-based FIFO queue, now we will see how `BlockingQueue`, `ConcurrentLinkedQueue` works. This section will implements a simple lock-based FIFO queue <sup>[[`7`](https://docs.oracle.com/javase/8/docs/api/java/util/concurrent/BlockingQueue.html)]</sup>, and implements a simple concurrent FIFO queue without lock <sup>[[`8`](https://github.com/frohoff/jdk8u-jdk/blob/master/src/share/classes/java/util/concurrent/ConcurrentLinkedQueue.java)]</sup>.

## References
- [ ] [Lamport, L.. “How to Make a Multiprocessor Computer That Correctly Executes Multiprocess Programs.” IEEE Transactions on Computers C-28 (1979): 690-691.](https://www.semanticscholar.org/paper/How-to-Make-a-Multiprocessor-Computer-That-Executes-Lamport/bdacc240ee817e6565f27f40f8658c037a457a13)
- [ ] [Maurice Herlihy. 1991. Wait-free synchronization. ACM Trans. Program. Lang. Syst. 13, 1 (Jan. 1991), 124–149. DOI:https://doi.org/10.1145/114005.102808](https://dl.acm.org/doi/10.1145/114005.102808)
- [ ] [Figure 1. A wait-free universal construction](https://www.semanticscholar.org/paper/A-Universal-Construction-for-Concurrent-Objects-Guerraoui-Raynal/a2b636c979c2581eff2e0d67dea269fb4d8067d1/figure/0)
- [ ] [MIT, Fall 2014, 6.005 — Software Construction, Reading 17: Concurrency](http://web.mit.edu/6.005/www/fa14/classes/17-concurrency/)
