# DEFINISI DAN SPESIFIKASI TYPE
# Konstruktor menambahkan elemen di awal, notasi prefix
# type List: [] atau [e o List]
# Konstruktor menambahkan elemen di akhir, notasi postfix
# type List: [] atau [List o e]

# DEFINISI DAN SPESIFIKASI KONSTRUKTOR
# Konso: elemen, List -> List
# {Konso(e, L) menghasilkan sebuah list dari e dan L
# dengan e sebagai elemen pertama dari L.}
# Realisasi:
def Konso(E, L):
    return [E] + L
# Aplikasi:

# Konsi: elemen, List -> List
# {Konsi(e, L) menghasilkan sebuah list dari e dan L
# dengan e sebagai elemen terakhir dari L.}
# Realisasi:
def Konsi(L, E):
    return L + [E]
# Aplikasi:

# DEFINISI DAN SPESIFIKASI SELEKTOR
# FirstElmt(L): List tidak kosong -> elemen
# {FirstElmt(L) mengembalikan elemen pertama dari L.}
# Realisasi:
def FirstElmt(L):
    return L[0]
# Aplikasi:

# LastElmt(L): List tidak kosong -> elemen
# {LastElmt(L) mengembalikan elemen terakhir dari L.}
# Realisasi:
def LastElmt(L):
    return L[-1]
# Aplikasi:

# Head(L): List tidak kosong -> List
# {Head(L) mengembalikan list L tanpa elemen terakhir
# dari L; dapat menghasilkan list kosong.}
# Realisasi:
def Head(L):
    return L[:-1]
# Aplikasi:

# Tail(L): List tidak kosong -> List
# {Tail(L) mengembalikan list L tanpa elemen pertama
# dari L; dapat menghasilkan list kosong.}
# Realisasi:
def Tail(L):
    return L[1:]
# Aplikasi:

# DEFINISI DAN SPESIFIKASI PREDIKAT
# isEmpty(L): List -> boolean
# {isEmpty(L) bernilai True jika List merupakan list kosong.}
# Realisasi:
def isEmpty(L):
    return L == []
# Aplikasi:

# IsOneElmt(L): List -> boolean
# {IsOneElmt(L) bernilai True jika List hanya memiliki
# tepat satu elemen.}
# Realisasi:
def IsOneElmt(L):
    if isEmpty(L):
        return False
    else:
        return Tail(L) == [] and Head(L) == []

# DEFINISI DAN SPESIFIKASI FUNGSI YANG MENGOPERASIKAN LIST
# NbElmt(L): List -> integer
# {NbElmt(L) menghasilkan banyaknya elemen dalam list L.}
# Realisasi:
def NbElmt(L):
    if isEmpty(L):
        return 0
    else:
        return 1 + NbElmt(Tail(L))

# --------------------Tugas Latihan--------------------
# ElmtKeN: integer ≥ 0, List -> elemen
# {ElmtKeN(N, L) menghasilkan elemen ke-N dari list L.}
def ElmtKeN(N, L) :
    if isEmpty(L) :
        return 0
    elif N == 1 :
        return FirstElmt(L)
    else :
        return ElmtKeN(N-1, Tail(L))

# IsMember: elemen, List -> boolean
# {IsMember(X, L) bernilai True apabila X merupakan elemen dari List.}
def IsMember(e, L) :
    if isEmpty(L) :
        return False
    elif e == FirstElmt(L) :
        return True
    else :
        return IsMember(e, Tail(L))

# Copy: List -> List
# {Copy(L) menghasilkan List yang identik dengan list asal.}
def Copy (L) :
    if isEmpty(L) :
        return []
    else :
        return Konso(FirstElmt(L), Copy(Tail(L)))

# Inverse: List -> List
# {Inverse(L) menghasilkan list L yang dibalik, yaitu
# yang urutan elemennya adalah kebalikan dari list awal.}
def Inverse (L) :
    if isEmpty(L) :
        return []
    else :
        return Konsi(Inverse(Tail(L)), FirstElmt(L))


# Konkat: 2 List -> List
# {Konkat(L1, L2) menghasilkan List yang merupakan hasil konkatenasi
# list L1 dan L2.}
def Konkat (L1, L2) :
    if isEmpty(L1) :
        return L2
    else :
        return Konso(FirstElmt(L1), Konkat(Tail(L1), L2))


# SumElmt(L): List of integer -> integer
# {SumElmt(L) menghasilkan bilangan bulat yang merupakan jumlah
# nilai dari seluruh elemen L.}
def SumElemen (L) :
    if isEmpty(L) :
        return 0
    else :
        return FirstElmt(L) + (SumElemen(Tail(L)))
