# type
def make_point (x, y) :
    return [x, y]

def absis (t) :
    return t[0]

def ordinat (t) :
    return t[1]


def make_garis (t1, t2) :
    return [t1, t2]

def titik_awal (g) :
    return g[0]

def titik_akhir (g) :
    return g[1]


def make_segi4 (t1, t2, t3, t4) :
    return [t1, t2, t3, t4]

def titik_a (s4) :
    return s4[0]

def titik_b (s4) :
    return s4[1]

def titik_c (s4) :
    return s4[2]

def titik_d (s4) :
    return s4[3]

#==========================================================
# operasi fungsi lain

# rumus diagonal = rumus panjang garis
def diagonal (g) :
    return ((absis(titik_akhir(g))-absis(titik_awal(g)))**2 + (ordinat(titik_akhir(g))-ordinat(titik_awal(g)))**2) **0.5

def gradien(g):
    if (absis(titik_awal(g)) == absis(titik_akhir(g))) or (ordinat(titik_awal(g)) == ordinat(titik_akhir(g))):
        return 0   
    else :
        return (ordinat(titik_awal(g)) - ordinat(titik_akhir(g))) / (absis(titik_awal(g)) - absis(titik_akhir(g)))

def is_sejajar(g1, g2):
    return gradien(g1) == gradien(g2)


print(diagonal(make_garis(make_point(0, 0), make_point(2, 2))))
print(gradien(make_garis(make_point(0,0), make_point(2, 2))))
print(gradien(make_garis(make_point(2, 4), make_point(2, 2))))
print(gradien(make_garis(make_point(3, 4), make_point(2, 2))))
print(gradien(make_garis(make_point(1, 5), make_point(4, 5))))
print(is_sejajar(make_garis(make_point(0,0), make_point(2, 2)), make_garis(make_point(2, 4), make_point(2, 2))))
print(is_sejajar(make_garis(make_point(0,0), make_point(0, 2)), make_garis(make_point(2, 2), make_point(2, 0))))


#========================================================
# fungsi utama

# sefiempat adalah bangun dengan 4 titik dan 4 garis
def segiempat (s4) :
    if (is_sejajar(make_garis(titik_a(s4), titik_b(s4)), make_garis(titik_c(s4), titik_d(s4))) and 
        is_sejajar(make_garis(titik_a(s4), titik_d(s4)), make_garis(titik_b(s4), titik_c(s4)))) :
        return "persegi"
    else : return "segiempat selain persegi : bisa jadi belahketupat, layang-layang, trapesium, atau segiempat tak beraturan. mff nanti lapraknya kepanjangan dan ga diminta soal juga :D"

# bujur sangkar mewakili persegi dan persegi panjang
def is_bujursangkar (s4) :
    if segiempat(s4) == "persegi" :
        return diagonal(make_garis(titik_a(s4), titik_c(s4))) ==  diagonal(make_garis(titik_b(s4), titik_d(s4))) 
    else: return "False"

def is_jajargenjang (s4) :
    if segiempat(s4) == "persegi" :
        return (diagonal(make_garis(titik_a(s4), titik_c(s4))) >  diagonal(make_garis(titik_b(s4), titik_d(s4))) or 
                diagonal(make_garis(titik_a(s4), titik_c(s4))) <  diagonal(make_garis(titik_b(s4), titik_d(s4))))
    else: return "False"

def luas_bujursangkar(s4) :
    if segiempat(s4) == "persegi" and is_bujursangkar(s4) :
        return diagonal(make_garis(titik_a(s4), titik_b(s4))) * diagonal(make_garis(titik_a(s4), titik_d(s4))) 
    else :
        return "bukan bujursangkar, silahkan input ulang"

#aplikasi
print (segiempat(make_segi4(make_point(0,0), make_point(0,2), make_point(2,2), make_point(2,0)))) #bujursangkar
print (segiempat(make_segi4(make_point(0,0), make_point(0,2), make_point(2,3), make_point(2,1)))) #jajar genjang
print (segiempat(make_segi4(make_point(3,0), make_point(6,7), make_point(3,10), make_point(0,7)))) #layang layang
print (is_bujursangkar(make_segi4(make_point(0,0), make_point(0,2), make_point(2,2), make_point(2,0)))) #bujursangkar
print (is_bujursangkar(make_segi4(make_point(0,0), make_point(0,2), make_point(2,3), make_point(2,1)))) #jajar genjang
print (is_bujursangkar(make_segi4(make_point(3,0), make_point(6,7), make_point(3,10), make_point(0,7)))) #layang layang
print (is_jajargenjang(make_segi4(make_point(0,0), make_point(0,2), make_point(2,2), make_point(2,0)))) #bujursangkar
print (is_jajargenjang(make_segi4(make_point(0,0), make_point(0,2), make_point(2,3), make_point(2,1)))) #jajar genjang
print (is_jajargenjang(make_segi4(make_point(3,0), make_point(6,7), make_point(3,10), make_point(0,7)))) #layang layang

print (luas_bujursangkar(make_segi4(make_point(0,0), make_point(0,2), make_point(2,2), make_point(2,0)))) #bujursangkar
print (luas_bujursangkar(make_segi4(make_point(0,0), make_point(0,2), make_point(2,3), make_point(2,1)))) #jajar genjang
print (luas_bujursangkar(make_segi4(make_point(3,0), make_point(6,7), make_point(3,10), make_point(0,7)))) #layang layang