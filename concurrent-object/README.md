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
  In this simple implementation, it only works on two threads, one for `enqueue`, another for `dequeue`.</br>
  It takes effect **concurrently**,  one possibility could be like that:
  ```
   thread 1: enque  enque
   thread 2:   deque  deque
  ```
