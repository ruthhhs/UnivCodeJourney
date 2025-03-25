# Nama: Ruth Septriana Sipangkar
# NIM : 24060124120024

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

#DEFINISI DAN SPESIFIKASI KONSTRUKTOR
def makePN(A,PN):
    return [A,PN]

def Akar(PN):
    return PN[0]

def Anak(PN):
    return PN[1]

#DEFINISI DAN SPESIFIKASI PREDIKAT
def isTreeNEmpty(PN):
    return PN == []

def isOneElmt(PN):
    return (isTreeNEmpty(PN) == False) and (isTreeNEmpty(Anak(PN)) == True)

# DEFINISI DAN SPESIFIKASI
# AyahNina: TreeNArry --> string
# AyahNina Mencari nama dari ayah Nina
def AyahNina(P):
    if isTreeNEmpty(Anak(P)) :
        return []
    elif FirstList(Anak(P)) == 'Nina' :
        return Akar(P)
    else :
        return AyahNina(Anak(P))
    
print(AyahNina(makePN("Unggul", [makePN("Najwa", [makePN("Nina", [])]), makePN("Ade", []), makePN("Maryadi", [])])))
print(AyahNina(makePN("Martaka", [makePN("Bahuraksa", [makePN("Nina", [])]), makePN("Balangga", []), makePN("Galak", []), makePN("Zulfa", [])])))

#APLIKASI
# print(eval(input()))