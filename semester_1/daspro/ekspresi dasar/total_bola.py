def p3(x):
    return x**3

def vol_bola(x) :
    return 4/3 * 3.14 * p3(x)

def total_vol(r, s, t) :
    return vol_bola(r) + vol_bola(s) + vol_bola(t)

print (total_vol (3, 4, 5))
print (total_vol (2, 2, 2))
print (total_vol (11, 34, 25))