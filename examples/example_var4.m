a = {'x': {}}
a = a.set('x', a.get('x').set('y', 10))

class A
    def __init__(self)
        self.x = {}

    def set_x(self, x)
        self.x = x
        return self

    def get_x(self)
        return self.x

a = A()
a = a.set_x({'y': {}})
a = a.set_x(a.get_x().set('y', {}))

a = A().set_x({'y': {}})

s = []
    .extend(range(10))
    .map(def (n) return n ** 2.0)
    .map(def (n) return n ** 0.5)
    .map(int)
    .reduce(def(n, prev=0) return n + prev)
