# Ruth Septriana Sipangkar
# 24060124120024

def turnamen(n, k, skor):
    skor.sort(reverse=True) # mff, pake ini dulu hehe

    batas = skor[k - 1]
    jumlah = jumlahLolos(n, batas, skor)

    print(batas, jumlah, end=" ")

def jumlahLolos(n, batas, skor):
    # disini anggapannya udah urut dr terbesar
    if n == 1:
        if skor[0] >= batas :
            return 1
        else :
            return 0
    else :
        if skor[0] >= batas :
            return 1 + jumlahLolos(n-1, batas, skor[1:])
        else :
            return jumlahLolos(n-1, batas, skor[1:])

# input
n, k = list(map(int, input().split()))
skor = list(map(int, input().split()))
turnamen(n, k, skor)