# Ruth Septriana Sipangkar
# 24060124120024

# input n, matriks jarak
# tiap state dijadiin node dalam tree, dfs
# --> hitung semua kemungkinan jarak, sampe kembali ke awal (tsp)
# bandingkan dengan lower bound, kalau state new < lower --> lower = new
# kalau semua kemingkinan ga balik ke 0 --> output -1

def dfs_bb(curr, visited, visited_count, cost_so_far, best_cost):
    # bounding
    lower_bound = cost_so_far
    for i in range(n):
        if not visited[i]:
            min_out = 1000
            for j in range(n):
                if i != j and dist[i][j] != 0:
                    if dist[i][j] < min_out:
                        min_out = dist[i][j]
            lower_bound += min_out

    # pruning
    if lower_bound >= best_cost:
        return best_cost

    # base case
    if visited_count == n :
        if dist[curr][0] != 0: # can return ke node awal
            total_cost = cost_so_far + dist[curr][0]
            best_cost = min(best_cost, total_cost)
        return best_cost

    # backtrack
    for next_node in range(n):
        if not visited[next_node] and dist[curr][next_node] != 0: # unvisited
            visited[next_node] = True
            best_cost = dfs_bb(next_node, visited, visited_count + 1, cost_so_far + dist[curr][next_node], best_cost)
            visited[next_node] = False

    return best_cost

# input
n = int(input())
dist = [list(map(int, input().split())) for _ in range(n)]
visited = [False]*n
visited[0] = True

# output
hasil = dfs_bb(0, visited, 1, 0, 1000)
if hasil == 1000:
    print(-1)
else:
    print(hasil)