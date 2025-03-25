# Nama File: garis.py
# Pembuat: Ruth Septriana Sipangkar (24060124120024)
# Tanggal: 21 Oktober 2024
# Deskripsi: Bentukan titik dan garis, serta operasi pada garis

#========================================================================
# TYPE

# point : < x: integer, y: integeer>
#   {point adalah tipe bentukan titik yang berupa tuple dengan 2 komponen, yaitu absis x dan ordinat y}

# garis : < p1: point, p2: point>
#   {garis adalah tipe bentukan garis yang berupa tuple dengan 2 komponen, yaitu titik awal p1 dan titik akhir p2}

#==========================================================================
# KONSTRUKTOR

# make_point : 2 integer ---> point
#   {make_point (x, y) adalah fungsi membuat tipe bentukan titik dengan absis x dan ordinat y}
def make_point (x, y) :
    return [x, y]

# make_garis : 2 point ---> garis
#   {make_garis (P1, P2) adalah fungsi membuat tipe bentukan garis dengan titik awal P1 dan titik akhir P2}
def make_garis(P1,P2):
    return [P1, P2]

#==========================================================================
# SELEKTOR

# absis : point ---> integer
#   {absis (P) adalah fungsi get absis dari suatu titik P}
def absis (P) :
    return P[0]

# ordinat : point ---> integer
#   {ordinat (P) adalah fungsi get ordinat dari suatu titik P}
def ordinat (P) :
    return P[1]


# titik_awal : garis ---> point
#   {titik_awal (P) adalah fungsi get titi kawal dari suatu garis G}
def titik_awal(G):
    return G[0]

# titik_akhir : garis ---> point
#   {titik_akhir (P) adalah fungsi get titik akhir dari suatu garis G}
def titik_akhir(G):
    return G[1]

#========================================================
# OPERATOR

# gradien : garis ---> real
#   {gradien (G) adalah fungsi untuk menghitung gradien suatu garis dengan rumus m = (y2-y1)/(x2-x1)}
def gradien(G):
     if (absis(titik_awal(G)) == absis(titik_akhir(G))) or (ordinat(titik_awal(G)) == ordinat(titik_akhir(G))):
         return 0.0
     else :
         return (ordinat(titik_akhir(G)) - ordinat(titik_awal(G))) / (absis(titik_akhir(G)) - absis(titik_awal(G)))

# panjang_garis : garis ---> real
#   {panjang_garis (G) adalah fungsi untuk menghitung panjang suatu garis dengan rumus akar((x1-x2)^2 + (y2-y1)^2)}
def panjang_garis (G) :
    return ((absis(titik_awal(G))-absis(titik_akhir(G)))**2 + (ordinat(titik_akhir(G))-ordinat(titik_awal(G)))**2) **0.5

#===========================================================
# PREDIKAT

# is_sejajar : 2 garis ---> boolean
#   {is_sejajar (G1, G2) adalah fungsi untuk menentukan apakah dua buah garis sejajar atau tidak}
def isSejajar(G1, G2):
    if (((absis(titik_awal(G1)) == absis(titik_akhir(G1))) and (ordinat(titik_awal(G2)) == ordinat(titik_akhir(G2)))) or 
        ((absis(titik_awal(G2)) == absis(titik_akhir(G2))) and (ordinat(titik_awal(G1)) == ordinat(titik_akhir(G1))))) :
         return False
    else :
        return gradien(G1) == gradien(G2)

# is_tegaklurus : 2 garis ---> boolean
#   {is_tegaklurus (G1, G2) adalah fungsi untuk menentukan apakah dua buah garis saling tegak lurus atau tidak}
def is_tegaklurus (G1, G2) :
    if (((absis(titik_awal(G1)) == absis(titik_akhir(G1))) and (ordinat(titik_awal(G2)) == ordinat(titik_akhir(G2)))) or 
        ((absis(titik_awal(G2)) == absis(titik_akhir(G2))) and (ordinat(titik_awal(G1)) == ordinat(titik_akhir(G1))))) :
         return True
    else :
        return gradien(G1)*gradien(G2) == -1

#===================================================================
# Aplikasi

print(gradien(make_garis(make_point(1,2), make_point(3,8))))            # 3.0
print(gradien(make_garis(make_point(2, 2), make_point(8, 8))))          # 1.0
print(panjang_garis(make_garis(make_point(2, 2), make_point(8, 8))))        # 8.48528137423857
print(panjang_garis(make_garis(make_point(1,2), make_point(3,8))))          # 6.324555320336759

print(isSejajar(make_garis(make_point(1,2), make_point(3,8)), (make_point(2, 2), make_point(8, 8))))        # False
print(is_tegaklurus(make_garis(make_point(1,2), make_point(3,8)), (make_point(2, 2), make_point(8, 8))))        # False

print(isSejajar(make_garis(make_point(2, 2), make_point(8, 2)), (make_point(2, 2), make_point(2, 8))))           # False
print(is_tegaklurus(make_garis(make_point(2, 2), make_point(8, 2)), (make_point(2, 2), make_point(2, 8))))       # True

print(gradien(make_garis(make_point(2, 2), make_point(8, 2))))              # 0.0
print(gradien(make_garis(make_point(2, 2), make_point(2, 8))))              # 0.0