# print(SumElemen([1, 2, 3, 4, 5]))
# print(SumElemen([]))
# print(SumElemen([2, 4, 6]))
# print(SumElemen([1, 3, 5, 4, 2]))
# print(SumElemen([24, 33, 26, 78, 11]))
# print(SumElemen([-1, 0, -5, -4, -2]))

# AvgElmt(L): List of integer -> real
# {AvgElmt(L) menghasilkan bilangan riil yang merupakan rata-rata
# nilai dari seluruh elemen L.}
def AvgElmt(L):
    if isEmpty(L):
        return 0
    elif NbElmt(L)==1:
        return FirstElmt(L)
    return (FirstElmt(L) + (NbElmt(L) - 1) * AvgElmt(Tail(L))) / NbElmt(L)
# print(AvgElmt([1, 2, 3, 4, 5]))
# print(AvgElmt([]))
# print(AvgElmt([2, 4, 6]))
# print(AvgElmt([1, 3, 5, 4, 2]))
# print(AvgElmt([24, 33, 26, 78, 11]))
# print(AvgElmt([-1, 0, -5, -4, -2]))

# MaxElmt(L): List of integer -> integer
# {MaxElmt(L) mengembalikan elemen dengan nilai maksimum dari list L.}
def MaxElmt (L) :
    if isEmpty(L) :
        return -999
    elif IsOneElmt(L) :
        return FirstElmt(L)
    elif FirstElmt(L) > LastElmt(L) :
        return MaxElmt(Head(L))
    else :
        return MaxElmt(Tail(L))
# print(MaxElmt([1, 2, 3, 4, 5]))
# print(MaxElmt([]))
# print(MaxElmt([2, 4, 6]))
# print(MaxElmt([1, 3, 5, 4, 2]))
# print(MaxElmt([24, 33, 26, 78, 11]))
# print(MaxElmt([-1, 0, -5, -4, -2]))

# MaxNB: List of integer -> <integer, integer >= 1>
# {MaxNB(L) menghasilkan tipe bentukan yang berisikan bilangan maksimum
# pada list L dan seberapa banyak bilangan itu muncul di dalam list.}
def MaxNb (L) :
    return (maxNbHelp(L, 0, 0))

def maxNbHelp (L, max, count) :
    if isEmpty(L) :
        return [max, count]
    else :
        if FirstElmt(L) > max :
            return maxNbHelp(Tail(L), FirstElmt(L), 1)
        elif FirstElmt(L) == max :
            return maxNbHelp(Tail(L), max, count +1)
        else :
            return maxNbHelp(Tail(L), max, count) 
# print(MaxNb([1, 2, 2, 3]))
# print(MaxNb([1, 2, 2, 5, 5, 3, 4, 3, 3, 3, 3, 4]))
# print(MaxNb([1, 2, 2, 3, 0, 3, 2]))
# print(MaxNb([1]))
# print(MaxNb([0, 0]))
# print(MaxNb([]))

# AddList: 2 List of integer -> List
# {AddList(L1, L2) menghasilkan list baru yang setiap elemennya adalah
# hasil penjumlahan setiap elemen di L1 dan L2 pada posisi yang sama.}
def AddList (L1, L2) :
    if NbElmt(L1) == 0 or NbElmt(L2) == 0 :
        return []
    elif NbElmt(L1) != NbElmt(L2) :
        return []
    else :
        return Konso(FirstElmt(L1) + FirstElmt(L2) , (AddList(Tail(L1), Tail(L2))))
# print(AddList([1, 2], [2, 3]))
# print(AddList([1, 2, 4], [2, 3]))
# print(AddList([1, 2, 4], [2, 3, 1]))
# print(AddList([3, 3, 3], [3, 3, 3]))
# print(AddList([3, 2, 4, 0], [2, 0, 2, 1]))
# print(AddList([], [0]))
# print(AddList([], []))

# IsPalindrom: List of character -> boolean
# {IsPalindrom(L) bernilai True jika L merupakan kata palindrom,
# yakni kata yang sama jika dibaca dari kiri atau kanan.}
def IsPalindrom(L) :
    if isEmpty(L) :
        return True
    elif IsOneElmt(L) :
        return True
    elif FirstElmt(L) == LastElmt(L) :
        return IsPalindrom(Head(Tail(L)))
    else :
        return False
# print(IsPalindrom(['a', 'y', 'a', 'm']))
# print(IsPalindrom(['m', 'a', 'l', 'a', 'm']))
# print(IsPalindrom(['a', 'p', 'e', 'l']))
# print(IsPalindrom(['k', 'a', 's', 'u', 'r']))
# print(IsPalindrom(['k', 'a', 's', 'u', 'r', 'r', 'u', 's', 'a', 'k']))
# print(IsPalindrom(['y', 'e', 'y']))
# print(IsPalindrom([]))