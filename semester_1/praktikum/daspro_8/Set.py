from templateList import *

# DEFINISI DAN SPESIFIKASI
# rember1 : integer, list : intefger--> List
#    {rember1 (x, L) menghapus 1 elemen x kembar dalam set dengan metode konso}
def rember1 (x, L) :
    if isEmpty(L) :
        return []
    elif x == firstElmt(L) :
        return tail(L)
    else :
        return konso(firstElmt(L), rember1(x, tail(L)))

# DEFINISI DAN SPESIFIKASI
# rember2 : integer, list --> List
#    {rember2 (x, L) menghapus 1 elemen x kembar dalam set dengan metode konsi}
def rember2 (x, L) :
    if isEmpty(L) :
        return []
    elif x == lastElmt(L) :
        return head(L)
    else :
        return konsi(rember2(x, head(L)), lastElmt(L))
    

# DEFINISI DAN SPESIFIKASI
# MultiRember : integer, list --> list
#    {MultiRember (x, L) menghapus seluruh elemen x dalam set}
def MultiRember (x, L) :
    if isEmpty(L) :
        return []
    elif x == firstElmt(L) :
        return MultiRember(x, tail(L)) 
    else :
        return konso(firstElmt(L), MultiRember(x, tail(L)))
    
# DEFINISI DAN SPESIFIKASI
# MakeSet1 : list --> set
#    {MakeSet1 (L) mengubah list menjadi set (tidak ada elemen kembar) dengan metode rember (dari belakang)}
def MakeSet1 (L) :
    if isEmpty(L) :
        return []
    else :
        if isMember(firstElmt(L), tail(L)) :
            return MakeSet1(tail(L))
        else :
            return konso(firstElmt(L), MakeSet1(tail(L)))
    

# DEFINISI DAN SPESIFIKASI
# MakeSet2 : list --> set
#    {MakeSet2 (L) mengubah list menjadi set (tidak ada elemen kembar) dengan metode multi rember (dari depan)}
def MakeSet2 (L) :
    if isEmpty(L) :
        return []
    else :
        return konso(firstElmt(L), MakeSet2(MultiRember(firstElmt(L), tail(L))))
    
# DEFINISI DAN SPESIFIKASI
# konsoSet : elemen, set : integer --> set
#    {konsoSet (e, L) menambahkan elemen kedalam sebuah set dari depan dengan syarat tidak ada elemen kembar}
def konsoSet (e, L) :
    if isMember(e, L) :
        return L
    else :
        return konso(e, L)
    
# DEFINISI DAN SPESIFIKASI
# IsSet : list --> boolean
#    {IsSet (L) mengecek apakah sebuah list merupakan set atau tidak}
def IsSet (L) :
    if isEmpty(L) :
        return True
    elif isMember(firstElmt(L), tail(L)) :
        return False
    else :
        return IsSet(tail(L))
    
# DEFINISI DAN SPESIFIKASI
# IsSubSet : 2 set --> boolean
#    {IsSubSet (L1, L2) mengecek apakah semua elemen di L1 adalah elemen di L2}
def IsSubSet (L1, L2) :
    if isEmpty(L1) and isEmpty(L2) : 
        return True
    elif isEmpty(L1) and not isEmpty(L2) :
        return True
    elif not isEmpty(L1) and isEmpty (L2) :
        return False
    else :
        if isMember(firstElmt(L1), L2) :
            return IsSubSet(tail(L1), L2)
        else :
            return False
        
# DEFINISI DAN SPESIFIKASI
# IsEqualSet1 : 2 set --> boolean
#    {IsEqualSet1 (L1, L2) mengecek apakah set 1 sama dengan set 2 dengan metode isSubSet}
def IsEqualSet1 (L1, L2) :
    if nbElemen(L1) == nbElemen(L2) :
        return IsSubSet(L1, L2) and IsSubSet(L2, L1)
    else : 
        return False
    
# DEFINISI DAN SPESIFIKASI
# IsEqualSet2 : 2 set  --> boolean
#    {IsEqualSet2 (L1, L2) mengecek apakah set 1 sama dengan set 2}
def IsEqualSet2 (L1, L2) :
    if isEmpty(L1) and isEmpty(L2) : 
        return True
    elif isEmpty(L1) or isEmpty(L2) : 
        return False
    else :
        if isMember(firstElmt(L1), L2) :
            return IsEqualSet2(tail(L1), MultiRember(firstElmt(L1), L2)) 
        else :
            return False


# DEFINISI DAN SPESIFIKASI
# makeIntersect : 2 set --> set
#    {makeIntersect (L1, l2) membuat himpunan irisan dari 2 himpunan dilihat dari himpunan pertama}
def makeIntersect (L1, L2) :
    if isEmpty(L1) or isEmpty(L2) :
        return []
    else :
        if isMember(firstElmt(L1), L2) :
            return konso(firstElmt(L1), makeIntersect(tail(L1), L2))
        else :
            return makeIntersect(tail(L1), L2)
        
