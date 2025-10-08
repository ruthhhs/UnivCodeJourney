def lagrange(x, y, xp):
    # Menghitung nilai interpolasi Lagrange di xp
    ny = len(x)
    yp = 0

    for i in range(ny):
        L = 1 # inisiasi rekursi
        for j in range(ny):
            if i != j:
                L *= (xp - x[j]) / (x[i] - x[j])
        yp += L * y[i]

    return yp

import numpy as np

# f(x) = cos(x)
x_points = [1, 2, 3, 4]
y_points = np.cos(x_points)

# titk yang di cari
xp = 2.5

hasil = lagrange(x_points, y_points, xp)
print("Interpolasi Lagrange di x =", xp, "adalah", hasil)

#galat
nilai_true = np.cos(xp)
galat = np.abs(nilai_true-hasil)

print("nilai hasil adalah:", hasil)
print("nilai sebenarnya adalah:", nilai_true)
print("besar galat adalah:", galat)