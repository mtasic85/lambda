
a = range(10)

each(a, def (i) {
    print(i)
})

for i in a {
    print(i)
}

b = map(a, def (i) {
    return i ** 2
})

b = [for i in a {
    yield i ** 2
}]
