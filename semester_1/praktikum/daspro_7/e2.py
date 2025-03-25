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

# DEFINISI DAN SPESIFIKASI
# isPolindrom : List of character --> boolean
#    {isPolindrom (L) akan bernialai benar jika L meruakan list dengan elemen yang sama jika dibaca dari kiri maupun kanan}
def isPolindrom(L) :
    if isEmpty(L) :
        return False
    elif isOneElmt(L) :
        return True
    elif firstElmt(L) == lastElmt(L) :
        return isPolindrom(head(tail(L)))
    else :
        return False


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
# copy : List --> List
#    {copy (L) fungsi yang menduplikat sebuah list secar aidentik}
def copy (L) :
    if isEmpty(L) :
        return []
    else :
        return konso(firstElmt(L), copy(tail(L)))

# DEFINISI DAN SPESIFIKASI
# invers : List --> List
#    {invers (L) adalah sebuah fungsi yang menduplikat sebuah list dengan berkebalikan atau dari belakang}
def invers (L) :
    if isEmpty(L) :
        return []
    else :
        return konsi(invers(tail(L)), firstElmt(L))

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

# DEFINISI DAN SPESIFIKASI
# avarageElemen : List of integer --> real
#    {avarageElemen (L) adalah fungsi menghitung rata rata tiap elemen di dalam list}
def avarageElemen (L) :
    if isEmpty(L) :
        return 0.0
    elif isOneElmt(L) :
        return firstElmt(L) / 1.0
    else :
        return sumElemen(L) / nbElemen(L)

# DEFINISI DAN SPESIFIKASI
# maxElemen : List of integer --> integer
#    {maxElemen (L) adalah fungsi yang mengambil elemen dengan nilai terbesar di dalam list}
def maxElemen (L) :
    if isEmpty(L) :
        return 0
    elif isOneElmt(L) :
        return firstElmt(L)
    elif firstElmt(L) > lastElmt(L) :
        return maxElemen(head(L))
    else :
        return maxElemen(tail(L))

# DEFINISI DAN SPESIFIKASI
# addList : 2 List of integer --> List of integer
#    {addList (L1, L2) adalah fungsi untuk membuat list baru dengan menjumlahkan setiap elemen dari L1 dan L2 di posisi yang sama dengan syarat nbElemen L1 sama dengan nbElemen L2}
def addList (L1, L2) :
    if nbElemen(L1) == 0 or nbElemen(L2) == 0 :
        return []
    elif nbElemen(L1) != nbElemen(L2) :
        return []
    else :
        return konso(firstElmt(L1) + firstElmt(L2) , (addList(tail(L1), tail(L2))))

# DEFINISI DAN SPESIFIKASI
# maxNb : List of integer --> <integer, integer>
#    {maxNb (L) adalah fungsi untuk mengambil elemen dengan nilai maksimal dan jumlah elemen tersebut di dalam list
#     dan mengeluarkan tuple yang berisikan <max, countMax>}
def maxNb (L) :
    return (maxNbHelp(L, 0, 0))

def maxNbHelp (L, max, count) :
    if isEmpty(L) :
        return [max, count]
    else :
        if firstElmt(L) > max :
            return maxNbHelp(tail(L), firstElmt(L), 1)
        elif firstElmt(L) == max :
            return maxNbHelp(tail(L), max, count +1)
        else :
            return maxNbHelp(tail(L), max, count) 

#==============================================================
# aplikasi

yey = [1, 2, 3, 4, 5] # L1
yipiy = [2, 4, 6] # L2
yay = [1, 3, 5, 4, 2] # L3
iyey = [24, 33, 26, 78, 11] # L4

# print(nbElemen(yey))
# print(elemenkeN(2, yey))
# print(isMember(0, yey))
# print(copy(yey))
# print(invers(yey))
# print(konkat(yey, yipiy))
# print(sumElemen(yey))
# print(avarageElemen(yey))
# print(avarageElemen(yay))
# print(addList(yey, yipiy))
# print(addList(yey, yey))
# print(maxElemen(yay))
# print(maxElemen(iyey))
# print(isPolindrom(['y', 'e', 'y']))
# print(isPolindrom(['i', 'y', 'e', 'y']))
# print(maxNb([1, 2, 2, 5, 5, 3, 4, 3, 3, 3, 3, 4]))