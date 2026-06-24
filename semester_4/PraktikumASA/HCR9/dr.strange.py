# Ruth Septriana Sipangkar
# 24060124120024

# aku samain kayak dungeon...

def knapsack(i, nilai_curr, berat_curr, nilai_best, berat_best):
    # kelebihan berat
    if berat_curr > x:
        return nilai_best, berat_best
    
    # base case / best case
    if nilai_curr > nilai_best :
        nilai_best = nilai_curr
        berat_best = berat_curr

    # gatau....
    # hitung upper bound dan pruning
    # upper_bound = bound(i, nilai_curr, berat_curr)
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
n, x = list(map(int, input().split()))
barang = [list(map(int, input().split())) for _ in range(n)]

# output
nilai_best, berat_best = knapsack(0, 0, 0, 0, 0)
print(nilai_best)