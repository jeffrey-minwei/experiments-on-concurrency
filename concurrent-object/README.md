# Experiments on Concurrent Object

Consider a lock-based FIFO queue, it works correct concurrently. But, `enqueue` and `dequeue` *can't takes effect concurrently*, they are still **sequential**. 

- Lock-based FIFO queue</br>
  It *can't takes effect concurrently*, still **sequential**, one possibility could be like that:
  ```
  thread 1:                   lock enque unlock
  thread 2: lock enque unlock
  thread 3:                                                       lock deque unlock
  thread 4:                                     lock deque unlock
  ```
- FIFO queue without lock</br>
  In this simple implementation, it only works on two threads, one for `enqueue` **ONLY**, another for `dequeue` **ONLY**.</br>
  It takes effect **concurrently**,  one possibility could be like that:
  ```
  thread 1: enque  enque
  thread 2:   deque  deque
  ```

## Lock-based FIFO queue

```shell
make clean
make lock_queue
sudo perf stat -r 10 ./lock_queue
```

The result might be like that:
```shell
...
-----------------------
lock-enque
            unlock-enque
lock-enque
            unlock-enque
lock-deque
            unlock-deque
lock-deque
            unlock-deque
-----------------------
lock-enque
            unlock-enque
lock-deque
            unlock-deque
lock-deque
lock_queue: lock_queue.c:30: dequeue: Assertion `head != tail' failed.
...
```

At the case above, the sequence like that:
```
thread 1:                   lock enque unlock
thread 2: lock enque unlock
thread 3:                                                       lock deque unlock
thread 4:                                     lock deque unlock
```  

## References
- [ ] [Concurrent Objects](http://cs.brown.edu/courses/cs176/lectures/chapter_03.pdf)
