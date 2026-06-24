# Ruth Septriana Sipangkar
# 24060124120024

# ini ngecek dia bisa ke kotak atau engga, nanti kalo engga di loop di utama
def is_safe(n, m, r, c, visited):
    if r < 0 or r >= n or c < 0 or c >= m or visited[r][c]:
        return False
    return True

def solve_kuda(n, m, r, c):
    visited = [[False]*m for _ in range(n)]

    # ini nganuin ini (x+-1, y+-2) atau (x+-2, y+-1)
    gerak = [
        (-2, 1), (-1, 2),
        (1, 2), (2, 1),
        (2, -1), (1, -2),
        (-1, -2), (-2, -1)
    ]

    langkah = 0
    semua = n * m

    for _ in range(semua):
        print(f"({r},{c})", end="")
        visited[r][c] = True
        langkah += 1

        for i, j in gerak:
            # nyoba kemungkinan gerak per langkah
            if is_safe(n, m, r+i, c+j, visited):
                r = r+i
                c = c+j
                # kalo bisa gerak, stop langkah ini, lanjut langkah berikutnya
                break

    # berarti ga kejalanin semua
    if langkah != semua :
        return "Ronda Gagal."

# input 
n, m = list(map(int, input().split()))
r, c = list(map(int, input().split()))

solve_kuda(n, m, r, c)