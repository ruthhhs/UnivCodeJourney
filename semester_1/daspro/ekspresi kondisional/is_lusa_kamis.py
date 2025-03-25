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

#diketahui  pada 1 januari adalah hari jumat (y=2016)
#menentukan hari ini hari apa
#int --> string
def hari(d, m, y) :
    if (hari_ke(d, m, y) % 7) == 1 : return "Jumat"
    elif (hari_ke(d, m, y) % 7) == 2 : return "Sabtu"
    elif (hari_ke(d, m, y) % 7) == 3 : return "Minggu"
    elif (hari_ke(d, m, y) % 7) == 4 : return "Senin"
    elif (hari_ke(d, m, y) % 7) == 5 : return "Selasa"
    elif (hari_ke(d, m, y) % 7) == 6 : return "Rabu"
    elif (hari_ke(d, m, y) % 7) == 0 : return "Kamis"

#apakah lusa hari kamis?
#int --> boolean
def is_lusa_kamis (d, m, y) :  
    return  (hari_ke(d, m, y) + 2) % 7 == 0

print (hari_ke(1, 1, 2016))
print (hari_ke(2, 1, 2016))
print (hari_ke(3, 1, 2016))
print (hari_ke(4, 1, 2016))
print (hari_ke(5, 1, 2016))
print (hari_ke(6, 1, 2016))
print (hari_ke(7, 1, 2016))
print (hari_ke(26, 9, 2016))

print (hari(1, 1, 2016))
print (hari(2, 1, 2016))
print (hari(3, 1, 2016))
print (hari(4, 1, 2016))
print (hari(5, 1, 2016))
print (hari(6, 1, 2016))
print (hari(7, 1, 2016))
print (hari(26, 9, 2016))

print (is_lusa_kamis(1, 1, 2016))
print (is_lusa_kamis(2, 1, 2016))
print (is_lusa_kamis(3, 1, 2016))
print (is_lusa_kamis(4, 1, 2016))
print (is_lusa_kamis(5, 1, 2016))
print (is_lusa_kamis(6, 1, 2016))
print (is_lusa_kamis(7, 1, 2016))
print (is_lusa_kamis(26, 9, 2016))

print (is_lusa_kamis(2, 1, 2016))
print (is_lusa_kamis(5, 1, 2016))
print (is_lusa_kamis(26, 1, 2016))