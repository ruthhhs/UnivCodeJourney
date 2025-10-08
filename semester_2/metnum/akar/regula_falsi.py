# definisikan fungsi
def f(x) :
    return x**3 + 3*x -5

# metode
def regula_falsi(a, b, max) :
    n = 1
    for n in range(max) :
        if (f(b) - f(a)) == 0 :
            return None
        
        x = (a * f(b) - b * f(a)) / (f(b) - f(a))
        print(f"iterasi {n} = {x}")

        if f(x)*f(a) <0 :
            b = x
        else :
            a = x

        if abs(f(x)) < e:
          return x
        
        n += 1
    return x

# contoh penerapan
a = 1
b = 2
e= 1e-6
max = 100
print(regula_falsi(a, b, max))