# Nama File : Duel Sihir
# Nama Pembuat :

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
    
# DEFINISI DAN SPESIFIKASI
# sumElemen : List of integer --> integer
#    {sumElemen (L) adalah fungsi yang menjumlahkan setiap elemen di list}
def sumElemen (L) :
    if isEmpty(L) :
        return 0
    else :
        return firstElmt(L) + (sumElemen(tail(L)))

#=======================================================================================
# DEFINISI DAN SPESIFIKASI
# DuelSihir : 2 List : integer --> string
#    {DuelSihir (S, M) adalah fungsi yang menentukan siapakah pemenang antara Snape dengan McGonagall}

def DuelSihir (S, M) :
    if sumElemen(snape(S, M)) > sumElemen(mcgonagall(S, M)) :
        return "Snape Menang"
    elif sumElemen(snape(S, M)) < sumElemen(mcgonagall(S, M)) :
        return "McGonagall Menang"
    else :
        return "Keduanya Seri"


def snape(S, M) :
    if isEmpty(S) and isEmpty(M) :
        return []
    else :
        if firstElmt(S) > firstElmt(M) :
            return konso(1, snape(tail(S), tail(M)))
        else :
            return konso(0, snape(tail(S), tail(M)))
        
def mcgonagall(S, M) :
    if isEmpty(S) and isEmpty(M) :
        return []
    else :
        if firstElmt(S) < firstElmt(M) :
            return konso(1, mcgonagall(tail(S), tail(M)))
        else :
            return konso(0, mcgonagall(tail(S), tail(M)))

# print(DuelSihir([10, 20], [15, 10]))

print(eval(input()))