
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

a = [for i in [for i in Iter(0, 10, 1) i] i]


#
# functions
#
def f(a, b, c=10) {}
x = f(10, b=1, c=20)

def f(*c, **d) {}
x = f(1, 2, 3, 4, 5, 6, x=10, y=20)

def f(a, *args, b=10, **kwargs) {}
x = f(1, 2, 3, b=4, c=5, d=6)


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

a0 = a = ^[]
a1 = a = a.append(1) # [1]
a1 = a = a.append(2) # [1, 2]
a3 = a = a.append(3) # [1, 2, 3]
a0 is not a1
a1 is not a2
a2 is not a3

a0 = a = {}
a1 = a = a.set('x', 1)
a2 = a = a.set('y', 2)
a3 = a = a.set('z', 3)
a0 is a1
a1 is a2
a2 is a3

a0 = a = ^{}
a1 = a = a.set('x', 1)
a2 = a = a.set('y', 2)
a3 = a = a.set('z', 3)
a0 is not a1
a1 is not a2
a2 is not a3
a4, v = a, v = a.get('x')
a4 is a3 and v == 1


#
# chaining
#
value = ^[]
  .append(0)
  .extend(range(1, 10))
  .prepend(-1)
  .prepend(-2)
  .pop(1)[0] # (immutable_list, value)
  .map(def (n) { return n ** 2 })
  .filter(def (n) { return n % 2 })
  .reduce(def (n, a=0) { return a + n })


#
# classes
#
class A (object) {
  def __new__(cls, *args, **kwargs) {
    self = ^{} # create immutable self
    return self
  }

  def __init__(self, a, b) {
    # self = setattr(self, 'a', a)
    self.a = a
    # self = setattr(self, 'b', b)
    self.b = b
  }

  def __del__(self) {
    # pass
  }

  def get_a(self) {
    return self.a
  }

  def set_a(self, a) {
    self.a = a
  }
}


# async
import socket

def fetch(options) {
  s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
  host, port = options['host'], options['port']
  s.connect((host, port))

  request_body = '' # assume that request_body is http request body

  for size in s.send(request_body) { # IO
    _ = yield
  }

  response_buf = []

  for buf in s.recv(1024) { # IO
    response_buf.append(buf)
    _ = yield
  }

  response_body = ''.join(response_buf)
  return response_body
}

tasks = []

for i in range(100) {
  task = fetch({'url': 'www.example.com'})
  tasks.append(task)
}

def wait(tasks) {
  done_tasks = {}
  error_tasks = {}

  while {
    for task in tasks {
      if task in done_tasks or task in error_tasks {
        continue
      }

      try {
        data = task.send(null)
      } catch Exception as e {
        error_tasks[task] = e
      }

      if data {
        done_tasks[task] = data
      }
    }

    if done_tasks.len() + error_tasks.len() == tasks.len() {
      break
    }
  }

  return done_tasks, error_tasks
}

done_tasks, error_tasks = wait(tasks)
