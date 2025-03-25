# Nama: Ruth Septriana Sipangkar
# NIM : 24060124120024

#Konstruktor
# DEFINISI DAN SPESIFIKASI
# KonsLo(e, L): elemen, List of List --> List of List
# KonsLo(e, L) Menambahkan elemen di baris awal List of List
def KonsLo(e, L):
    return [e] + L

# DEFINISI DAN SPESIFIKASI
# KonsLi(L, e): List of List, elemen --> List of List
# KonsLi(L, e) Menambah6y5ukan elemen di baris akhir List of List
def KonsLi(L, e):
    return L + [e]

# Selektor

# DEFINISI DAN SPESIFIKASI
# FirstList(L): List of List --> elemen
# FirstList(L) Menampilkan elemen pertama dari List of List
def FirstList(L):
    return L[0]

# DEFINISI DAN SPESIFIKASI
# LastList(L): List of List --> elemen
# LastList(L) Menampilkan elemen terakhir dari List of List
def LastList(L):
    return L[-1]

# DEFINISI DAN SPESIFIKASI
# HeadList(L): List of List --> List of List
# HeadList(L) List of List dengan menghilangkan elemen terakhirnya
def HeadList(L):
    return L[:-1]

# DEFINISI DAN SPESIFIKASI
# TailList(L): List of List --> List of List
# TailList(L) List of List dengan menghilangkan elemen pertamanya
def TailList(L):
    return L[1:]

# Predikat

# DEFINISI DAN SPESIFIKASI
# isEmpty(L): List of List --> boolean
# isEmpty(L) mengecek apakah List of List kosong
def IsEmpty(L):
    return L == []

# DEFINISI DAN SPESIFIKASI
# IsAtom: List of List --> boolean
# IsAtom Cek apakah S adalah atom atau bukan sebuah list
def IsAtom(S):
    return type(S) != list

# DEFINISI DAN SPESIFIKASI
# IsList: List of List --> boolean
# IsList Cek apakah S adalah List
def IsList(S):
    return type(S) == list
  
def Konkat(L1,L2):
    if IsEmpty(L1):
        return L2
    else:
        return KonsLo(FirstList(L1), Konkat(TailList(L1),L2))

def NBElmt(S):
    if IsEmpty(S):
        return 0
    else:
        if IsList(FirstList(S)):
            return NBElmt(FirstList(S)) + NBElmt(TailList(S))
        else:
            return 1 + NBElmt(TailList(S))

def insert(x, L) :
    if IsEmpty(L) :
        return [x]
    elif x <= FirstList(L) :
        return KonsLo(x, L)
    else :
        return KonsLo (FirstList(L), insert(x, TailList(L)))
    
def insort (L) :
    if IsEmpty(L) :
        return []
    else :
        return insert(FirstList(L), insort(TailList(L)))
    
# DEFINISI DAN SPESIFIKASI
# PilahX: List --> List
# PilahX Mengurutkan List sesuai kemauan Noci
def PilahX(L, x) :
    return insort(PilahXhelp(L, x)) + sisa(L, x)

def PilahXhelp(L, x):
    if IsEmpty(L) :
        return []
    elif FirstList(L) % x == 0 :
        return (KonsLo(FirstList(L), PilahXhelp(TailList(L), x)))
    else :
        return PilahXhelp(TailList(L), x)
    
def sisa (L, x) :
    if IsEmpty(L) :
        return []
    elif FirstList(L) % x != 0 :
        return (KonsLo(FirstList(L), sisa(TailList(L), x)))
    else :
        return sisa(TailList(L), x)
    

print(PilahX([157, 121, 75, 355], 1))
print(PilahX([923, 648, 239, 710, 735, 680, 1002, 206], 8))


#APLIKASI
# import ast
# print(eval(input()))