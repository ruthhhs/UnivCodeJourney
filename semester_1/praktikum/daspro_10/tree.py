#Nama File: list.py
#Deskripsi: berisi type dan operasi list of list
#Pembuat: Ruth Septriana Sipangkar 24060124120024
#Tanggal: 19/11/2024

from ListOfList import *

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

def PrintTreeNAryHelp(T, sisa, indent):
    print(indent + str(Akar(T)))
    if not isEmpty(Anak(T)):
        PrintTreeNAryHelp(FirstList(Anak(T)), TailList(Anak(T)), indent + '\t')
    if not isEmpty(sisa):
        PrintTreeNAryHelp(FirstList(sisa), TailList(sisa), indent)

def PrintTreeNAry(T):
    PrintTreeNAryHelp(T, [], '')

def NbNElmt(PN):
    # Basis: Jika pohon kosong
    if isTreeNEmpty(PN):
        return 0
    
    # Jika hanya ada satu elemen (Akar saja)
    if isOneElmt(PN):
        return 1
    
    # Hitung 1 untuk Akar, dan rekursif pada setiap Anak pohon
    # Tanpa menggunakan loop, kita memanggil fungsi untuk setiap Anak secara rekursif
    # Pertama pada Anak pertama
    return 1 + NbNElmtChild(Anak(PN))

# Fungsi tambahan untuk menghitung jumlah elemen pada sisa Anak-Anak
def NbNElmtChild(PN):
    # Basis: Jika tidak ada Anak
    if isTreeNEmpty(PN):
        return 0
    
    # Jika ada Anak, rekursif pada Anak pertama dan sisa Anak-Anak
    return NbNElmt(FirstList(PN)) + NbNElmtChild(TailList(PN))

def NbNDaun(PN):
    # Basis: Jika pohon kosong
    if isTreeNEmpty(PN):
        return 0
    
    # Jika pohon adalah daun (Anak kosong)
    if isOneElmt(PN) and isTreeNEmpty(Anak(PN)):
        return 1
    
    # Rekursi pada Akar dan Anak-Anak
    return NbNDaunChild(Anak(PN))

# Fungsi tambahan untuk menghitung jumlah daun pada sisa Anak-Anak
def NbNDaunChild(PN):
    # Basis: Jika tidak ada Anak
    if isTreeNEmpty(PN):
        return 0
    
    # Jika ada Anak, rekursif pada Anak pertama dan sisa Anak-Anak
    return NbNDaun(FirstList(PN)) + NbNDaunChild(TailList(PN))

#APLIKASI
# T = makePN(2,[])
# PrintTreeNAry(makePN(2,[]))
# print(isTreeNEmpty(T))
# print(isOneElmt(T))
# T2 = makePN('A',[makePN('B',[makePN('C',[])]), makePN('D',[])])
# PrintTreeNAry(T2)
# print(NbNElmt(T2))
# print(NbNDaun(T2))
T3 = makePN("Silvani",
            [makePN("Nuha",[]), 
             makePN("Rendi",[makePN("Fikhrul",[makePN("Syahrafi",[])])]),
             makePN("Ruth",[makePN("Aji",[])]),
             makePN("Eko",[makePN("Raffi",[])])])
PrintTreeNAry(T3)
print(NbNDaun(T3))