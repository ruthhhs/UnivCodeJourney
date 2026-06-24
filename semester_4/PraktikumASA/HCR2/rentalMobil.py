# Ruth Septriana Sipangkar
# 24060124120024

def rentalMobil(nmx):
    n, targetK, targetN = nmx

    hargaMin = -1
    kapasitas = []
    nyaman = []
    harga = []

    for _ in range(n):
        a, b, c = (list(map(int, input().split())))
        kapasitas.append(a)
        nyaman.append(b)
        harga.append(c)

    for i in range(1, 2 ** n):
        tempK = 0
        tempN = 0
        tempH = 0
        for j in range(n):
            if (i >> j) & 1:
                tempK += kapasitas[j]
                tempN += nyaman[j]
                tempH += harga[j]

            if (tempK >= targetK and tempN >= targetN and
                (hargaMin > tempH or hargaMin == -1)):
                
                hargaMin = tempH

    return hargaMin

# hcr
nmx = list(map(int, input().split()))
print(rentalMobil(nmx))