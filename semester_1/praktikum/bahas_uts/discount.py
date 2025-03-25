def make_date (d, m, y) :
    return [d, m, y]

def day (D) :
    return D[0]

def month (D) :
    return D[1]

def year (D) :
    return D[2]

def make_discount(kategori, disc):
    return [kategori, disc]
 
# dengan d1 tanggal berangkat dan d2 tanggal lahir
def disc(d1, d2) :
    if (year(d1))-(year(d2)) <= 0 : return "belum lahir kocak, coba bagusin inputan"
    elif (year(d1))-(year(d2)) <= 2 :
        if (month(d1))-(month(d2)) <= 0 :
            if (day(d1))-(day(d2)) <= 0 :
                return make_discount ("invant", 75)
            else : return make_discount ("child", 25)
        else : return make_discount ("child", 25)
    elif (year(d1))-(year(d2)) <= 12 :
        if (month(d1))-(month(d2)) <= 0 :
            if (day(d1))-(day(d2)) <= 0 :
                return make_discount ("child", 25)
            else : return make_discount ("adult", 0)
        else : return make_discount ("adult", 0)
    else : return make_discount ("adult", 0)

print (disc(make_date(23, 2, 2024), make_date(25, 2, 2024)))
print (disc(make_date(23, 2, 2024), make_date(25, 2, 2022)))
print (disc(make_date(23, 2, 2024), make_date(25, 2, 2014)))
print (disc(make_date(23, 2, 2024), make_date(25, 2, 2004)))