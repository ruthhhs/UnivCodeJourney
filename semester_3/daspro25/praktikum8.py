from templateList import *
# --------------------Tugas Latihan--------------------
# DEFINISI DAN SPESIFIKASI OPERASI LIST YANG DIPERLUKAN UNTUK SET

def rember(x,L):
    if isEmpty(L):
        return []
    else :
        if firstElmt(L) == x:
            return tail(L)
        else:
            return konso(firstElmt(L), rember(x, tail(L)))
# print(rember(2, [7,2,3,5,6,2,5,2]))

# Rember2: elemen, List -> List
# {Rember2(x, L) menghapus sebuah elemen dari list L.
# Jika x ada di list L, maka elemen L berkurang 1.
# Jika x tidak ada di list L, maka L tidak berubah.
# List kosong tetap menjadi list kosong.}
def rember2(x,L):
    if isEmpty(L):
        return[]
    else:
        if lastElmt(L)== x:
            return head(L)
        else: 
            return konso(lastElmt(L), rember2(x,head(L)))
# print(rember2(3,[1,2,3,1,2,3]))

# MultiRember: elemen, List -> List
# {MultiRember(x, L) menghapus semua kemunculan elemen x dari list L.
# List baru yang dihasilkan tidak lagi memiliki elemen x.
# List kosong tetap menjadi list kosong.}

# DEFINISI DAN SPESIKASI KONSTRUKTOR SET DARI LIST

# MakeSet_V1: List -> Set
# {MakeSet_V1(L) membuat set dari list L dengan menghapus semua
# elemen yang muncul lebih dari satu, menyisakan elemen yang
# sama yang terakhir muncul.}
def makeset_v1(l):
    if isEmpty(l):
        return l
    else:
        if isMember(firstElmt(l), tail(l)):
            return makeset_v1(tail(l))
        else:
            return konso(firstElmt(l), makeset_v1(tail(l)))
# print(makeset_v1([1,1,2,2,3,3,1,2,4,4]))

# MakeSet_V2: List -> Set
# {MakeSet_V2(L) membuat set dari list L dengan menghapus semua
# elemen yang muncul lebih dari satu, menyisakan elemen yang
# sama yang pertama muncul.}
def makeset_v2(l):
    if isEmpty(l):
        return l
    else:
        if isMember(lastElmt(l), head(l)):
            return makeset_v2(tail(l))
        else:
            return konso(lastElmt(l), makeset_v2(head(l)))
# print(makeset_v1([1,2,2,3,3,1,4,4])) #[1,2,3,4]\

def MultiRember(X,L) :
    if isEmpty(L):
        return []
    else :
        if firstElmt(L) == X :
            return MultiRember(X,tail(L))
        else :
            return konso(firstElmt(L), MultiRember(X,tail(L)))
# print(MultiRember(2,[1,2,3,2]))

# DEFINISI DAN SPESIKASI KONSTRUKTOR SET

# KonsoSet: elemen, Set -> Set
# {KonsoSet(e, H) menambahkan elemen e sebagai elemen pertama dari set H
# dengan syarat e belum merupakan anggota dari set H.}
# def KonsoSet(e,S):
#     if isEmpty(S):
#         return konso(e,S)
#     else:
#         if isMember(e,S):
#             return S
#         else:
#             return konso(e,S)
        
# print(KonsoSet(2,[3,4,5]))
# def KonsoSet(e,H) :
#     if isEmpty(H) :
#         return [e]
#     else :
#         if firstElmt(H) == e:
#             return H
#         else :
#             return konso(firdtElmt(H),KonsoSet(e,tail(H)))
# print(KonsoSet(2,[1,3]))

# DEFINISI DAN SPESIFIKASI PREDIKAT

# IsSet: List -> boolean
# {IsSet(L) bernilai True apabila list L merupakan sebuah set.}
def isSet(L):
    if isEmpty(L) or isOneElmt(L):
        return True
    if firstElmt(L) == firstElmt(tail(L)):
        return False
    return isSet(tail(L))
print(isSet([1,2,3,4]))
print(isSet([1,2,2,3]))
print(isSet([1,2,1,3]))

# IsSubSet: 2 Set -> boolean
# {IsSubset(H1, H2) bernilai True apabila H1 merupakan subset dari H2.}
def isSubSet(H1,H2):
    if isEmpty(H1):
        return True
    else:
        if isMember(firstElmt(H1),H2):
            return isSubSet(tail(H1),H2)
        else:
            return False    
# print(isSubSet([1,2,3],[1,2,3,4,5]))

# IsEqualSet_V1: 2 Set -> boolean
# {IsEqualSet_V1(H1, H2) bernilai True apabila H1 adalah
# set yang sama dengan H2, dengan mengecek bahwa H1
# merupakan subset dari H2, dan sebaliknya.}
def IsEqualSet_V1(H1,H2):
    if isEmpty(H1):
        return False
    else:
        if isSubSet(H1,H2):
            if isSubSet(H2,H1):
                return True
        else:
            return False    
# print(IsEqualSet_V1([1,2,3],[1,2,3]))

# IsEqualSet_V2: 2 Set -> boolean
# {IsEqualSet_V2(H1, H2) bernilai True apabila H1 adalah
# set yang sama dengan H2, dengan mengecek setiap elemen H1
# merupakan elemen dari H2 juga dan kedua set memiliki besar yang sama.}
# IsIntersect: 2 Set -> boolean
# {IsIntersect(H1, H2) bernilai True apabila H1 beririsan dengan H2.}

# DEFINISI DAN SPESIFIKASI OPERASI TERHADAP SET

# MakeIntersect_H1: 2 Set -> Set
# {MakeIntersect_H1(H1, H2) menghasilkan set baru yang berisikan
# irisan antara elemen H1 dan H2, dengan elemen pertama H1 yang
# beririsan dengan H2 diprioritaskan untuk dimasukkan ke set yang baru.}

# MakeIntersect_H2: 2 Set -> Set
# {MakeIntersect_H2(H1, H2) menghasilkan set baru yang berisikan
# irisan antara elemen H1 dan H2, dengan elemen pertama H2 yang
# beririsan dengan H1 diprioritaskan untuk dimasukkan ke set yang baru.}

# MakeUnion_H1: 2 Set -> Set
# {MakeUnion_H1(H1, H2) menghasilkan set baru yang merupakan
# gabungan dari elemen H1 dan H2, dengan elemen H1 yang bukan merupakan
# elemen H2 diletakkan di belakang sebagai elemen terakhir dari set baru.}

# MakeUnion_H2: 2 Set -> Set
# {MakeUnion_H2(H1, H2) menghasilkan set baru yang merupakan
# gabungan dari elemen H1 dan H2, dengan elemen H2 yang bukan merupakan
# elemen H1 diletakkan di belakang sebagai elemen terakhir dari set baru.}

# NBIntersect: 2 Set -> integer
# {NBIntersect(H1, H2) menghasilkan jumlah elemen yang beririsan pada H1 dan H2
# tanpa memanfaatkan fungsi MakeIntersect sebelumnya.}

# NBUnion: 2 Set -> integer
# {NBUnion(H1, H2) menghasilkan jumlah elemen gabungan pada H1 dan H2
# tanpa memanfaatkan fungsi MakeUnion sebelumnya.}
