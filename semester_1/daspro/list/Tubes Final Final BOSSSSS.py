# Nama File: KoleksiObjek.py

# Pembuat:  Wahyu Aji Gumelar Tri Nugroho (24060124140134)
#           Ruth Septriana Sipangkar (24060124120024)
#           Rafif Setya Imaduddin (24060124130115)
#           Revalina Salwa Aliya Wicaksono Prabowo (24060124140155)
#           Saburo Rafqi Hidayat (24060124140196)

# Tanggal: 6 November 2024

# DEFINISI DAN SPESIFIKASI TYPE
# type Mhs: <nim: string, nama: string, kelas: character, nilai: list of integer>
#   {type Mhs terdiri atas nim, nama, dan kelas mahasiswa, serta kumpulan nilai kuis
#    yang pernah dikerjakan, dengan maksimal jumlah mengerjakan adalah 10 kali. Nilai
#    mahasiswa memiliki rentang antara 0-100}

# DEFINISI DAN SPESIFIKASI KONSTRUKTOR
# MakeMhs: <string, string, character, list of integer> --> Mhs
#   {MakeMhs(nim, nama, kelas, nilai) membentuk sebuah mahasiswa dengan dengan nim, nama, kelas dan nilai berbentuk list of integer.
#
#    Contoh:
#    MakeMhs(‘234’, ‘Andi’, ‘C’, []) membentuk mahasiswa dengan nim ‘234’, nama ‘Andi’ dari kelas C, dan belum pernah mengerjakan kuis (nilainya berupa list kosong).
#    MakeMhs(‘123’, ‘Caca’, ‘C’, [90,80,100]) membentuk mahasiswa dengan nim ‘123’, nama ‘CC’ dari kelas C, dan telah mengerjakan kuis sebanyak tiga kali dengan nilai masing-masing adalah 90, 80, dan 100}
#
# REALISASI
def MakeMhs(nim,nama,kelas,nilai):
    return [nim,nama,kelas,nilai]

# Konso: elemen, list --> list
#   {Konso(e, L) menambahkan suatu elemen pada awal list}
# REALISASI
def Konso(e, L):
    return [e] + L

# Konsi: list, elemen --> list
#   {Konsi(L, e) menambahkan sebuah elemen pada akhir list}
# REALISASI
def Konsi(L, e):
    return L + [e]

# DEFINISI DAN SPESIFIKASI SELEKTOR
# nim: Mhs --> string
#   {nim(Mhs) mengembalikan nim dari tipe bentukan Mhs}
# REALISASI
def nim(Mhs):
    return Mhs[0]

# nama: Mhs --> string
#   {nama(Mhs) mengembalikan nama dari tipe bentukan Mhs}
# REALISASI
def nama(Mhs):
    return Mhs[1]

# kelas: Mhs --> character
#   {kelas(Mhs) mengembalikan kelas dari tipe bentukan Mhs}
# REALISASI
def kelas(Mhs):
    return Mhs[2]

# nilai: Mhs --> list of integer
#   {nilai(Mhs) mengembalikan List nilai dari tipe bentukan Mhs}
# REALISASI
def nilai(Mhs):
    return Mhs[3]

# FirstElmnt: list --> elemen
#   {FirstElmnt(L) memberikan elemen pertama dari suatu list}
# REALISASI
def FirstElmnt(L):
    return L[0]

# LastElmnt: list --> elemen
#   {LastElmnt(L) memberikan elemen terakhir dari suatu list}
# REALISASI
def LastElmnt(L):
    return L[-1]

# Head: list --> list
#   {Head(L) suatu list dengan menghilangkan elemen terkahirnya}
# REALISASI
def Head(L):
    return L[:-1]

# Tail: list --> list
#   {Tail(L) suatu list dengan menghilangkan elemen pertamanya}
# REALISASI
def Tail(L):
    return L[1:]

# DEFINISI DAN SPESIFIKASI FUNGSI ANTARA
# AvgNilai: Mhs --> real
#   {AvgNilai(Mhs) mengembalikan nilai rata-rata dari tipe Mhs}

# DEFINISI DAN SPESIFIKASI PREDIKAT
# IsEmpty: list --> boolean
#   {IsEmpty(L) bernilai benar jika list kosong}

# IsOneElmnt: list --> boolean
#   {IsOneElmnt(L) benar jika list L hanya mempunyai satu elemen}

# DEFINISI DAN SPESIFIKASI OPERATOR
# SumElmnt: list of integer --> integer
#   {SumElmnt(L) menghasilkan jumlahan dari setiap elemen di list L}

