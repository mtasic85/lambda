
def getattr(o, a) {

}

def setattr(o, a, v) {

}

class A {
    def __new__(self, x, y) {
        self.x = x
        self.y = y
    }

    def get_x(self) {
        return self.x
    }

    def set_x(self, x) {
        self.x = x
    }
}

a = A(10, 20)
a = a.set_x(a.get_x() + 10)

# t0 = 'a'
# t1 = 'y'
# t2 = 10
# t3 = getattr(locals, t0)
# t4 = getattr(t3, t1)
# t5 = t4 - t2
# t6 = setattr(t3, t1, t5)
# locals = setattr(locals, t0, t6)
a.y = a.y - 10
