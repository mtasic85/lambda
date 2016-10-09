
#
# 1
#
class A
    def __new__(self, x, y, z)
        self.x = x
        self.y = y
        self.z = z

a = A(10, 20, 30)
a0 = a
a.x = -a.x
a1 = a

a0 is not a1
a0 is not a
a1 is a

#
# 2
#
A = class
    def __new__(self, x, y, z)
        self.x = x
        self.y = y
        self.z = z

#
# 3
#
class A def __new__(self, x, y, z) self.x, self.y, self.z = x, y, z
A = class def __new__(self, x, y, z) self.x, self.y, self.z = x, y, z
a = (class A def __new__(self, x, y, z) self.x, self.y, self.z = x, y, z)(10, 20, 30)