#fungsi pecahan (P) dengan x pembilang dan y penyebut
def make_pecahan (x, y) :
    return [x, y]

def pembilang (P) :
    return P[0]

def penyebut (P) :
    return P[1]

#operasi
def jumlahP (P1, P2) :
    return make_pecahan((pembilang(P1) * penyebut(P2) + pembilang(P2) * penyebut(P1)), penyebut(P1) * penyebut(P2))

def kurangP (P1, P2) :
    return make_pecahan((pembilang(P1) * penyebut(P2) - pembilang(P2) * penyebut(P1)), penyebut(P1) * penyebut(P2))

def kaliP (P1, P2) :
    return make_pecahan ((pembilang(P1)*pembilang(P2)), penyebut(P1)*(penyebut(P2)))

def bagiP (P1, P2) :
    return make_pecahan ((pembilang(P1)*penyebut(P2)), penyebut(P1)*(pembilang(P2)))

def real (P) :
    return pembilang(P) / penyebut(P)

def isEqivalen (P1, P2) :
    return pembilang(P1) * penyebut(P2) == penyebut(P1) * pembilang(P2)

def isLess (P1, P2) :
    return pembilang(P1) * penyebut(P2) < penyebut(P1) * pembilang(P2)

def isGreat (P1, P2) :
    return pembilang(P1) * penyebut(P2) > penyebut(P1) * pembilang(P2)

#aplikasi
print (jumlahP(make_pecahan(1, 2), make_pecahan(3, 4)))
print (kurangP(make_pecahan(1, 2), make_pecahan(3, 4)))
print (kaliP(make_pecahan(1, 2), make_pecahan(3, 4)))
print (bagiP(make_pecahan(1, 2), make_pecahan(3, 4)))
print (real(make_pecahan(1, 2)))
print (isEqivalen(make_pecahan(1, 2), make_pecahan(3, 4)))
print (isLess(make_pecahan(1, 2), make_pecahan(3, 4)))
print (isGreat(make_pecahan(1, 2), make_pecahan(3, 4)))