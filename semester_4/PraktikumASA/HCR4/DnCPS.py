# Ruth Septriana Sipangkar
# 24060124120024

def BinarySearch(n, x, arr):
    index = -1
    mid = n // 2

    for i in range(n):
        if arr[i] == x:
            index = i + 1
        else:
            BinarySearch(mid, x, arr[:mid]) #left
            BinarySearch(mid, x, arr[mid:]) #right

    return index

n, x = list(map(int, input().split()))
arr = list(map(int, input().split()))
print(BinarySearch(n, x, arr))