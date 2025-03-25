#fungsi date (D) dengan d tanggal, m bulan, y tahun
def make_date (d, m, y) :
    return [d, m, y]

def day (D) :
    return D[0]

def month (D) :
    return D[1]

def year (D) :
    return D[2]

def is_kabisat(D) :
    return (year(D) %4==0) and (year(D) %100!=0) or (year(D) %400==0)

def dpm(D) :
    if month(D)==1 : return 1
    elif month(D)==2 : return 32
    elif month(D)==3 : return 60
    elif month(D)==4 : return 91
    elif month(D)==5 : return 121
    elif month(D)==6 : return 152
    elif month(D)==7 : return 182
    elif month(D)==8 : return 213
    elif month(D)==9 : return 243
    elif month(D)==10 : return 274
    elif month(D)==11 : return 304
    elif month(D)==12 : return 335

def hari_ke(D) :
    return dpm(D) + day(D) - 1 + (1 if month(D) > 2 and is_kabisat(D) else  0)

print (hari_ke(make_date(26, 9, 2006)))

