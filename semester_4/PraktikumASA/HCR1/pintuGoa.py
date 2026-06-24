# Ruth Septriana Sipangkar
# 24060124120024

def faktorial(n):
    if n == 0: return 1

    hasil = 1
    for i in range(1, n+1):
        hasil *= i
    return hasil

def pintuGoa(kode):
    n = len(kode)
    hasil = faktorial(n)

    dah_ada = ""

    for huruf in kode:
        if huruf not in dah_ada:
            jlh = 0
            for j in kode:
                if j == huruf:
                    jlh += 1
            hasil //= faktorial(jlh)
            dah_ada += huruf
        else:
            continue

    return hasil

# hcr
# print(pintuGoa(input()))

# test
print(pintuGoa("ADA")) # 3
print(pintuGoa("AIR")) # 6
print(pintuGoa("INFORMATIKA")) # 9979200
print(pintuGoa("AAAAAA")) # 1
print(pintuGoa("ABCDEFGHIJKLMNOPQRSTUVWXYZ")) # 403291461126605635584000000