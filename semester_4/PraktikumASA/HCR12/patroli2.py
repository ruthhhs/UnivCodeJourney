# Ruth Septriana Sipangkar
# 24060124120024

import heapq

n = int(input())
matriks = [list(map(int, input().split())) for _ in range(n)]
awal, goal = list(map(int, input().split()))

def patroli(matriks, awal, goal):
    aktif = []
    heapq.heappush(aktif, (0, awal))
    visited = [False]*n

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

print(patroli(matriks, awal, goal))