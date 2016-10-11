a = {'x': {}}
a = a.set('x', a.get('x').set('y': 10))

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
a = a.set_x(a.get_x().set('y': {}))

a = A().set_x({'y': {}})
