def max (x, y) :
    return (x+y + abs(x-y)) /2

def min (x, y) :
    return (x+y - abs(x-y)) /2

def median(x, y, z) :
    return (x+y+z - max(x, max(y,z)) - min(x, min(y, z)))

print (median(2, 6, 4))
print (median(-4, 6, 1))