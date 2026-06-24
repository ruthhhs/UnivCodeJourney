# Ruth Septriana Sipangkar
# 24060124120024

def dfs(matrix, i, j, visited=None):
    if (i < 0 or i >= len(matrix) or
        j < 0 or j >= len(matrix[0])):
        return 0
    if matrix[i][j] == 0 or (i, j) in visited:
        return 0
    
    visited.add((i, j))
    
    count = 1
    count += dfs(matrix, i+1, j, visited)
    count += dfs(matrix, i-1, j, visited)
    count += dfs(matrix, i, j+1, visited)
    count += dfs(matrix, i, j-1, visited)
    
    return count

def labubu():
    n, m = list(map(int, input().split()))
    matrix = []
    for i in range(n) :
        matrix.append(list(map(int, input().split())))

    visited = set()
    jumlah = 0
    
    for i in range(n):
        for j in range(m):
            if matrix[i][j] == 1 and (i, j) not in visited:
                luas = dfs(matrix, i, j, visited)
                if luas >= 2:
                    jumlah += 1
    
    print (jumlah)

labubu()