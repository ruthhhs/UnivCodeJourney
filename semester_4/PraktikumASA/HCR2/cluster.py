# Ruth Septriana Sipangkar
# 24060124120024

def cluster(arr):
    r, c, d = arr

    matriks = []
    for _ in range(r):
        matriks.append(list(map(int, input().split())))

    hasil = -1

    for i in range(r-2):
        for j in range(c-2):

            temp = 0
            maks = 0
            minn = 1000

            for a in range(3):
                for b in range(3):
                    temp += matriks[i+a][j+b]
                    maks = max(maks, matriks[i+a][j+b])
                    minn = min(minn, matriks[i+a][j+b])

                    if hasil < temp and maks - minn >= d:
                        hasil = temp

    print(hasil)

# hcr
arr = list(map(int, input().split()))
cluster(arr)