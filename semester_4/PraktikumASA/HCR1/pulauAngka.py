# Ruth Septriana Sipangkar
# 24060124120024

def pulauAngka(x, D, M):
    hasil = []
    for i in D:
        if i not in M:
            hasil.append(i)

    # print
    if len(hasil) == 0:
        print("KOSONG")
    else:
        for i in hasil:
            print(i, end=" ")

# hcr
# x = list(map(int, input().split()))
# D = list(map(int, input().split()))
# M = list(map(int, input().split()))
# pulauAngka(x, D, M)

# test
x = []
D = [1, 2, 3, 4, 5]
M = [2, 4, 6, 8]
pulauAngka(x, D, M) # 1 3 5

print(" ")
D1 = [2, 4]
pulauAngka(x, D1, M) # KOSONG
