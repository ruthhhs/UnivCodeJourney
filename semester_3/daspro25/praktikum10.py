from praktikum9 import *

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
        PrintTreeNAryHelp(firstList(Anak(T)), tailList(Anak(T)), indent + '\t')
    if not isEmpty(sisa):
        PrintTreeNAryHelp(firstList(sisa), tailList(sisa), indent)

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
    return NbNElmt(firstList(PN)) + NbNElmtChild(tailList(PN))

#APLIKASI
T = makePN('A',[makePN('b',[makePN('c',[makePN('g',[])])]), makePN('d',[makePN('e',[])]), makePN('f',[])])
PrintTreeNAry(T)
print(isTreeNEmpty(T))
print(isOneElmt(T))
print(NbNElmt(T))
T1 = makePN("Ridho",[makePN("Silvani",[makePN("Nuha",[]), makePN("Syahrafi",[makePN("Syair", [])]),
makePN("Umar",[])]), makePN("Rendi",[makePN("Fikhrul",[])]), makePN("Ruth",[makePN("Aji",[])]),
 makePN("Eko",[makePN("Raffi",[])])])
PrintTreeNAry(T1)
