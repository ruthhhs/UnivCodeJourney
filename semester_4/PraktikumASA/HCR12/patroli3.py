# Ruth Septriana Sipangkar
# 24060124120024

import heapq

n = int(input())
matriks = [list(map(int, input().split())) for _ in range(n)]
heuristik = list(map(int, input().split()))
awal, goal = list(map(int, input().split()))

def patroli(matriks, heuristik, awal, goal):
    aktif = []
    heapq.heappush(aktif, (heuristik[awal], awal))
    visited = [False]*n
    parent = [-1] * n
    
    while len(aktif) > 0 :
        heu, node = heapq.heappop(aktif)

        if node == goal :
            jalur = []
            while node != -1:
                jalur.append(node)
                node = parent[node]
            jalur.reverse() 
            return jalur

        if visited[node]:
            continue

        visited[node] = True
        for anak, heu_anak in enumerate(matriks[node]):
            if heu_anak > 0 and not visited[anak]:
                parent[anak] = node
                heapq.heappush(aktif, (heuristik[anak], anak))

    return -1

hasil = patroli(matriks, heuristik, awal, goal)
if hasil == -1 :
    print (hasil)
else:
    for i in hasil:
        print(i, end=" ")