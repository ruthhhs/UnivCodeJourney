#NAMA: Ruth Septriana Sipangkar
#NIM : 24060124120024

# DEFINISI DAN SPESIFIKASI KONSTRUKTOR
# MakePB: integer, 2 PohonBiner --> PohonBiner
# MakePB(A, L, R) membuat Pohon Biner yang terdiri dari akar yang berupa elemen, 
# L dan R adalah Pohon Biner yang merupakan sub pohon kiri dan sub pohon kanan
# REALISASI
def MakePB(A, L, R):
    return [A, L, R]

# DEFINISI DAN SPESIFIKASI SELEKTOR
# Akar: PohonBiner --> integer
# Akar(P) mengembalikan akar dari sebuah PohonBiner
# REALISASI
def Akar(P):
    return P[0]

# DEFINISI DAN SPESIFIKASI SELEKTOR
# Left: PohonBiner --> PohonBiner
# Left(P) mengembalikan subpohon kiri dari sebuah PohonBiner
# REALISASI
def Left(P):
    return P[1]

# DEFINISI DAN SPESIFIKASI SELEKTOR
# Right: PohonBiner --> PohonBiner
# Right(P) mengembalikan subpohon kanan dari sebuah PohonBiner
# REALISASI
def Right(P):
    return P[2]

# DEFINISI DAN SPESIFIKASI PREDIKAT
# DEFINISI DAN SPESIFIKASI
# IsTreeEmpty: T --> boolean
# IsTreeEmpty Mengecek apakah Tree kosong
def IsTreeEmpty(T):
    return len(T) == 0

# DEFINISI DAN SPESIFIKASI
# IsOneElmt: Binary Tree --> boolean
# IsOneElmt Cek apakah Tree hanya satu elemen
def IsOneElmt(T):
    return not IsTreeEmpty(T) and IsTreeEmpty(Left(T)) and IsTreeEmpty(Right(T))

# DEFINISI DAN SPESIFIKASI
# IsUnerLeft: Binary Tree --> boolean
# IsUnerLeft Cek apakah sebuah tree Hanya mengandung sub pohon kiri
def IsUnerLeft(P):
    return not IsTreeEmpty(Left(P)) and IsTreeEmpty(Right(P))

# DEFINISI DAN SPESIFIKASI
# IsUnerRight: Binary Tree --> boolean
# IsUnerRight Cek apakah sebuah tree hanya mengandung sub pohon kanan
def IsUnerRight(P):
    return IsTreeEmpty(Left(P)) and not IsTreeEmpty(Right(P))

# DEFINISI DAN SPESIFIKASI
# IsBiner: Binary Tree --> boolean
# IsBiner Cek apakah Tree mengandung sub pohon kiri dan kanan
def IsBiner(P):
    return not IsTreeEmpty(Left(P)) and not IsTreeEmpty(Right(P))

# DEFINISI DAN SPESIFIKASI
# IsExistLeft: Binary Tree --> boolean
# IsExistLeft Cek apakah Tree memiliki sub pohon kiri
def IsExistLeft(P):
    return not IsTreeEmpty(Left(P))

# DEFINISI DAN SPESIFIKASI
# IsExistRight: Binary Tree --> boolean
# IsExistRight Cek apakah Tree memiliki sub pohon kanan
def IsExistRight(P):
    return not IsTreeEmpty(Right(P))