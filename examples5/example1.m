
#
# generator
#
def f() {
  for i in range(10) {
    v = yield i

    if v == 2 {
      break
    }
  }
}

g = f()
a = g.next()  # returns 0
g,send(a)
a = g.next()  # returns 1
g.send(a)
a = g.next()  # returns 2
g.send(a)     # stops


#
# generator
#
def f() {
  for i in range(10) {
    yield i
  }
}

a = [for i in f() i]


#
# iterator
#
class Iter {
  def __init__(self, b, e, s) {
    self.b = b
    self.e = e
    self.s = s
    self.curr = self.b
  }

  def __iter__(self) {
    return self
  }

  def __next__(self) {
    r = self.curr
    self.curr = self.b + self.s

    if self.curr >= self.e {
      raise StopIteration('')
    }

    return r
  }
}

a = [for i in Iter(0, 10, 1) i]


#
# functions
#
def f(a, b, c=10) {}
x = f(10, b=1, c=20)

def f(*c, **d) {}
x = f(1, 2, 3, 4, 5, 6, x=10, y=20)

def f(a, b=10, *a, **b) {} # SyntaxError


#
# immutable-like data structures
#
a0 = a = []
a1 = a = a.append(1) # [1]
a2 = a = a.append(2) # [1, 2]
a3 = a = a.append(3) # [1, 2, 3]
a0 is a1
a1 is a2
a2 is a3
