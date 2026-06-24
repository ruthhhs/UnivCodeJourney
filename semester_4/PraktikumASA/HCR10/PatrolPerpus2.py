# Ruth Septriana Sipangkar
# 24060124120024

import heapq # aku liat dari geeks for geeks hehe, buat ambil cost terkecil katanya

# input
n = int(input())
matriks = [list(map(int, input().split())) for _ in range(n)]
awal, goal = list(map(int, input().split()))

def ucs(matriks, awal, goal):
    aktif = [] # isinya node hasil expand 
    heapq.heappush(aktif, (0, awal)) # (0, awal) maksudnya node awal costnya 0
    visited = [False]*n # isinya node yg dah di cek

    while len(aktif) > 0 :
        cost, node = heapq.heappop(aktif)
        # base case
        if node == goal :
            return cost
        # skip
        if visited[node]:
            continue

        # cek lah anakan
        visited[node] = True
        for anak, cost_anak in enumerate(matriks[node]): # enumerate --> nganuin index (?) anak sebagai costnya kira kira
            if cost_anak > 0 and not visited[anak]:
                total = cost + cost_anak
                heapq.heappush(aktif, (total, anak))
        # kira kira beginilah:
        # cost --> biaya node skrg
        # cost_anak --> biaya si anak
        # total --> jarak sejauh ini (hasil jumlah)

    return -1 # failure

print(ucs(matriks, awal, goal))