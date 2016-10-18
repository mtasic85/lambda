
threads = Thread.map(range(100), def (i) { return i })
threads = map(threads, Thread.start)
map_thread_result = map(threads, Thread.join)
