# Nama File: pecahan_campur.py
# Pembuat: Ruth Septriana Sipangkar (24060124120024)
# Tanggal: 21 Oktober 2024
# Deskripsi: Bentukan pecahan dan pecahan campuran, beserta operasi pada pecahan campuran

#====================================================================================
# TYPE

# pecahanc : < bl: integer, n: integer, d: iinteger >0 >
#   {pecahanc adalah tipe bentukan pecahan campuran dengan tuple berisi 3 komponen yaitu bilangan bulat bil, n pembilang, dan d penyebut}

# pecahan : < pb: integer, py: iinteger >0 >
#   {pecahan adalah tipe bentukan pecahan biasa dengan tuple berisi 2 komponen yaitu pb pembilang dan py penyebut}


#====================================================================================
# KONSTRUKTOR

# make_pecahanc : 2 integer, integer>0 ---> pecahanc
#   {make_pecahanc (bil, n, d) adalah fungsi untuk memmbuat pecahan campuran (P) dengan bil bilangan, n pembilang, dan d penyebut
#    dengan n harus lebih kecil d}
def make_pecahanc (bil, n, d) :
    return [bil, n, d]

# make_pecahan : integer, integer>0 ---> pecahan
#   {make_pecahan (n, d) adalah fungsi untuk membuat pecahan biasa dengan n pembilang dan d penyebut dengan n harus lebih kecil d}
def make_pecahan(n, d) :
    return [n, d]

#===================================================================================
# SELEKTOR

# bilangan : pecahanc ---> integer
#   {bilangan (P) adalah fungsi get bilangan dari sebuah pecahan campuran}
def bilangan (p) :
    return p[0]

# pembilang : pecahanc ---> integer
#   {pembilang (P) adalah fungsi get pembilang dari sebuah pecahan campuran}
def pembilang (p) :
    return p[1]

# penyebut : pecahanc ---> integer
#   {penyebut (P) adalah fungsi get penyebut dari sebuah pecahan campuran}
def penyebut (p) :
    return p[2]

#==================================================================================
# OPERATOR

# konv_pembilang : pecahanc ---> integer
#   {konv_pembilang(P) adalah fungsi membuat pembilang dalam bentuk pecahan biasa
#    dari pecahan campurang dengan 2 kondisi dimana bilangan lebih dari 0 atau kurang dari 0}
def konv_pembilang(P) :
    if bilangan(P) >= 0 :
        return penyebut(P)*bilangan(P) + pembilang(P)
    else :
        return penyebut(P)*bilangan(P) - pembilang(P)


# konv_pecahan : pecahanc ---> pecahan
#   {konv_pecahan(P) adalah fungsi mengubah pecahan campuran ke pecahan biasa}
def konv_pecahan(P) :
        return make_pecahan(konv_pembilang(P), penyebut(P))


# konv_real : pecahanc ---> real
#   {konv_real (P) adalah fungsi mengubah pecahan campuran ke bilangan desimal}
def konv_real(P) :
    return konv_pembilang(P)/penyebut(P)

