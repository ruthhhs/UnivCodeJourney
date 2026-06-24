# Ruth Septriana Sipangkar
# 24060124120024

def gbk(matrix, n, m, sx, sy, gx, gy):
    visited = [[False]*m for _ in range(n)]

    # saat ini
    (x,y) = (sx,sy)
    jarak = 0

    # ngecek atas, bawah, kiri, kanan
    arah = [(0,1),(0,-1),(-1,0),(1,0)]

    for i, j in arah:
        # ini ngecek tiap kemungkinan arah gerak
        xbaru, ybaru = x+i, y+j

        if 0 <= xbaru < n and 0 <= ybaru < m:
            # ini ngecek yang ga negatif sama yang belum visited
            if matrix[xbaru][ybaru] < 0 or visited[xbaru][ybaru]:
                continue

            # terus di loop untuk milih yang terpendek gitu
                # pake f(x) nya dihitung, pake g(x) + h(x)
                # kalo ketemu yang f(x) terkecil, pindahin (x,y) ke (xbaru,ybaru)
                # jaraknya juga ditambah
            # di loop terus sampe nyentuh (gx,gy) atau kondisi gagal
            # kondisi gagal kalau keempat arah tadi nilainya negatif

# sudah menyerah 

# input
n, m = list(map(int, input().split()))
sx, sy, gx, gy = list(map(int, input().split()))
matrix = []
for _ in range(n) :
    matrix.append(list(map(int, input().split())))

gbk(matrix, n, m, sx, sy, gx, gy)
