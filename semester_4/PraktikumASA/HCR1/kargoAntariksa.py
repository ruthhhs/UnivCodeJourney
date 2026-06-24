# Ruth Septriana Sipangkar
# 24060124120024

def stabilitas(wa, wb, wc):
    return wa*wb + wb*wc + wc*wa

def kombinasiValid(n, arr):
    maks = 0
    for i in range(n):
        for j in range(i+1, n):
            for k in range(j+1, n):
                if stabilitas(arr[i], arr[j], arr[k]) % 2 != 0 :
                    temp = arr[i] + arr[j] + arr[k]
                    if maks < temp :
                        maks = temp
    if maks == 0:
        return -1
    else:
        return maks

# hcr
# n = int(input())
# arr = list(map(int, input().split()))
# print(kombinasiValid(n, arr))

# test
print(kombinasiValid(5, [2, 4, 6, 8, 10])) # -1
print(kombinasiValid(5, [1, 2, 3, 4, 5])) # 12