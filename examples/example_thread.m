from thread import Thread

a = []

threads = [
    for i in range(10)
        t = Thread(def()
            b = {}
            return b
        )
        yield t
]

map(threads, def (t) t.start())
results = map(threads, def (t) t.join())
a = results


a = map(
    map(
        [
            for i in range(10)
                t = Thread(def()
                    b = {}
                    return b
                )
                yield t
        ],
        def (t) t.start()
    ),
    def (t) t.join()
)


a = [
    [
        for t in [
            for i in range(10)
                t = Thread(def()
                    b = {}
                    return b
                )
                yield t
        ]
            t.start()
            yield t
    ]
        r = t.join()
        yield r
]
