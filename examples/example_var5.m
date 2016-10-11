
# t = {}
# a = t
a = {}

# t = {}
# t0 = a
# t1 = t0.__setitem__('x', t)
# a = t1
a['x'] = {}

# t = {}
# t0 = a
# t1 = t0.__getitem__('x')
# t2 = t1.__setitem__('y', t)
# t3 = t0.__setitem__('x', t2)
# a = t3
a['x']['y'] = {}

# t = {}
# t0 = a
# t1 = t0.__getitem__('x')
# t2 = t1.__getitem__('y')
# t3 = t2.__setitem__('z', t)
# t4 = t1.__setitem__('y', t3)
# t5 = t0.__setitem__('x', t4)
# a = t5
a['x']['y']['z'] = {}
