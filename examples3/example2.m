

class A {
    def __new__(self, x, y, z) {
        self.x = x
        self.y = y
        self.z = z
        return self
    }

    def get_x(self) {
        return self.x
    }

    def set_x(self) {
        self.x = x
        return self
    }
}

a = A(10, 20, 30)
    .set_x(-1)
    .set_x(-2)
    .set_x(10)
