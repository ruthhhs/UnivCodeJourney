# Ruth Septriana Sipangkar
# 24060124120024

def bukitLembah(n, arr):
    if n <= 1:
        return 0

    hitung = []
    hitung.append(arr[0])

    arah = 0  # 1 = naik, -1 = turun

    for i in range(1, n):
        if arr[i] > arr[i-1]:
            if arah == -1:
                # lembah
                hitung.append(arr[i-1])
            arah = 1
        elif arr[i] < arr[i-1]:
            if arah == 1:
                # bukit
                hitung.append(arr[i-1])
            arah = -1

    hitung.append(arr[-1])

    maks = 0
    for i in range(1, len(hitung)):
        selisih = abs(hitung[i] - hitung[i-1])
        if selisih > maks:
            maks = selisih

    return maks


# hcr
# n = int(input())
# arr = list(map(int, input().split()))
# print(bukitLembah(n, arr))

# test
test = [1, 4, 6, 6, 3, 2]
print(bukitLembah(6, test))
