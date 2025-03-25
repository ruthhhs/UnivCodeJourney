#dpm : jumlah hari tanggal 1 di bulan x [1..12]
def dpm(x) :
    if x==1 : return 1
    elif x==2 : return 32
    elif x==3 : return 60
    elif x==4 : return 91
    elif x==5 : return 121
    elif x==6 : return 152
    elif x==7 : return 182
    elif x==8 : return 213
    elif x==9 : return 243
    elif x==10 : return 274
    elif x==11 : return 304
    elif x==12 : return 335

#is_kabisat : mengetahui apakah tahun x adalah kabisat atau bukan
#int-->boolean
def is_kabisat(x) :
    return (x %4==0) and (x %100!=0) or (x %400==0)

#hari_ke : menghitung hari suatu tanggal dan bulan d, m dalam suatu tahun y
def hari_ke(d, m, y) :
    return dpm(m) + d - 1 + (1 if m > 2 and is_kabisat(y) else  0)

print (hari_ke(26, 9, 2006))
