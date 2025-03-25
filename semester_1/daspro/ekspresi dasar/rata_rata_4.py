def jumlah(a, b, c, d) :
    return a+b+c+d

def x2(x, y) :
    return x*y

def rata2(a, b, c, d, e, f, g, h) :
    return (jumlah(x2(a, e), x2(b, f), x2(c, g), x2(d, h))) / jumlah(e, f, g, h)

print (rata2(86, 75, 80, 85, 30, 30, 20, 20))
print (rata2(88, 85, 81, 87, 30, 30, 20, 20))