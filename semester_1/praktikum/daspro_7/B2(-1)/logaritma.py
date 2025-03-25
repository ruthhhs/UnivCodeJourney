# Nama File : Logaritma
# Nama Pembuat : 

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

# DEFINISI DAN SPESIFIKASI
# biner : integer > 0 --> list : 0, 1
#    {biner (a) adlah fungsi untuk mengubah bilangan bulat a menjadi biner}
def biner(a) :
    if a == 1 :
        return [1]
    else :
        return konkat(biner(a//2), [a%2])
    
# DEFINISI DAN SPESIFIKASI
# TranslateBinary  : List : 0, 1 --> integer
#    {TranslateBinary (L) adalah fungsi untuk menerjemahkan list berisi biner ke dalan bilangan bulat}
def TranslateBinary (L) :
    if isOneElmt(L) :
        return lastElmt(L)
    else :
        if firstElmt(L) == 1 :
            return 2**(nbElemen(L)-1) + (TranslateBinary(tail(L)))
        else :
            return 0 + (TranslateBinary(tail(L)))
        

#=======================================================================================

def log (n) :
    if n == 1 :
        return 2**n
    else :
        return [2**n, log(n-1)]
    
def logaritma (n) :
    if isEmpty(log(n)) :
        return []
    else :
        return konkat(firstElmt(log(n)), logaritma(tail(log(n))))
    
print(log(3))