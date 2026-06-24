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

def Kuadran(P:make_point) -> int:
    if absis(P) > 0 and ordinat(P) > 0:
        return 1
    elif absis(P) < 0 and ordinat(P) > 0:
        return 2
    elif absis(P) < 0 and ordinat(P) < 0:
        return 3
    elif absis(P)>0 and ordinat(P)<0:
        return 4
    elif absis(P)==0 and ordinat(P) == 0:
        return "Origin"
    elif absis(P) == 0:
        return "Berhimpitan dangan sumbu y"
    elif ordinat(P) == 0:
        return "Berhimpitan dengan sumbu x"

def isEqualTitik(t1:make_point, t2:make_point) -> bool:
    return (absis(t1) == absis(t2)) and (ordinat(t1) == ordinat(t2))



# p1 = make_point(0,2)
# p2 = make_point(0,2)
# print(isEqualTitik(p1, p2))

# print(isEqualTitik(make_point(0,2), make_point(0,2)))
def jaraktitik(p: make_point) -> int:
    return ( absis(p) ** 2 + ordinat(p) ** 2  ) ** 0.5
p = make_point(1,3)
print(jaraktitik(p))