# NbElmnt: list --> integer
#   {NbElmnt(L) menghasilkan banyaknya elemen list, nol jika kosong}

# MaxElmnt: list of integer --> integer
#   {MaxElmnt(L) mengembalikan elemen maksimumm dari list L}

# SetMhs: Mhs, list --> set
#   {SetMhs(Mhs,L) membentuk sebuah set dari Mhs. Tidak dapat menambahkan pada set jika nim yang
#    dimasukkan dari Mhs sudah ada di set L. Dapat menambahkan jika nimnya belum ada di set L}

# Mhs_Lulus: set of Mhs --> set
#   {Mhs_Lulus(MhsS) mengembalikan nama-nama dari Mhs yang lulus dengan kriteria rata-rata nilai di atas atau sama dengan 70}

# Mhs_NilaiKosong: set of Mhs, character --> set
#   {Mhs_NilaiKosong(MhsS, SelectedClass) mengembalikan nama-nama dari Mhs yang tidak memiliki nilai sama sekali di kelas tertentu}

# NilaiTertinggi: set of Mhs --> real
#   {NilaiTertinggi(MhsS) mengembalikan rata-rata nilai tertinggi dari seluruh nilai Mhs}

# NilaiTertinggi_Kelas: set of Mhs, character --> real
#   {NilaiTertinggi_Kelas(MhsS, SelectedClass) mengembalikan rata-rata nilai tertinggi dari kelas yang sudah ditentukan dari SelectedClass}

# NbMhs_SkipKuis: set of Mhs --> integer
#   {NbMhs_SkipKuis(MhsS) menghitung jumlah Mhs yang tidak mengerjakan kuis}

# NbMhs_Lulus: set of Mhs --> integer
#   {NbMhs_Lulus(MhsS) mengembalikan jumlah Mhs yang lulus sesuai kriteria}

# REALISASI
def IsEmpty(L):
    return L == []

def IsOneElmnt(L):
    return not IsEmpty(L) and IsEmpty(Tail(L))

def AvgNilai(Mhs):
    if IsEmpty(nilai(Mhs)):
        return 0
    else:
        return SumElmnt(nilai(Mhs)) / NbElmnt(nilai(Mhs))

def SumElmnt(L):
    if IsEmpty(L):
        return 0
    else:
        return FirstElmnt(L) + SumElmnt(Tail(L))

def NbElmnt(L):
    if IsEmpty(L):
        return 0
    else:
        return 1 + NbElmnt(Tail(L))

def MaxElmnt(L):
    if IsEmpty(L):
        return []
    elif IsOneElmnt(L):
        return FirstElmnt(L)
    else:
        if FirstElmnt(L) > MaxElmnt(Tail(L)):
            return FirstElmnt(L)
        else:
            return MaxElmnt(Tail(L))

def SetMhs(Mhs, L):
    if L == []:
        return Konso(Mhs, L)
    elif nim(Mhs) == nim(FirstElmnt(L)):
        return L
    else:
        return Konso(FirstElmnt(L), SetMhs(Mhs, Tail(L)))

def Mhs_Lulus(MhsS):
    if IsEmpty(MhsS):
        return []
    else:
        if AvgNilai(FirstElmnt(MhsS)) >= 70:
            return Konso(nama(FirstElmnt(MhsS)), Mhs_Lulus(Tail(MhsS)))
        else:
            return Mhs_Lulus(Tail(MhsS))

def Mhs_NilaiKosong(MhsS, SelectedClass):
    if IsEmpty(MhsS):
        return []
    else:
        if kelas(FirstElmnt(MhsS)) == SelectedClass and IsEmpty(nilai(FirstElmnt(MhsS))):
            return Konso(nama(FirstElmnt(MhsS)), Mhs_NilaiKosong(Tail(MhsS), SelectedClass))
        else:
            return Mhs_NilaiKosong(Tail(MhsS), SelectedClass)

def NilaiTertinggi(MhsS):
    if IsEmpty(MhsS):
        return []
    elif IsOneElmnt(MhsS):
        return AvgNilai(FirstElmnt(MhsS))
    else:
        if AvgNilai(FirstElmnt(MhsS)) >= AvgNilai(FirstElmnt(Tail(MhsS))):
            return NilaiTertinggi(Konso(FirstElmnt(MhsS), Tail(Tail(MhsS))))
        else:
            return NilaiTertinggi(Tail(MhsS))
        
