# Experiments on Lock-free Concurrent Thread Pool

After watch the video [`並行和多執行緒程式設計 (5)`](https://www.youtube.com/watch?v=8BidMHVGeBE), I am interested on how to implements a lock-free concurrent thread pool, so I start this experimental.

Below are some point regarding this experimental.
- What is thread pool?
- Implements thread pool by using queue
- Implements with lock-based concurrent queue
- Implements with lock-free concurrent queue
- Implements with lock-free concurrent circular queue

```
$ make
```

## References
- [ ] [並行和多執行緒程式設計 (5)](https://www.youtube.com/watch?v=8BidMHVGeBE)
- [ ] [A simple C thread pool implementation](https://github.com/mbrossard/threadpool)
