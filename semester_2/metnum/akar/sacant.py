# definisikan fungsi
def f(x) :
    return x**3 + 3*x -5

# metode
def secant(x0, x1, e, max) :
    for n in range(max) :
        if (f(x1) - f(x0)) == 0 :
            return None
        
        xnew = x0 - f(x0) * (x0 - x1) / (f(x0) - f(x1))
        print(f"iterasi {n} = {x1}")
        x0, x1 = x1, xnew

        if abs(x1 - x0) < e :
            return x1
        x = x1
        n += 1
    return x

# contoh penerapan
x0 = 1.5
x1 = 2
e = 1e-6
max = 100
print(secant(x0, x1, e, max))