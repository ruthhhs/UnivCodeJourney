# definisikan fungsi
def f(x) :
    return x**3 + 3*x -5

# metode
def bisection(a, b, e) :
    n = 1
    while (b-a) > e :
        x = (a+b)/2
        print(f"nilai x di iterasi {n} dengan interval [{a}, {b}]= {x}")

        if f(x)*f(a) <0 :
            b = x
        else :
            a = x
        n += 1
    return x

# contoh penerapan
a = 0
b = 2
e = 1e-6
print(bisection(a, b, e))