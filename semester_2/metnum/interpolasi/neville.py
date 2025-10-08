def neville(x, y, xp):
    # Menghitung nilai interpolasi Neville di xp
    n = len(x)
    q = [[0] * n for _ in range(n)]

    for i in range(n):
        q[i][0] = y[i] 

    for j in range(1, n):
        for i in range(n - j):
            q[i][j] = ((xp - x[i+j]) * q[i][j-1] + (x[i] -xp) * q[i+1][j-1]) / (x[i] - x[i+j])

    return q[0][n - 1]

import numpy as np

# f(x) = cos(x)
x_points = [1, 2, 3, 4]
y_points = np.cos(x_points)

# titk yang di cari
xp = 2.5

hasil = neville(x_points, y_points, xp)
print("Interpolasi Neville di x =", xp, "adalah", hasil)

#galat
nilai_true = np.cos(xp)
galat = np.abs(nilai_true-hasil)

print("nilai hasil adalah:", hasil)
print("nilai sebenarnya adalah:", nilai_true)
print("besar galat adalah:", galat)