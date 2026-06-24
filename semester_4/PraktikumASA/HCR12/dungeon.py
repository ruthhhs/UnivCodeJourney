# Ruth Septriana Sipangkar
# 24060124120024

n = int(input())
x = int(input())
barang = [list(map(int, input().split())) for _ in range(n)]

def knapsack(i, v, w, hasil_v, hasil_w):
    if w > x:
        return hasil_v, hasil_w
    
    if v > hasil_v :
        hasil_v = v
        hasil_w = w

    if i == n :
        return hasil_v, hasil_w
    
    nilai, berat = barang[i]
    hasil_v, hasil_w = knapsack(i+1, v+nilai, w+berat, hasil_v, hasil_w)
    hasil_v, hasil_w = knapsack(i+1, v, w, hasil_v, hasil_w)

    return hasil_v, hasil_w

hasil_v, hasil_w = knapsack(0, 0, 0, 0, 0)
print(hasil_v, hasil_w, end=" ")