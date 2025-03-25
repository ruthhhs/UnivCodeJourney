def digit(x) :
    return len(str(x))

def total(x, y, z) :
    return digit(x) + digit(y) + digit(z)

print (total(10, 10, 10))
print (total(123, 34, 456))
print (total(333, 4444, 55555))