# addP : 2 pecahanc ---> pecahanc
#   {addP (P) adalah fungsi untuk menjumlahkan dua tipe bentukan pecahan campuran dan menghasilkan keluaran pecahan campuran}
def addP (P1, P2) :
    if (((konv_pembilang(P1)*penyebut(P2)) + (konv_pembilang(P2)*penyebut(P1)))) <0 :
        if (abs(((konv_pembilang(P1)*penyebut(P2)) + (konv_pembilang(P2)*penyebut(P1)))) // (penyebut(P1)*penyebut(P2))) == 0:
            return make_pecahanc (
                0, #bilangan
                - (abs((konv_pembilang(P1)*penyebut(P2)) + (konv_pembilang(P2)*penyebut(P1))) % (penyebut(P1)*penyebut(P2))), #pembilang
                penyebut(P1)*penyebut(P2) #penyebut
            )
        else :
            return make_pecahanc (
                - (abs(((konv_pembilang(P1)*penyebut(P2)) + (konv_pembilang(P2)*penyebut(P1)))) // (penyebut(P1)*penyebut(P2))), #bilangan
                abs((konv_pembilang(P1)*penyebut(P2)) + (konv_pembilang(P2)*penyebut(P1))) % (penyebut(P1)*penyebut(P2)), #pembilang
                penyebut(P1)*penyebut(P2) #penyebut
            )
    else :
        return make_pecahanc (
            ((konv_pembilang(P1)*penyebut(P2)) + (konv_pembilang(P2)*penyebut(P1))) // (penyebut(P1)*penyebut(P2)), #bilangan
            ((konv_pembilang(P1)*penyebut(P2)) + (konv_pembilang(P2)*penyebut(P1))) % (penyebut(P1)*penyebut(P2)), #pembilang
            penyebut(P1)*penyebut(P2) #penyebut
        )

# subP : 2 pecahanc ---> pecahanc
#   {subP (P) adalah fungsi untuk mengurangkan dua tipe bentukan pecahan campuran dan menghasilkan keluaran pecahan campuran}
def subP (P1, P2) :
    if (((konv_pembilang(P1)*penyebut(P2)) - (konv_pembilang(P2)*penyebut(P1)))) <0 :
        if (abs(((konv_pembilang(P1)*penyebut(P2)) - (konv_pembilang(P2)*penyebut(P1)))) // (penyebut(P1)*penyebut(P2))) == 0:
            return make_pecahanc (
                0, #bilangan
                - (abs((konv_pembilang(P1)*penyebut(P2)) - (konv_pembilang(P2)*penyebut(P1))) % (penyebut(P1)*penyebut(P2))), #pembilang
                penyebut(P1)*penyebut(P2) #penyebut
            )
        else :
            return make_pecahanc (
                - (abs(((konv_pembilang(P1)*penyebut(P2)) - (konv_pembilang(P2)*penyebut(P1)))) // (penyebut(P1)*penyebut(P2))), #bilangan
                abs((konv_pembilang(P1)*penyebut(P2)) - (konv_pembilang(P2)*penyebut(P1))) % (penyebut(P1)*penyebut(P2)), #pembilang
                penyebut(P1)*penyebut(P2) #penyebut
            )
    else :
        return make_pecahanc (
            (((konv_pembilang(P1)*penyebut(P2)) - (konv_pembilang(P2)*penyebut(P1)))) // (penyebut(P1)*penyebut(P2)), #bilangan
            ((konv_pembilang(P1)*penyebut(P2)) - (konv_pembilang(P2)*penyebut(P1))) % (penyebut(P1)*penyebut(P2)), #pembilang
            penyebut(P1)*penyebut(P2) #penyebut
        )

# mulP : 2 pecahanc ---> pecahanc
#   {mulP (P) adalah fungsi untuk mengalikan dua tipe bentukan pecahan campuran dan menghasilkan keluaran pecahan campuran}
def mulP (P1, P2) :
    if (konv_pembilang(P1) * konv_pembilang(P2)) <0 :
        if (abs(konv_pembilang(P1) * konv_pembilang(P2)) // (penyebut(P1)*penyebut(P2))) == 0 :
            return make_pecahanc (
                0, #bilangan
                - (abs(konv_pembilang(P1) * konv_pembilang(P2)) % (penyebut(P1)*penyebut(P2))), #pembilang
                penyebut(P1)*penyebut(P2) #penyebut
            )
        else :
            return make_pecahanc (
                - (abs(konv_pembilang(P1) * konv_pembilang(P2)) // (penyebut(P1)*penyebut(P2))), #bilangan
                abs(konv_pembilang(P1) * konv_pembilang(P2)) % (penyebut(P1)*penyebut(P2)), #pembilang
                penyebut(P1)*penyebut(P2) #penyebut
            )
    else :
        return make_pecahanc (
            (konv_pembilang(P1) * konv_pembilang(P2)) // (penyebut(P1)*penyebut(P2)), #bilangan
            (konv_pembilang(P1) * konv_pembilang(P2)) % (penyebut(P1)*penyebut(P2)), #pembilang
            penyebut(P1)*penyebut(P2) #penyebut
        )


# divP : 2 pecahanc ---> pecahanc
#   {divP (P) adalah fungsi untuk membagikan dua tipe bentukan pecahan campuran dan menghasilkan keluaran pecahan campuran}
def divP (P1, P2) :
    if (konv_pembilang(P1) * penyebut(P2)) <0 or (konv_pembilang(P2) * penyebut(P1)) <0:
        if (abs(konv_pembilang(P1) * penyebut(P2)) // abs(konv_pembilang(P2) * penyebut(P1))) == 0 :
            return make_pecahanc (
            0, #bilangan
            - (abs(konv_pembilang(P1) * penyebut(P2)) % abs(konv_pembilang(P2) * penyebut(P1))), #pembilang
            abs(konv_pembilang(P2) * penyebut(P1)) #penyebut
        )
        else :
            return make_pecahanc (
                - (abs(konv_pembilang(P1) * penyebut(P2)) // abs(konv_pembilang(P2) * penyebut(P1))), #bilangan
                abs(konv_pembilang(P1) * penyebut(P2)) % abs(konv_pembilang(P2) * penyebut(P1)), #pembilang
                abs(konv_pembilang(P2) * penyebut(P1)) #penyebut
            )
    else :
        return make_pecahanc (
            (konv_pembilang(P1) * penyebut(P2)) // (konv_pembilang(P2) * penyebut(P1)), #bilangan
            (konv_pembilang(P1) * penyebut(P2)) % (konv_pembilang(P2) * penyebut(P1)), #pembilang
            abs(konv_pembilang(P2) * penyebut(P1)) #penyebut
        )


#======================================================================================
# PREDIKAT

# is_equivP : 2 pecahanc ---> boolean
#   {is_equivP (P) adalah fungsi untuk menentukan apakah pecahan campuran 1 sama dengan pecahan campuran 2}
def is_eqivP (P1, P2) :
    return konv_real(P1) == konv_real(P2)

# is_lessP : 2 pecahanc ---> boolean
#   {is_lessP (P) adalah fungsi untuk menentukan apakah pecahan campuran 1 kurang dari pecahan campuran 2}
def is_lessP (P1, P2) :
    return konv_real(P1) < konv_real(P2)

# is_greaterP : 2 pecahanc ---> boolean
#   {is_greaterP (P) adalah fungsi untuk menentukan apakah pecahan campuran 1 lebih dari pecahan campuran 2}
def is_greaterP (P1, P2) :
    return konv_real(P1) > konv_real(P2)


#======================================================================================
# APLIKASI

print(konv_pecahan(make_pecahanc(1, 2, 3)))                        # output [5, 3]
print(konv_pecahan(make_pecahanc(-1, 2, 4)))                       # output [-6, 4]
print(konv_real(make_pecahanc(1, 2, 3)))                # output 1.6666666666666667
print(konv_real(make_pecahanc(-1, 2, 4)))               # output -1.5
print(addP(make_pecahanc(1, 2, 3), make_pecahanc(-1, 2, 4)))            # output [0, 2, 12]
print(subP(make_pecahanc(1, 2, 3), make_pecahanc(-1, 2, 4)))            # output [3, 2, 12]
print(mulP(make_pecahanc(1, 2, 3), make_pecahanc(-1, 2, 4)))            # output [-2, 6, 12]
print(divP(make_pecahanc(1, 2, 3), make_pecahanc(-1, 2, 4)))            # output [-1, 2, 18]

print(" ")

print(konv_pecahan(make_pecahanc(3, 1, 3)))                        # output [10, 3]
print(konv_pecahan(make_pecahanc(-3, 2, 4)))                       # output [-14, 4]
print(konv_real(make_pecahanc(3, 1, 3)))                    # output 3.3333333333333335
print(konv_real(make_pecahanc(-3, 2, 4)))                   # output -3.5
print(addP(make_pecahanc(3, 1, 3), make_pecahanc(-3, 2, 4)))            # output [0, -2, 12]
print(subP(make_pecahanc(3, 1, 3), make_pecahanc(-3, 2, 4)))            # output [6, 10, 12]
print(mulP(make_pecahanc(3, 1, 3), make_pecahanc(-3, 2, 4)))            # output [-11, 8, 12]
print(divP(make_pecahanc(3, 1, 3), make_pecahanc(-3, 2, 4)))            # output [0, -40, 42]

print(" ")

print(is_eqivP(make_pecahanc(3, 1, 3), make_pecahanc(-3, 2, 4)))        # output False
print(is_lessP(make_pecahanc(3, 1, 3), make_pecahanc(-3, 2, 4)))        # output False
print(is_greaterP(make_pecahanc(3, 1, 3), make_pecahanc(-3, 2, 4)))        # output True
