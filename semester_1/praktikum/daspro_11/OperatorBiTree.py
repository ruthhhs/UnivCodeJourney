from praktikum.daspro_11.BinaryTree import *

# Nama: Ruth Septriana Sipangkar
# NIM : 24060124120024

# DEFINISI DAN SPESIFIKASI SEARCH

# DEFINISI DAN SPESIFIKASI
# NBElmtTree: Binary Tree --> Integer
# NBElmtTree Menghitung jumlah dari elemen Binary Tree
def NBElmtTree(T):
    if IsTreeEmpty(T) :
        return 0
    elif IsOneElmt(T) :
        return 1
    else :
        return 1 + NBElmtTree(Right(T)) + NBElmtTree(Left(T))

# DEFINISI DAN SPESIFIKASI
# NBDaunTree: Binary Tree --> Integer
# NBDaunTree Menghitung daun dari sebuah binary tree
def NBDaunTree(T):
    if IsTreeEmpty(T) :
        return 0
    elif IsOneElmt(T) :
        return 1
    else :
        return NBElmtTree(Right(T)) + NBElmtTree(Left(T))

# DEFINISI DAN SPESIFIKASI
# IsMember: Binary Tree, integer --> boolean
# IsMember Mengecek apakah X ada di dalam Binary Tree
def IsMember(P, X):
    if IsTreeEmpty(P) :
        return False
    elif IsOneElmt(P) :
        return Akar(P) == X
    else :
        if Akar(P) == X :
            return True
        else :
            return IsMember(Right(P), X) or IsMember(Left(P), X)

# DEFINISI DAN SPESIFIKASI
# IsSkewLeft: Binary Tree --> booelan
# IsSkewLeft Cek apakah Binary Tree hanya memiliki node kiri untuk setiap sub pohonya
def IsSkewLeft(P):
    if IsTreeEmpty(P) :
        return True
    elif IsUnerRight(P) :
        return False
    elif IsUnerLeft(P):
        return IsSkewLeft(Left(P))
    elif IsTreeEmpty(Left(P)) and IsTreeEmpty(Right(P)) :
        return True

# DEFINISI DAN SPESIFIKASI
# IsSkewRight: Binary Tree --> booelan
# IsSkewRight Cek apakah Binary Tree hanya memiliki node kanan
def IsSkewRight(P):
    if IsTreeEmpty(P) :
        return True
    elif IsUnerLeft(P) :
        return False
    elif IsUnerRight(P):
        return IsSkewRight(Right(P))
    elif IsTreeEmpty(Left(P)) and IsTreeEmpty(Right(P)) :
        return True

# DEFINISI DAN SPESIFIKASI
# LevelOfX: Binary Tree, Integer --> Integer
# LevelOfX Mencari level dari X yang dijamin ada di dalam binary tree
def LevelOfX(P, X):
    if IsTreeEmpty(P) :
        return 0
    else :
        if X == Akar(P) :
            return 1
        else :
            if IsMember(Left(P), X) :
                return 1 + LevelOfX(Left(P), X) 
            else :
                return 1 + LevelOfX(Right(P), X)

# DEFINISI DAN SPESIFIKASI
# AddDaunTerkiri: Binary Tree, Integer --> Binary Tree
# AddDaunTerkiri Menambahkan daun terkiri dari Binary Tree
def AddDaunTerkiri(P, X):
    if IsTreeEmpty(P) :
        return []
    elif IsTreeEmpty(Left(P)) :
        return MakePB(Akar(P), MakePB(X, [], []), Right(P))
    else :
        return MakePB(Akar(P), AddDaunTerkiri(Left(P), X), Right(P))


# DEFINISI DAN SPESIFIKASI
# DelDaunTerkiri: Binary Tree --> Binary Tree
# DelDaunTerkiri Menghapus Daun Terkiri dari Binary Tree
def DelDaunTerkiri(P):
    if IsTreeEmpty(P) :
        return []
    elif IsOneElmt(Left(P)) :
        return MakePB(Akar(P), [], Right(P))
    else :
        return MakePB(Akar(P), DelDaunTerkiri(Left(P)), DelDaunTerkiri(Right(P)))

# DEFINISI DAN SPESIFIKASI
# DelDaun: Binary Tree --> Binary Tree
# DelDaun Menghapus Daun X dari Binary Tree jika ada
def DelDaun(P, X):
    if IsTreeEmpty(P) :
        return []
    elif IsOneElmt(P) :
        if X == Akar(P) :
            return []
        else :
            return P
    else :
        return MakePB(Akar(P), DelDaun(Left(P), X), DelDaun(Right(P), X))

