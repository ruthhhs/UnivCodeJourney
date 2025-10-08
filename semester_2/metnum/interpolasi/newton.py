def divided_diff(x, y):
    # menghitung tabel selisih, x dan y adalah array
    ny = len(y)
    a = [y[i] for i in range(ny)] # a = y

    for j in range (1, ny) :
        for i in range (ny-1, j-1, -1) :
            a[i] = (a[i]-a[i-1]) / (x[i]-x[i-j])
    
    return a

def newton(x, y, xp):
    # menghitung interpolasi newton di xp
    a = divided_diff(x, y)
    ny = len(y)
    yp = a[0] # basis
    px = 1 # inisiasi rekursi

    for i in range(1, ny):
        px *= (xp - x[i-1])
        yp += a[i] * px
        print("Interpolasi Newton orde", i, "di x =", xp, "adalah", yp)
    return yp

import numpy as np

# f(x) = cos(x)
x_points = [1, 2, 3, 4]
y_points = np.cos(x_points)

# titk yang di cari
xp = 2.5

# orde ke-3
hasil = newton(x_points, y_points, xp)

# galat
nilai_true = np.cos(xp)
galat = np.abs(nilai_true-hasil)

print("nilai hasil adalah:", hasil)
print("nilai sebenarnya adalah:", nilai_true)
print("besar galat adalah:", galat)
