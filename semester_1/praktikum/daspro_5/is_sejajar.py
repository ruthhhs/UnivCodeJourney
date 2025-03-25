#(P) mewakili point
def make_point (x, y) :
    return [x, y]

def absis (P) :
    return P[0]

def ordinat (P) :
    return P[1]

#(L) mewakili line
def make_garis (p1, p2) :
    return [p1, p2]

def titik_a (L) :
    return L[0]

def titik_b (L) :
    return L[1]

def gradient (L) :
    return abs(ordinat(titik_a(L)) - ordinat(titik_b(L))) / abs(absis(titik_a(L)) - absis(titik_b(L)))

def is_sejajar (l1, l2) :
    return gradient(l1) == gradient(l2)

print (gradient(make_garis(make_point(1, 2), make_point(3, 4))))
print (gradient(make_garis(make_point(2, 2), make_point(4, 4))))
print (is_sejajar(make_garis(make_point(1, 2), make_point(3, 4)), (make_garis(make_point(2, 2), make_point(4, 4)))))