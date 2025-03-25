# Nama File: CincinPernikahan.py
# Pembuat: Ruth Septriana Sipangkar
# Tanggal: 3 Desember 2024
# Deskripsi: Mencari hari terbaik untuk membeli cincin dalam rentang a dan b.
from math import *

# DEFINISI DAN SPESIFIKASI
# CincinPernikahan: lambda, 2 integer --> integer
# CincinPernikahan(f, a, b) mencari hari terbaik untuk membeli cincin dalam rentang a dan b.
def CincinPernikahan(f, a, b):
    if a > b :
        return a
    else :
        if f(a) <= f(b) :
            return CincinPernikahan(f, a, b-1)
        else :
            return CincinPernikahan(f, a+1, b)
  
print(CincinPernikahan(lambda x: x**2 - 8*x + 25, 1, 7))
print(CincinPernikahan(lambda x: abs((x-6)*(x+2)*(x-10)+30), 5, 15))

# APLIKASI
# print(eval(input()))