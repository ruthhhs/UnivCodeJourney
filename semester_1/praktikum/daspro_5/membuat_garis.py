# Nama: ruth Septriana sipangkar
# NIM: 24060124120024

# Paste semua Operator tipe bentukan point di bawah ini



#================================


# Konstruktor

# Membuat tipe bentukan garis
def make_point (x, y) :
    return [x, y]

def absis (P) :
    return P[0]

def ordinat (P) :
    return P[1]

def make_garis(P1,P2):
    return [P1, P2]

#=======================
# Selektor
# Mengambil titik awal dari sebuah Garis
def titik_awal(G):
    return G[0]

# Mengambil titik akhir dari sebuah Garis
def titik_akhir(G):
    return G[1]
  
#=======================
# Operator lainnya

# Mengambil nilai gradien dari suatu garis
def gradien(G):
     return (ordinat(titik_awal(G)) - ordinat(titik_akhir(G))) / (absis(titik_awal(G)) - absis(titik_akhir(G)))

# Mencocokan 2 garis sejajar atau tidak
def isSejajar(G1, G2):
    return gradien(G1) == gradien(G2)

#==========================
def panjang_garis (G) :
    return ((absis(titik_akhir(G))-absis(titik_awal(G)))**2 + (ordinat(titik_akhir(G))-ordinat(titik_awal(G)))**2) **0.5


# APLIKASI
print(gradien(make_garis(make_point(1,2), make_point(3,8))))
print(gradien(make_garis(make_point(2, 2), make_point(8, 8))))
print(isSejajar(make_garis(make_point(1,2), make_point(3,8)), (make_point(2, 2), make_point(8, 8))))
print(panjang_garis(make_garis(make_point(2, 2), make_point(8, 8))))
print(panjang_garis(make_garis(make_point(1,2), make_point(3,8))))
