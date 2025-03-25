# Nama File: Mencari Sepuh.py
# Pembuat: Ruth Septriana Sipangkar 24060124120024
# Tanggal: 3 Desember 2024
# Deskripsi: Mencari sepuh (lowest common ancestor) dari Kagura dan Kamui.

# DEFINISI TYPE
# Type PohonBiner: <A: integer, L: PohonBiner, R: PohonBiner>
# Pohon Biner terdiri dari akar yang berupa elemen, 
# L dan R adalah Pohon Biner yang merupakan sub pohon kiri dan sub pohon kanan

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
# IsEmptyTree: PohonBiner --> boolean
# IsEmptyTree(P) mengecek apakah pohon biner P kosong atau bukan
# REALISASI
def IsEmptyTree(P):
    return P is None

# DEFINISI DAN SPESIFIKASI
# MencariSepuh: PohonBiner, 2 integer --> integer
# MencariSepuh(P, ID1, ID2) mengecek lowest common ancestor dari ID1 dan ID2
# REALISASI
def MencariSepuh(P, ID1, ID2):
    if IsEmptyTree(P) :
        return None
    elif (Akar(P) > ID1 and Akar(P) < ID2) or (Akar(P) < ID1 and Akar(P) > ID2) or Akar(P)==ID1 or Akar(P)==ID2 :
        return Akar(P)
    else :
        return MencariSepuh(Right(P), ID1, ID2) or MencariSepuh(Left(P), ID1, ID2)
    
# print(MencariSepuh(MakePB(6, MakePB(2, MakePB(0, None, None), MakePB(4, MakePB(3, None, None), MakePB(5, None, None))), MakePB(8, MakePB(7, None, None), MakePB(9, None, None))), 7, 9))
# print(MencariSepuh(MakePB(6, MakePB(2, MakePB(0, None, None), MakePB(4, MakePB(3, None, None), MakePB(5, None, None))), MakePB(8, MakePB(7, None, None), MakePB(9, None, None))), 0, 5))

# APLIKASI
# print(eval(input()))