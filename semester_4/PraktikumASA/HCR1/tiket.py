# Ruth Septriana Sipangkar
# 24060124120024

def tiket(n, t, arr):
    hasil = -1

    for i in range(n):
        for j in range(i, n):
            if arr[i] + arr[j] == t and i != j:
                temp = arr[i] * arr[j]
                if temp > hasil :
                    hasil = temp

    return hasil

# hcr
# n = int(input())
# t = int(input())
# arr = list(map(int, input().split()))
# print(tiket(n, t, arr))

# test
print(tiket(5, 10, [1, 9, 5, 5, 2]))