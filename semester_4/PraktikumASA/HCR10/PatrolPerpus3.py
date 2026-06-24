# Ruth Septriana Sipangkar
# 24060124120024

# mirip perpus patrol 2 kan
import heapq

# input
n = int(input())
matriks = [list(map(int, input().split())) for _ in range(n)]
heuristik = list(map(int, input().split()))
awal, goal = list(map(int, input().split()))

def greedy_bfs(matriks, heuristik, awal, goal):
    aktif = [] # isinya node hasil expand 
    heapq.heappush(aktif, (heuristik[awal], awal)) # maksudnya node awal dan heuristiknya
    visited = [False]*n # isinya node yg dah di cek
    parent = [-1] * n
    
    while len(aktif) > 0 :
        heu, node = heapq.heappop(aktif)

        # base case
        if node == goal :
            jalur = []
            while node != -1: # berarti masi ada paretn
                jalur.append(node) # masukin node sekarang
                node = parent[node] # loop sampe awal
            jalur.reverse() # karna node tadi mulai dr goal (base case), brrti dibalik biar mulai dr awal
            return jalur
        
        # skip
        if visited[node]:
            continue

        # cek anakan
        visited[node] = True
        for anak, heu_anak in enumerate(matriks[node]):
            if heu_anak > 0 and not visited[anak]:
                parent[anak] = node # biar bs cetak jalur nnti
                heapq.heappush(aktif, (heuristik[anak], anak))

    return -1 # failure

hasil = greedy_bfs(matriks, heuristik, awal, goal)
if hasil == -1 :
    print (hasil)
else:
    for i in hasil:
        print(i, end=" ")