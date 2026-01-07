# Nama: Ruth Septriana Sipangkar
# NIM: 24060124120024
# Deskripsi Fungsi: List of List

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
def isEmpty(L):
    return L == []

def isOneElmt(L):
    return len(L) == 1

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

#============================================================================================
# IsMemberS: elemen, list of list-> boolean
#    {IsMemberS(x,S) mengembalikan true jika elemen x ada di dalam list of list}
def IsMemberS (x, S) :
    if isEmpty(S) :
        return False
    elif IsAtom(FirstList(S)) :
        if x == FirstList(S) :
            return True
        else :
            return IsMemberS(x, TailList(S))
    else :
        if x == FirstList(S) :
            return True
        else :
            return IsMemberS(x, FirstList(S)) or IsMemberS(x, TailList(S))
# Contoh aplikasi:
# print(IsMemberS(3, [])) #{menghasilkan false}
# print(IsMemberS(3, [2, 4, 3, [1], [4,5]])) #{menghasilkan true}
# print(IsMemberS(3, [2, 4, 7, [1], [3,5]])) #{menghasilkan true}

# Rember: elemen, list of list -> list of list
# Rember(x,S) menghapus semua elemen x yang ada di list of list S
def Rember (x, S) :
    if isEmpty(S) :
        return []
    elif IsList(FirstList(S)) :
        if x == FirstList(S) :
            return Rember(x, TailList(S))
        else :
            return KonsLo(Rember(x, FirstList(S)), Rember(x, TailList(S)))
    else :
        if x == FirstList(S) :
            return Rember(x, TailList(S))
        else :
            return KonsLo(FirstList(S), Rember(x, TailList(S)))
# Contoh aplikasi:
# print(Rember(3, [])) #menghasilkan []
# print(Rember(3, [4, 3, [2,4], 3])) #menghasilkan [4, [2,4]]
# print(Rember(3, [2, 4, [3,6,9], 5, 3])) #menghasilkan [2, 4, [6,9], 5]

def maxNb(S):
    if isEmpty(S) :
        return 0
    elif isOneElmt(S) :
        return FirstList(S)
    elif FirstList(S) > LastList(S) :
        return maxNb(HeadList(S))
    else :
        return maxNb(TailList(S))

def ListInLoL (S) :
    if isEmpty(S) :
        return []
    elif IsAtom(FirstList(S)) :
        return ListInLoL(TailList(S))
    else :
        if isOneElmt(S) :
            return NBElmtAtom(FirstList(S))
        return KonsLo(NBElmtAtom(FirstList(S)), ListInLoL(TailList(S)))
    
def atomInLoL(S) :
    if isEmpty(S) :
        return []
    elif IsAtom(FirstList(S)) :
        return KonsLo(FirstList(S), atomInLoL(TailList(S)))
    else :
        return atomInLoL(FirstList(S)) + atomInLoL(TailList(S))

# maxElmt: list of list -> elemen
# maxElmt(S) mengembalikan elemen maksimum di dalam list of list S
def maxElmt(S) :
    return maxNb(atomInLoL(S))
# Contoh aplikasi:
# print(maxElmt([4, 5, 6, [8,9,10], [12,0], 8])) #menghasilkan 12
# print(maxElmt([4, 15, 6, [8,9,10], [12,0], 8])) #menghasilkan 15

# NBElmtAtom: list of list -> integer
# NBElmtAtom(S) mengembalikan banyaknya elemen list of list S yang berupa atom
def NBElmtAtom(S) :
    if isEmpty(S) :
        return 0
    else :
        if IsAtom(FirstList(S)) :
            return 1 + NBElmtAtom(TailList(S))
        else :
            return NBElmtAtom(TailList(S))
# Contoh aplikasi:
# print(NBElmtAtom([4, 5, 6, [8,9,10], [12,0], 8])) #menghasilkan 4
# print(NBElmtAtom([4, 15, 6, [8,9], 10, [12], 8])) #menghasilkan 5
# print(NBElmtAtom([[8,9,10]])) #menghasilkan 0

# NBElmtList: list of list -> integer
# NBElmtList(S) mengembalikan banyaknya elemen list of list S yang berupa list
def NBElmtList(S) :
    if isEmpty(S) :
        return 0
    else :
        if IsList(FirstList(S)) :
            return 1 + NBElmtList(TailList(S))
        else :
            return NBElmtList(TailList(S))
# Contoh aplikasi:
# print(NBElmtList([4, 5, 6, [8,9,10], [12,0], 8])) #menghasilkan 2
# print(NBElmtList([[4, 15], 6, [8,9], 10, [12], 8])) #menghasilkan 3
# print(NBElmtList([[8,9,10]])) #menghasilkan 1

# SumLoL : List of List --> integer
#    {SumLoL (lol) menjumlahkan setiap elemen dalam List of List dalam bentuk integer}
def SumLoL (lol) :
    if isEmpty(lol) :
        return 0
    elif IsList(FirstList(lol)) :
        return SumLoL((FirstList(lol))) + SumLoL(TailList(lol))
    elif IsAtom(FirstList(lol)) :
        return FirstList(lol) + SumLoL(TailList(lol))
    else :
        return 0
# contoh aplikasi 
# print(SumLoL([1, 2, [3, 4], 5])) #{menghasilkan 15}
# print(SumLoL([[]])) #{menghasilkan 0}

# MaxNBElmtList: list of list -> integer
# MaxNBElmtList(S) mengembalikan banyaknya elemen list maksimum yang ada pada list of list S 
def MaxNBElmtList(S):
    return maxNb(ListInLoL(S))
# Contoh aplikasi:
# print(MaxNBElmtList([[4,5,6,7], [8,9,10], [12,0], 8])) #menghasilkan 4
# print(MaxNBElmtList([[4,15], 6, [8,9], 10, [12], 8])) #menghasilkan 2
# print(MaxNBElmtList([8,9,10])) #menghasilkan 0

# MaxSumElmt: list of list -> integer
# MaxSumElmt(S) mengembalikan elemen maksimum pada list of list S
# jika elemen berupa list, maka dihitung jumlahan elemen dalam list tersebut
# jika elemen atom, maka nilainya adalah elemen tersebut 
def MaxSumElmt(S) :
    return maxNb(sumListInLoL(S))

def sumListInLoL (S) :
    if isEmpty(S) :
        return []
    elif IsAtom(FirstList(S)) :
        return sumListInLoL(TailList(S))
    else :
        if isOneElmt(S) :
            return SumLoL(FirstList(S))
        return KonsLo(SumLoL(FirstList(S)), sumListInLoL(TailList(S)))
# Contoh aplikasi:
# print(MaxSumElmt([[1,2], 9, [4,5,6], 8])) #menghasilkan 15
# print(MaxSumElmt([[1,2], 90, [4,5,6], 8])) #menghasilkan 90
# print(MaxSumElmt([8,9,10])) #menghasilkan 10
# print(MaxSumElmt([[8,9,10]])) #menghasilkan 27

