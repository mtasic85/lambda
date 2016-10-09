
a = [0]
b = [1]
c = [2]
a.append(c)
b.append(c)
c.append(a)
c.append(b)

a == [0, [2]]
b == [1, [2]]
c == [2, [0, [2]], [1, [2]]]
