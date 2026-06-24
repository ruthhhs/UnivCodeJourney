# Ruth Septriana Sipangkar
# 24060124120024

# algoritma greedy (?)

import heapq

n, m = list(map(int, input().split()))
sx, sy, gx, gy = list(map(int, input().split()))
matriks = [list(map(int, input().split())) for _ in range(n)]

def gbk(matriks, sx, sy, gx, gy):
    awal = (sx, sy)
    goal = (gx, gy)

    aktif = []
    heapq.heappush(aktif, (0, awal))
    visited = [[False]*m for _ in range(n)]

    while len(aktif) > 0 :
        cost, node = heapq.heappop(aktif)
        if node == goal :
            return cost
        if visited[node]:
            continue

        visited[node] = True
        for anak, cost_anak in enumerate(matriks[node]):
            if cost_anak > 0 and not visited[anak]:
                total = cost + cost_anak
                heapq.heappush(aktif, (total, anak))

    return -1

print(gbk(matriks, sx, sy, gx, gy))