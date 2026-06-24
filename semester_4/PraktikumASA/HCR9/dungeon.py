# Ruth Septriana Sipangkar
# 24060124120024

# def bound(i, nilai_curr, berat_curr):
#     # kelebihan berat
#     if berat_curr > x:
#         return 0

#     upper_bound = nilai_curr
#     total_berat = berat_curr

#     # ambil item sampai penuh / ga kelebihan
#     while i < n and total_berat + barang[i][1] <= x:
#         nilai, berat = barang[i]
#         upper_bound += nilai
#         total_berat += berat
#         i += 1

#     if i < n:
#         nilai, berat = barang[i]
#         sisa = x - total_berat
#         upper_bound += sisa * (nilai / berat)

#     return upper_bound

def knapsack(i, nilai_curr, berat_curr, nilai_best, berat_best):
    # kelebihan berat
    if berat_curr > x:
        return nilai_best, berat_best
    
    # base case / best case
    if nilai_curr > nilai_best :
        nilai_best = nilai_curr
        berat_best = berat_curr

    # hitung upper bound
    # upper_bound = bound(i, nilai_curr, berat_curr)

    # pruning
    # if upper_bound <= nilai_best:
    #     return nilai_best, berat_best

    # berhenti brancing
    if i == n :
        return nilai_best, berat_best
    
    # brancing
    nilai, berat = barang[i]
    nilai_best, berat_best = knapsack(i+1, nilai_curr+nilai, berat_curr+berat, nilai_best, berat_best)
    nilai_best, berat_best = knapsack(i+1, nilai_curr, berat_curr, nilai_best, berat_best)

    return nilai_best, berat_best

# input
n = int(input())
x = int(input())
barang = [list(map(int, input().split())) for _ in range(n)]

# output
nilai_best, berat_best = knapsack(0, 0, 0, 0, 0)
print(nilai_best, berat_best, end=" ")