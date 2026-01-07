# DEFINISI DAN SPESIFIKASI KONSTRUKTOR
# MakePB: elemen, PohonBiner, PohonBiner -> PohonBiner
# {MakePB(A, L, R) membuat pohon biner dengan A sebagai akar, L sebagai anak kiri dari
# pohon, dan R sebagai anak kanan dari pohon. L dan R bisa berupa daun maupun
# pohon biner utuh.}
def MakePB(A, L, R):
    return (A, L, R)

# DEFINISI DAN SPESIFIKASI SELEKTOR
# Akar: Pohon Biner tidak kosong -> Elemen
# {Akar(PB) adalah Akar dari PB.
# Jika PB adalah (A, L, R) = Akar(PB) adalah A.}
def Akar(PB):
    return PB[0]

# Left: Pohon Biner -> Pohon Biner
# {Left(PB) adalah pohon Biner yang merupakan anak kiri dari P.
# Jika PB adalah (A, L, R) = Right(PB) adalah L.}
def Left(PB):
    return PB[1]

# Right: Pohon Biner -> Pohon Biner
# {Right(PB) adalah pohon Biner yang merupakan anak kanan dari P.
# Jika PB adalah (A, L, R) = Right(PB) adalah R.}
def Right(PB):
    return PB[2]

# DEFINISI DAN SPESIFIKASI PREDIKAT
# isBTEmpty: Pohon Biner -> boolean
# { isBTEmpty(PB) bernilai True jika PB kosong : () }
def isBTEmpty(PB):
    return PB == ()

# isBTDaun: Pohon Biner -> boolean
# { isBTDaun(PB) bernilai True jika PB hanya terdiri dari Akar. }
def isBTDaun(PB):
    return (not isBTEmpty(PB)) and (isBTEmpty(Left(PB))) and (isBTEmpty(Right(PB)))

# NBElmt: PohonBiner -> integer >= 0
# {NBElmt(PB) memberikan banyaknya node dari pohon P:
# Basis 0: IsTreeNEmpty(()) = 0
# Basis 1: IsOneElmt((A)) = 1
# Rekurens: NBElmt((A, L, R)) = 1 + NBElmt(L) + NBElmt(R) }
def NBElmt(PB):
    # Basis: Jika pohon kosong
    if isBTEmpty(PB):
        return 0
    # Basis 2: Jika merupakan daun
    if isBTDaun(PB):
        return 1
    # Hitung 1 untuk akar, lalu rekursif pada anak kiri dan kanan pohon
    return NBElmt(Left(PB)) + 1 + NBElmt(Right(PB))

# --------------------Tugas Latihan--------------------
# Misal diberikan pohon biner:
P = MakePB(2,
        MakePB(3,
                (),
                MakePB(7,
                        MakePB(6,
                                MakePB(4,
                                        (),
                                        ()
                                ),
                                MakePB(5,
                                        (),
                                        ()
                                )
                            ),
                        ()
                    )
            ),
            MakePB(1,
                    (),
                    MakePB(9,
                            (),
                            MakePB(8,
                                    (),
                                    ()
                            )
                    )
            )
)

P1 = MakePB(1,
            (),
            MakePB(3, (), ()))

# print(P)
# print(NBElmt(P))

# print(PrintPrefixRingkas(P))
# # NBNDaun: Pohon Biner -> integer >= 0
# # {NBNDaun(P) memberikan banyaknya daun dari pohon P:
# # Basis 0: IsTreeNEmpty(()) = 0
# # Basis 1: IsOneElmt((A)) = 1
# # Rekurens: NBNDaun((A, L, R)) = NBNDaun(L) + NBNDaun(R)}
# # Contoh:
# # NBNDaun(P) -> 3
# # {terdapat 3 daun pada pohon biner P}
def NBNDaun(P):
    if isBTDaun(P):
        return 1
    if isBTEmpty(P):
        return 0
    else:
        return NBNDaun(Left(P)) + NBNDaun(Right(P))
# print(NBNDaun(P))
# print(NBNDaun(P1))

# # IsMemberPB: Pohon Biner, elemen -> boolean
# # {IsMemberPB(P, X) mengembalikan True jika X merupakan bagian dari P.}
# # Contoh:
# # IsMemberPB(P, 10) -> False
# # {Tidak ada 10 pada pohon}
# # IsMemberPB(P, 8) -> True
# # {Elemen 8 ada pada pohon}
def IsMemberPB(P,X):
    if isBTEmpty(P):
        return False
    elif Akar(P) == X:
            return True
    elif IsMemberPB(Left(P),X) or IsMemberPB(Right(P),X):
        return True
    else:
        return False
# print(IsMemberPB(P,10))
# print(IsMemberPB(P,8))
# print(IsMemberPB(P,3))

# # IsSkewLeft: Pohon Biner -> boolean
# # {IsSkewLeft(P) mengembalikan True jika P condong kiri.}
def IsSkewLeft(P):
    if isBTEmpty(P):
        return False
    if isBTDaun(P):
        return True
    if not isBTEmpty(Right(P)):
        return False
    else:
        return IsSkewLeft(Left(P))
# print (IsSkewLeft(P1))

# # IsSkewRight: Pohon Biner -> boolean
# # {IsSkewRight(P) mengembalikan True jika P condong kanan.}
def IsSkewRight(P):
    if isBTEmpty(P):
        return False
    if isBTDaun(P):
        return True
    if not isBTEmpty(Left(P)):
        return False
    else:
        return IsSkewLeft(Right(P))
# print(IsSkewRight(P))
# print(IsSkewRight(P1))

# # LevelOfX: Pohon Biner, elemen -> integer
# # {LevelOfX(P, X) mengembalikan level dari elemen X pada P.}
def LevelofX(P,x):
    if isBTEmpty(P):
        return 0
    elif isBTDaun(P):
        return 1
    elif IsMemberPB(Left(P),x):
        return 1 + LevelofX(Left(P),x)
    elif IsMemberPB(Right(P),x):
        return 1 + LevelofX(Right(P),x)
    else:
        return 0
    
print(LevelofX(P,8))

