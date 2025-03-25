# Nama: Ruth Septriana Sipnagkar
# NIM: 24060124120024

# Konstruktor

# Membuat titik dari absis dan ordinat
def make_point (x,y) :
    return [x, y]

#=======================
# Selektor

# Mengambil nilai absis dari sebuah titik
def absis(P) :
    return P[0]

# Mengambil nilai ordinat dari sebuah titik
def ordinat(P) :
    return P[1]
#=======================

# Operator lainnya

# Menghitung jarak anatara 2 titik
def jarak(P1, P2):
    return ((absis(P2)-absis(P1))**2 + (ordinat(P2)-ordinat(P1))**2) **0.5

# Menghitung jarak titik dari titik pusat
def jarak0(P1):
    return ((absis(P1))**2 + (ordinat(P1)**2 )) **0.5

# Menentukan sebuah titik berada di kuadran berapa
def kuadran(P):
    if absis(P) > 0 and ordinat(P) > 0 : return "1"
    elif absis(P) < 0 and ordinat(P) > 0 : return "2"
    elif absis(P) < 0 and ordinat(P) < 0 : return "3"
    elif absis(P) > 0 and ordinat(P) < 0 : return "4"
    elif absis(P) == 0 and ordinat(P) == 0 : return "ordinat"
    else : return "sumbu simetri"

#==========================

import sys
exec(''.join(sys.stdin.readlines()))