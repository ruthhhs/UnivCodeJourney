# Nama: Ruth Septriana Sipangkar
# NIM : 24060124120024

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
def IsEmpty(L):
    return L == []

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

# DEFINISI DAN SPESIFIKASI
# GeserList: List of List --> List of List
# GeserList Fungsi merapikan perkakas milik Andi
def GeserList(L):
    if IsEmpty(L) :
        return []
    elif IsAtom(FirstList(L)) :
        return KonsLo(FirstList(L), GeserList(TailList(L)))
    else :
        return KonsLi(GeserList(TailList(L)), FirstList(L))
    
# print(GeserList([4, [4, 6, 1, 1, 2, 4, 4, 5, 2], 2]))

#APLIKASI
import ast
# print(GeserList(ast.literal_eval(input())))