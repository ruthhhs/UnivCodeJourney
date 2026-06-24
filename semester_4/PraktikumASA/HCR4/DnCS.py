# Ruth Septriana Sipangkar
# 24060124120024

def Prima(n):
    # mff ini aja dulu wkkw
    prima = [2, 3, 5, 7, 11, 13, 17]
    if n in prima:
        return True
    else:
        for i in prima:
            if n % i == 0 :
                return False

def JumlahPrima(n, arr):
    jumlah = 0
    mid = n // 2

    for i in range(n):
        if Prima(arr[i]):
            jumlah += arr[i]
        else:
            JumlahPrima(mid, arr[:mid]) #left
            JumlahPrima(mid, arr[mid:]) #right

    return jumlah

# n = int(input())
# arr = list(map(int, input().split()))
# print(JumlahPrima(n, arr))

print(Prima(100))