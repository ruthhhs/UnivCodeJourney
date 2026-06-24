# Ruth Septriana Sipangkar
# 24060124120024

n = int(input())
matriks = [list(map(int, input().split())) for _ in range(n)]
visited = [False]*n
visited[0] = True

def patroli(node, visited, jlh_visited, jarak, jarak_terbaik):
    lower_bound = jarak
    for i in range(n):
        if not visited[i]:
            min_out = 99999999
            for j in range(n):
                if i != j and matriks[i][j] != 0:
                    if matriks[i][j] < min_out:
                        min_out = matriks[i][j]
            lower_bound += min_out

    if lower_bound >= jarak_terbaik:
        return jarak_terbaik

    if jlh_visited == n :
        if matriks[node][0] != 0:
            total_cost = jarak + matriks[node][0]
            jarak_terbaik = min(jarak_terbaik, total_cost)
        return jarak_terbaik

    for next_node in range(n):
        if not visited[next_node] and matriks[node][next_node] != 0: # unvisited
            visited[next_node] = True
            jarak_terbaik = patroli(next_node, visited, jlh_visited + 1, jarak + matriks[node][next_node], jarak_terbaik)
            visited[next_node] = False

    return jarak_terbaik

hasil = patroli(0, visited, 1, 0, 99999999)
if hasil == 99999999:
    print(-1)
else:
    print(hasil)