# DEFINISI DAN SPESIFIKASI
# makeIntersect2 : 2 set --> set
#    {makeIntersect2 (L1, l2) membuat himpunan irisan dari 2 himpunan dilihat dari himpunan kedua}
def makeIntersect2 (L1, L2) :
    if isEmpty(L1) or isEmpty(L2) :
        return []
    else :
        if isMember(firstElmt(L2), L1) :
            return konso(firstElmt(L2), makeIntersect2(tail(L2), L1))
        else :
            return makeIntersect2(tail(L2), L1)

# DEFINISI DAN SPESIFIKASI
# NBIntersect : 2 set --> integer
#    {NBIntersect (L1, L2) menghitung jumlah elemen beririsan dari 2 himpunan}
def NBIntersect (L1, L2) :
    if isEmpty(L1) or isEmpty(L2) :
        return 0
    else :
        if isMember(firstElmt(L1), L2) :
            return 1+ NBIntersect(tail(L1), L2)
        else :
            return NBIntersect(tail(L1), L2)

# DEFINISI DAN SPESIFIKASI
# IsInterSect : 2 set --> boolean
#    {IsInterSect (L1, L2) mengecek apakan 2 himpunan memiliki irisan atau tidak}
def IsInterSect (L1, L2) :
    return NBIntersect(L1, L2) != 0


# DEFINISI DAN SPESIFIKASI
# MakeUnion : 2 set --> set
#    {MakeUnion (L1, L2) membuat himpunan gabungan dari 2 himpunan}
def MakeUnion (L1, L2) : 
    if isEmpty(L1) and isEmpty(L2) :
        return []
    elif isEmpty(L1) :
        return (L2)
    elif isEmpty(L2) :
        return (L1)
    else :
        if isMember(firstElmt(L1), L2) :
            return MakeUnion(tail(L1), L2)
        else :
            return MakeSet2(konso(firstElmt(L1), MakeUnion(tail(L1), L2)))
        
# DEFINISI DAN SPESIFIKASI
# MakeUnion2 : 2 set --> set
#    {MakeUnion2 (L1, L2) membuat himpunan gabungan dari 2 himpunan}
def MakeUnion2 (L1, L2) : 
    # return MakeUnion(L2, L1)
    if isEmpty(L1) and isEmpty(L2) :
        return []
    elif isEmpty(L1) :
        return (L2)
    elif isEmpty(L2) :
        return (L1)
    else :
        if isMember(firstElmt(L2), L1) :
            return MakeUnion2(tail(L2), L1)
        else :
            return konso(firstElmt(L2), MakeUnion2(tail(L2), L1))

# DEFINISI DAN SPESIFIKASI
# NBunion : 2 set --> integer
#    {NBunion (L1, L2) menghitung jumlah elemen gabungan dari 2 himpunan}
def NBunion (L1, L2) :
    if isEmpty(L1) and isEmpty(L2) :
        return 0
    elif isEmpty(L1) :
        return nbElemen(L2)
    elif isEmpty(L2) :
        return nbElemen(L1)
    else :
        if isMember(firstElmt(L1), L2) :
            return NBunion(tail(L1), L2)
        else :
            return (1 + NBunion(tail(L1), L2))

list = [2, 3, 1, 4, 5, 2, 1, 1, 4, 2]
set1 = [2, 3, 5, 7]
set2 = [1, 2, 3, 4, 5, 6, 7, 8, 9]
set3 = [4, 5, 6, 8, 9]
set4 = [2, 5, 7, 3]

print(rember1(1, list))
print(rember2(1, list))
print(MultiRember(1, list))

print(MakeSet1(list))
print(MakeSet2(list))
print(IsSet(list))
print(IsSet(set1))
print(IsSubSet(set1, set2))
print(IsSubSet(set1, set3))

print(IsEqualSet1(set1, set4))
print(IsEqualSet2(set1, set4))
print(IsEqualSet1(set1, set2))
print(IsEqualSet2(set1, set2))

print(makeIntersect(set1, set2))
print(makeIntersect(set1, set3))
print(makeIntersect(set1, set4))
print(makeIntersect2(set1, set2))
print(makeIntersect2(set1, set3))
print(makeIntersect2(set1, set4))

print(NBIntersect(set1, set2))
print(NBIntersect(set1, set3))
print(NBIntersect(set1, set4))

print(MakeUnion(set1, set2))
print(MakeUnion(set1, set3))
print(MakeUnion(set1, set4))
print(MakeUnion2(set1, set2))
print(MakeUnion2(set1, set3))
print(MakeUnion2(set1, set4))

print(NBunion(set1, set2))
print(NBunion(set1, set3))
print(NBunion(set1, set4))















