# Nama File : Mencuri Uang
# Nama Pembuat : Ruth Septriana Sipangkar (24060124120024)

#==========================================================================================
#Konstruktor

# DEFINISI DAN SPESIFIKASI
# konso(e, L): elemen, List --> List
# konso(e, L) Menambahkan elemen di baris awal list
def konso(e, L):
    return [e] + L

# DEFINISI DAN SPESIFIKASI
# konsi(L, e): List, elemen --> List
# konsi(L, e) Menambahkan elemen di baris akhir list
def konsi(L, e):
    return L + [e]

#==============================================================================
# Selektor

# DEFINISI DAN SPESIFIKASI
# firstElmt(L): List --> elemen
# firstElmt(L) Menampilkan elemen pertama dari List
def firstElmt(L):
    return L[0]

# DEFINISI DAN SPESIFIKASI
# lastElmt(L): List --> elemen
# lastElmt(L) Menampilkan elemen terakhir dari List
def lastElmt(L):
    return L[-1]

# DEFINISI DAN SPESIFIKASI
# head(L): List --> List
# head(L) List dengan menghilangkan elemen terakhirnya
def head(L):
    return L[:-1]

# DEFINISI DAN SPESIFIKASI
# tail(L): List --> List
# tail(L) List dengan menghilangkan elemen pertamanya
def tail(L):
    return L[1:]

#=============================================================================
# Predikat

# DEFINISI DAN SPESIFIKASI
# isEmpty(L): List --> boolean
# isEmpty(L) mengecek apakah List kosong
def isEmpty(L):
    return L == []

# DEFINISI DAN SPESIFIKASI
# isOneElmt(L): List --> integer
# isOneElmt(L) mengecek apakah List satu elemen
def isOneElmt(L):
    return len(L) == 1

# DEFINISI DAN SPESIFIKASI
# isMember : elemen, List --> boolean 
#    {isMember (e, L) adalah benar jika e merupaka elemen dari list l}
def isMember(e, L) :
    if isEmpty(L) :
        return False
    elif e == firstElmt(L) :
        return True
    else :
        return isMember(e, tail(L))


#============================================================================
# operator

# DEFINISI DAN SPESIFIKASI
# nbElemen : List --> integer
#    {nbElemen (L) adalah fungsi yang menghitung jumlah elemen dalam suatu list}
def nbElemen (L) :
    if isEmpty(L) :
        return 0
    else : 
        return 1 + nbElemen(tail(L))

# DEFINISI DAN SPESIFIKASI
# elemenkeN : integer >= 0 , List --> elemen
#    {elemenkeN (N, L) mengambil elemen list yang N dengan 0<= N <= nbElemen}
def elemenkeN(N, L) :
    if isEmpty(L) :
        return 0
    elif N == 1 :
        return firstElmt(L)
    else :
        return elemenkeN(N-1, tail(L))

# DEFINISI DAN SPESIFIKASI
# konkat : 2 List --> List
#    {konkat (L1, L2) adalah sebuah fungsi untuk menggabungkan 2 list dengan L1 di depan dan L2 dibelakang}
def konkat (L1, L2) :
    if isEmpty(L1) :
        return L2
    else :
        return konso(firstElmt(L1), konkat(tail(L1), L2))

#=======================================================================================

def strToList (x) :
    return list(x)
    
def isInt (x) :
    if x=='1' or x=='2' or x=='3' or x=='4' or x=='5' or x=='6' or x=='7' or x=='8' or x=='9' or x=='0' :
        return True
    else :
        return False
    
def angka (L) :
    if isEmpty(L) :
        return []
    else :
        if isInt(firstElmt(L)) :
            return konso(firstElmt(L), angka(tail(L)))
        else : 
            return angka(tail(L))
    
def sumElemen (L) :
    if isEmpty(L) :
        return 0
    else :
        return int(firstElmt(L)) + (sumElemen(tail(L)))

def hitung_angka(x) :
    return sumElemen(angka(strToList(x)))

print(hitung_angka("Inv35t4s1"))