# APLIKASI
# import sys
# exec(''.join(sys.stdin.readlines()))

# print(NBElmtTree([]))
# print(NBElmtTree(MakePB(10, MakePB(11, (MakePB(13, [], [])), []), MakePB(12, [], []))))

# print(NBDaunTree([]))
# print(NBDaunTree(MakePB(10, MakePB(11, [], []), MakePB(12, [], []))))

# print(IsMember(MakePB(10, MakePB(11, MakePB(12, [], MakePB(13, MakePB(14, [], []), [])), MakePB(16, [], [])), MakePB(5, [], [])), 10))
# print(IsMember(MakePB(10, MakePB(11, MakePB(12, [], MakePB(13, MakePB(14, [], []), [])), MakePB(16, [], [])), MakePB(5, [], [])), 99))
# print(IsMember(MakePB(10, MakePB(11, MakePB(12, [], MakePB(13, MakePB(14, [], []), [])), MakePB(16, [], [])), MakePB(5, [], [])), 14))
# print(IsMember(MakePB(10, MakePB(11, MakePB(12, [], MakePB(13, MakePB(14, [], []), [])), MakePB(16, [], [])), MakePB(5, [], [])), 113))
# print(IsMember(MakePB(10, MakePB(11, MakePB(12, [], MakePB(13, MakePB(14, [], []), [])), MakePB(16, [], [])), MakePB(5, [], [])), 13))

# print(IsSkewLeft(MakePB(10, MakePB(11, MakePB(12, MakePB(14, [], []), []), []), [])))
# print(IsSkewLeft(MakePB(10, MakePB(11, MakePB(12, MakePB(14, [], MakePB(30, [], [])), []), []), [])))
# print(IsSkewRight(MakePB(10, [], MakePB(11, [], MakePB(12, [], MakePB(14, [], []))))))
# print(IsSkewRight(MakePB(10, MakePB(11, MakePB(12, MakePB(14, [], MakePB(30, [], [])), []), []), [])))

# print(LevelOfX(MakePB(10, MakePB(11, MakePB(12, [], MakePB(13, MakePB(14, [], []), [])), MakePB(16, [], [])), MakePB(5, [], [])), 16)) # expected output 3
# print(LevelOfX(MakePB(10, MakePB(11, MakePB(12, [], MakePB(13, MakePB(14, [], []), [])), MakePB(16, [], [])), MakePB(5, [], [])), 14)) # expected output 5
# print(LevelOfX(MakePB(10, MakePB(11, MakePB(12, [], MakePB(13, MakePB(14, [], []), [])), MakePB(16, [], [])), MakePB(5, [], [])), 10)) # expected output 1

# print(AddDaunTerkiri(MakePB(10, MakePB(11, MakePB(12, [], MakePB(13, MakePB(14, [], []), [])), MakePB(16, [], [])), MakePB(5, [], [])), 110))
# print(AddDaunTerkiri(AddDaunTerkiri(MakePB(10, MakePB(11, MakePB(12, [], MakePB(13, MakePB(14, [], []), [])), MakePB(16, [], [])), MakePB(5, [], [])), 120), 300))
# print(AddDaunTerkiri(MakePB(1, [], MakePB(12, MakePB(13, [], []), MakePB(14, [], []))), 5))

# print(DelDaunTerkiri(MakePB(10, MakePB(11, MakePB(12, [], MakePB(13, MakePB(14, [], []), [])), MakePB(16, [], [])), MakePB(5, [], []))))
# print(DelDaunTerkiri(MakePB(10, MakePB(11, MakePB(12, MakePB(120,[],[]), MakePB(13, MakePB(14, [], []), [])), MakePB(16, [], [])), MakePB(5, [], []))))
# print(DelDaunTerkiri(AddDaunTerkiri(MakePB(10, MakePB(11, MakePB(12, [], MakePB(13, MakePB(14, [], []), [])), MakePB(16, [], [])), MakePB(5, [], [])), 120)))

# print(DelDaun(MakePB(10, MakePB(11, MakePB(12, [], MakePB(13, MakePB(14, [], []), [])), MakePB(16, [], [])), MakePB(5, [], [])), 5))
# print(DelDaun(AddDaunTerkiri(MakePB(10, MakePB(11, MakePB(12, [], MakePB(13, MakePB(14, [], []), [])), MakePB(16, [], [])), MakePB(5, [], [])), 120), 13))