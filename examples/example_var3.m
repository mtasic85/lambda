a = []
b = [1, a]
c = [2, a]

b[1] is a
c[1] is a

a.append(10)

b[1] is not a
c[1] is not a
