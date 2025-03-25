def cek_segitiga(a, b, c) :
    if a + b > c and a + c > b and b + c > a :
        if a == b == c :
            return "Sama Sisi"
        elif a == b > c or b == c > a or a == c > b :
            return "Sama Kaki"
        elif a != b or b != c or c != a :
            return "Sembarang"
    else :
        return "Tidak dapat membentuk segitiga"

print (cek_segitiga(1, 1, 1))
print (cek_segitiga(2, 1, 2))
print (cek_segitiga(5, 2, 6))
print (cek_segitiga(3, 4, 5))
print (cek_segitiga(3, 4, 100))