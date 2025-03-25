# Nama: Ruth Septriana Sipangkar
# Nim : 24060124120024

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

#DEFINISI DAN SPESIFIKASI KONSTRUKTOR
def makePN(A,PN):
    return [A,PN]

#DEFINISI DAN SPESIFIKASI SELEKTOR
def Akar(PN):
    return PN[0]

def Anak(PN):
    return PN[1]

#DEFINISI DAN SPESIFIKASI PREDIKAT
def isTreeNEmpty(PN):
    return PN == []

def isOneElmt(PN):
    return (isTreeNEmpty(PN) == False) and (isTreeNEmpty(Anak(PN)) == True)


# def Saudara (x, T) :
#     if isTreeNEmpty(T) :
#         return []
#     elif isTreeNEmpty(Anak(T)) :
#         return []
#     else :
#         if 

T = makePN('Yuki', [makePN('Asuna', []), makePN('Akame', [makePN('Kuro', [makePN('Suzu', [])]), makePN('Frieren', [makePN('Fern', []), makePN('Stark', [])]), makePN('Kana', [])]), makePN('Shiro', [])])
print(FirstList(Anak(T)))

# APLIKASI
# print(eval(input()))