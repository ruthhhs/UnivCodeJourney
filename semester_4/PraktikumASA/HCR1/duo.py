# Ruth Septriana Sipangkar
# 24060124120024

def duo(n, arr):
    maks = 0
    for i in range(n):
        for j in range(n):
            if i != j :
                temp = arr[i] + arr[j]
                if maks < temp:
                    maks = temp
    return maks

# hcr
# n = int(input())
# arr = list(map(int, input().split()))
# print(duo(n, arr))

# test
print(duo(8, [90, 66, 15, 15, 13, 48, 6, 76]))