def NilaiTertinggi_Kelas(MhsS, SelectedClass):
    if IsEmpty(MhsS):
        return []
    elif IsOneElmnt(MhsS):
        if kelas(FirstElmnt(MhsS)) == SelectedClass:
            return AvgNilai(FirstElmnt(MhsS))
        else:
            return 0
    else:
        if kelas(FirstElmnt(MhsS)) == SelectedClass:
            if AvgNilai(FirstElmnt(MhsS)) >= AvgNilai(FirstElmnt(Tail(MhsS))):
                return AvgNilai(FirstElmnt(MhsS))
            else:
                return NilaiTertinggi_Kelas(Tail(MhsS), SelectedClass)
        else:
            return NilaiTertinggi_Kelas(Tail(MhsS), SelectedClass)
    
def NbMhs_SkipKuis(MhsS):
    if IsEmpty(MhsS):
        return 0
    else: 
        if NbElmnt(nilai(FirstElmnt(MhsS))) != 0:
            return NbMhs_SkipKuis(Tail(MhsS))
        else: 
            return 1 + NbMhs_SkipKuis(Tail(MhsS))

def NbMhs_Lulus(MhsS):
    if IsEmpty(MhsS):
        return 0
    else: 
        if AvgNilai(FirstElmnt(MhsS)) >= 70: 
            return 1 + NbMhs_Lulus(Tail(((MhsS))))
        else: 
            return NbMhs_Lulus(Tail(MhsS))

# APLIKASI
print(NilaiTertinggi_Kelas([
    MakeMhs("Ali", "123", "B", [100]),
    MakeMhs("Budi", "456", "A", [60, 65, 70]),
    MakeMhs("Cici", "789", "A", [90, 85, 88]),
    MakeMhs("Dina", "012", "A", [95, 90, 92]),
    MakeMhs("Eka", "234", "E", [55, 60, 58]),
    MakeMhs("Fajar", "567", "A", [78, 82, 80]),
    MakeMhs("Gina", "890", "A", [85, 87, 90]),
    MakeMhs("Hadi", "345", "B", [95, 94, 96])
], "A"))

print(NilaiTertinggi_Kelas([
    MakeMhs("Ali", "123", "B", [100]),
    MakeMhs("Budi", "456", "A", [60, 65, 70]),
    MakeMhs("Cici", "789", "D", [90, 85, 88]),
    MakeMhs("Dina", "012", "A", [95, 90, 92]),
    MakeMhs("Eka", "234", "C", [55, 60, 58]),
    MakeMhs("Fajar", "567", "A", [78, 82, 80]),
    MakeMhs("Gina", "890", "A", [85, 87, 90]),
    MakeMhs("Hadi", "345", "B", [95, 94, 96])
], "A"))

print(
    SetMhs(
        MakeMhs("Ali", "123", "A", [80, 75, 90]),
        [MakeMhs("Budi", "456", "B", [60, 65, 70]), 
        MakeMhs("Cici", "123", "B", [60, 65, 70]),
        MakeMhs("Dina", "789", "C", [90, 85, 88])
]))

print(NilaiTertinggi([
    MakeMhs("Ali", "123", "A", [80, 75, 90]),
    MakeMhs("Budi", "456", "A", [60, 65, 70]),
    MakeMhs("Cici", "789", "B", [90, 85, 88]),
    MakeMhs("Dina", "012", "B", [95, 90, 92]),
    MakeMhs("Eka", "234", "C", [55, 60, 58]),
    MakeMhs("Fajar", "567", "C", [78, 82, 80]),
    MakeMhs("Gina", "890", "D", [85, 87, 90]),
    MakeMhs("Hadi", "345", "D", [95, 94, 96])
]))


print(Mhs_Lulus([
    MakeMhs("Ali", "123", "A", [80, 75, 90]),
    MakeMhs("Budi", "456", "B", [60, 65, 70]),
    MakeMhs("Dina", "789", "C", [90, 85, 88])
]))

print(Mhs_NilaiKosong([
    MakeMhs("Ali", "123", "A", []),
    MakeMhs("Budi", "456", "A", [60, 65, 70]),
    MakeMhs("Cici", "789", "B", []),
    MakeMhs("Dina", "012", "A", [])
], "A"))

print(
    NbMhs_Lulus([
    MakeMhs("Ali", "123", "A", [80, 75, 90]),
    MakeMhs("Budi", "456", "B", [60, 65, 70]),
    MakeMhs("Dina", "789", "C", [90, 85, 88])
]))

print(
    NbMhs_SkipKuis([
    MakeMhs("Ali", "123", "A", [80, 75, 90]),
    MakeMhs("Budi", "456", "B", [90]),
    MakeMhs("Dina", "789", "C", [90, 85, 88])
]))