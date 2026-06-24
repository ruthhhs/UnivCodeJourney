# NAMA  : Ruth Septriana Sipangkar
# NIM   : 24060124120024
# LAB   : C2

def virus(nt) :
    n, t = nt[0], nt[1]
    
    # baca input matriksnya
    matriks = []
    for _ in range(n):
        matriks.append(list(map(int, input().split())))

    # inisialisasi nilai
    maks = 0
    posx = 0
    posy = 0
    
    # cari setiap kemungkinan
    for i in range(n):
        for j in range(n):

            # jumlahin virus setiap kemungkinan
            temp = 0
            for a in range(n):
                for b in range(n):
                    # jarak manhattannya
                    if abs(i-a) + abs(j-b) <= t:
                        temp += matriks[a][b]

            # ini ngubah nilai terbaru
            if (maks < temp or
                maks == temp and i + 1 < posx or
                maks == temp and i + 1 == posx and j + 1 < posy):
                maks = temp
                posx = i + 1
                posy = j + 1

    # keluarkan hasil
    print(maks, posx, posy, end=" ")

# panggil fungsi
nt = list(map(int, input().split()))
virus(nt)