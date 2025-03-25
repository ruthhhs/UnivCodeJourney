# kode / 10m^3 pertama / 10m^3 berikutnya
# A  /  rp. 30 000   /  rp 2500
# B  /  rp  40 000   /  rp 3000
# C  /  rp 50 000   /  rp 3500

# x mewakili kode
# y mewakili m^3 penggunaan
def tarif(x, y) :
    if x == 'A' :
        if y < 10 : return 30000
        else : return 30000 + ((y-10)*2500)
    elif x == 'B' :
        if y < 10 : return 40000
        else : return 40000 + ((y-10)*3000)
    elif x == 'C' :
        if y < 10 : return 50000
        else : return 50000 + ((y-10)*3500)


print(tarif('A', 15))
print(tarif('B', 15))
print(tarif('C', 15))