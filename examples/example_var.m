
a = []      # closure['a'] = []
a0 = a      # closure['a0'] = closure['a']
a.append(1) # _a_0 = copy(a)
            # _v_0 = _a_0.append(1)
            # closure['a'] = _a_0
a1 = a      # closure['a1'] = closure['a']
a.append(2) # _a_1 = copy(a)
            # _v_1 = _a_1.append(1)
            # closure['a'] = _a_1
a2 = a      # closure['a2'] = closure['a']

a0 == []
a1 == [1]
a2 == [1, 2]
a0 is not a
a1 is not a
a2 is a



a = 0       # closure['a'] = 0
a0 = a      # closure['a0'] = closure['a']
a += 1      # _a_0 = copy(a)
            # _a_0 = _a_0 + 1
            # closure['a'] = _a_0
a1 = a      # closure['a1'] = closure['a']
a *= 2.0    # _a_1 = copy(a)
            # _a_1 = _a_1 * 2.0
            # closure['a'] = _a_1
a2 = a      # closure['a2'] = closure['a']

a0 == 0
a1 == 1
a2 == 2.0
a0 is not a
a1 is not a
a2 is a
