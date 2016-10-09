
a = {}                  # closure['a'] = {}
a['a'] = {/}            # _t0 = copy(a)
                        # _t0['a'] = {/}
                        # freeze(_t0)
                        # closure['a'] = _t0
a['b'] = {/}            # _t1 = copy(a)
                        # _t1['b'] = {/}
                        # freeze(_t1)
                        # closure['a'] = _t1
a['c'] = {'a', 'b'}     # _t2 = copy(a)
                        # _t2['a'] = {'a', 'b'}
                        # freeze(_t2)
                        # closure['a'] = _t2

# x = a['a']
# x.add('c')
a['a'].add('c')         # _t0 = closure['a']
                        # _t1 = _t0['a']
                        # _t2 = copy(_t1)
                        # _t2.add('c')
                        # freeze(_t2)
                        # _t3 = copy(_t0)
                        # _t3['a'] = _t2
                        # freeze(_t3)
                        # closure['a'] = _t3

x = 'd' in a['c']       # closure['x'] = closure['a']['c'].__contains__('d')
