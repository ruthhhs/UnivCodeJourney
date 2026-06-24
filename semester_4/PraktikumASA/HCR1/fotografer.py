# Ruth Septriana Sipangkar
# 24060124120024

def fotografer(nm):
    n, m = nm[0], nm[1]
    
    matriks = []
    for _ in range(n):
        matriks.append(list(map(int, input().split())))

    maks = -10 ** 12
    size = 0
    x = 0
    y = 0

    kotak = min(n, m)
    for k in range(1, kotak+1):
        for i in range(n - k + 1):
            for j in range(m - k + 1):

                temp = 0
                for a in range(k):
                    for b in range(k):
                        temp += matriks[i + a][j + b]

                if (temp > maks or
                   (temp == maks and k > size) or
                   (temp == maks and k == size and i + 1 < x) or
                   (temp == maks and k == size and i + 1 == x and j + 1 < y)):

                    maks = temp
                    size = k
                    x = i + 1
                    y = j + 1

    print(maks, kotak, x, y, end=" ")

# hcr
nm = list(map(int, input().split()))
fotografer(nm)