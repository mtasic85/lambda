
def g(a):
    # REF(a)

    a.append(true)

    # UNREF(a)
    return a


def f():
    # mutable object
    a = []
    a.append(10)
    a.append(-1.0)

    b = g(a)

    # UNREF(a)
    return b


def main():
    a = f()
    # REF(a)

a = []
b = []
a = a + [b]
b = b + [a]
