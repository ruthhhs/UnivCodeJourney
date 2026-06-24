# Ruth Septriana Sipangkar
# 24060124120024

# blm bisa cek tetangga

def bfs(matrix, i, j, visited):
    queue = ([(i, j)])
    visited.add((i, j))
    
    is_edge = False

    while queue:
        x, y = queue.pop()

        if (x == 0 or x == len(matrix)-1 or
            y == 0 or y == len(matrix[0])-1):
            is_edge = True

    return is_edge

def danauSungai():
    n, m = list(map(int, input().split()))
    matrix = []
    for i in range(n) :
        matrix.append(list(map(int, input().split())))

    visited = set()
    danau = 0
    sungai = 0

    for i in range(n):
        for j in range(m):
            if matrix[i][j] == 0 and (i, j) not in visited:
                tepi = bfs(matrix, i, j, visited)
                if tepi :
                    sungai += 1
                else :
                    danau += 1

    print(danau, sungai, end=" ")

danauSungai()