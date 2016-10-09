
def f(h)
    return def(*args, **kwargs) {
        return h(*args, **kwargs) 
    }

x = f(def(a, b=None) { return a or b })
