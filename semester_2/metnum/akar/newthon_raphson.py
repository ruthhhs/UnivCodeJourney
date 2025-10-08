# definisikan fungsi
def f(x) :
    return x**3 + 3*x -5
# turunan fungsi
def df(x):
    return 3*x**2 - 3

# metode
def newton_raphson(x0, e, max) :
    x = x0
    for n in range(max) :
        if df(x) == 0 :
            return None
        
        x_new = x - f(x) / df(x)
        print(f"iterasi {n} = {x_new}")

        if abs(x_new - x) < e :
            return x_new
        x = x_new
        n += 1
    return x

# contoh penerapan
x0 = 1.5
e = 1e-6
max = 100
print(newton_raphson(x0, e, max))