# Ruth Septriana Sipangkar
# 24060124120024

# bisa +1 atau +2
# input 2 --> +11 atau +2 --> 2 cara
# input 4 --> +1111, +112, +121, +211, +22 --> 5 cara

# dp nyimpan jumlah cara x
# jumlah ngitung penjumlahan si x nya
def naikTangga(x, dp):
    if x == 1:
        return 1

    for i in range(x):
        if i - 1 >= 0:
            dp = 1 + naikTangga(i-1, dp)
        if i - 2 >= 0:
            dp = 1 + naikTangga(i-2, dp)
        dp = naikTangga(x-1, dp) + naikTangga(i-2, dp)

    return dp

# input
x = int(input())
dp = 0 # ak buat jumlah....

# output
print(naikTangga(x, dp))

# sepertinya aku mendapat pencerahan
# ini haunya kan si dp jadi array sepanjang x untuk nyimpan sesuatu kan
# berarti harusnya jumlahnya disimpan ke dp kan ya...
# terus yang di return itu isi si dp yang x nya 0
# tapi gatau kak, kepalaku sakit