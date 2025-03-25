# Nama File : addOne
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

#=======================================================================================

def addOne (L, c) :
    if isEmpty(L) :
        return []
    elif isOneElmt(L):
        if firstElmt(L) + c > 1 :
            return konkat([1], [((firstElmt(L)+c) %2)])
        else :
            return [firstElmt(L) %2]
    else :
        return konsi(addOne(head(L), (lastElmt(L)+c)//2), ((lastElmt(L)+c) %2))

def delZero(l):
    if isOneElmt(l):
        return l
    elif firstElmt(l)!=0:
        return l
    else:
        return delZero(tail(l))

print (addOne([0], 0))
print (addOne([1], 0))
print (addOne([0], 1))
print (addOne([1], 1))
print(addOne([0,0,0], 1))
print (addOne([0,0,1], 1))
print (addOne([0,1,1], 1))
