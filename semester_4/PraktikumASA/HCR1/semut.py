# Ruth Septriana Sipangkar
# 24060124120024

def semut(x, y, count):
    i = 1
    while (count > 0):
        hasil = x * i
        if hasil % y != 0:
            print(hasil, end= " ")
            count -= 1
        i += 1

# hcr
# x, y, count = map(int, input().split())
# semut(x, y, count)

# test
semut(2, 3, 5) # 2 4 8 10 12
print(' ')
semut(1, 2, 10) # 1 3 5 7 9 11 13 15 17 19