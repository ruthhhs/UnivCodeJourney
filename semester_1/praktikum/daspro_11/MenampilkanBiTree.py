from praktikum.daspro_11.BinaryTree import *

# Nama: Ruth Septriana Sipangkar
# NIM : 2460124120024

# DEFINISI DAN SPESIFIKASI PRINT

# DEFINISI DAN SPESIFIKASI
# RepPrefix: Binary Tree --> List of List
# RepPrefix Mengubah struktur Binary Tree menjadi list of list
def RepPrefix(T):
    if IsTreeEmpty(T) :
        return []
    elif IsOneElmt(T) :
        return MakePB (Akar(T), [], [])
    else :
        return MakePB(Akar(T), RepPrefix(Left(T)), RepPrefix(Right(T)))

# DEFINISI DAN SPESIFIKASI
# MakeListDaun: Binary Tree --> List
# MakeListDaun Membuat List yang berisi elemen dari daun
def MakeListDaun(P):
    if IsTreeEmpty(P) :
        return []
    elif IsOneElmt(P) :
        return [Akar(P)]
    else :
        return MakeListDaun(Left(P)) + MakeListDaun(Right(P))

# DEFINISI DAN SPESIFIKASI
# MakeListPreOrder: Binary Tree --> List
# MakeListPreOrder Mencetak Tree dengan posisi elemen PreOrder
def MakeListPreOrder(P):
    if IsTreeEmpty(P) :
        return []
    elif IsOneElmt(P) :
        return [Akar(P)]
    else :
        return [Akar(P)] + MakeListPreOrder(Left(P)) + MakeListPreOrder(Right(P))

# DEFINISI DAN SPESIFIKASI
# MakeListInOrder: Binary Tree --> List
# MakeListInOrder Mencetak Tree dengan posisi elemen InOrder 
def MakeListInOrder(P) :
    if IsTreeEmpty(P) :
        return []
    elif IsOneElmt(P) :
        return [Akar(P)]
    else :
        return MakeListInOrder(Left(P)) + [Akar(P)] + MakeListInOrder(Right(P))

# DEFINISI DAN SPESIFIKASI
# MakeListPostOrder: Binary Tree --> List
# MakeListPostOrder Mencetak Tree dengan posisi elemen PostOrder 
def MakeListPostOrder(P) :
    if IsTreeEmpty(P) :
        return []
    elif IsOneElmt(P) :
        return [Akar(P)]
    else :
        return MakeListPostOrder(Left(P)) + MakeListPostOrder(Right(P)) + [Akar(P)]

# APLIKASI
# import sys
# exec(''.join(sys.stdin.readlines()))

# print(RepPrefix(MakePB('Saburo', MakePB('Rendi', MakePB('Ruth', [], []), MakePB('Aqila', MakePB('Syifa', [], []), MakePB('Eko', [], []))), MakePB('Rayhan', MakePB('Silvani', [], []), []))))
# print(MakeListDaun(MakePB('Saburo', MakePB('Rendi', MakePB('Ruth', [], []), MakePB('Aqila', MakePB('Syifa', [], []), MakePB('Eko', [], []))), MakePB('Rayhan', MakePB('Silvani', [], []), []))))
# print(MakeListPreOrder(MakePB('Saburo', MakePB('Rendi', MakePB('Ruth', [], []), MakePB('Aqila', MakePB('Syifa', [], []), MakePB('Eko', [], []))), MakePB('Rayhan', MakePB('Silvani', [], []), []))))
# print(MakeListInOrder(MakePB('Saburo', MakePB('Rendi', MakePB('Ruth', [], []), MakePB('Aqila', MakePB('Syifa', [], []), MakePB('Eko', [], []))), MakePB('Rayhan', MakePB('Silvani', [], []), []))))
# print(MakeListPostOrder(MakePB('Saburo', MakePB('Rendi', MakePB('Ruth', [], []), MakePB('Aqila', MakePB('Syifa', [], []), MakePB('Eko', [], []))), MakePB('Rayhan', MakePB('Silvani', [], []), []))))
