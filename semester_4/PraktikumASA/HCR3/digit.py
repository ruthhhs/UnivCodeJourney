# Ruth Septriana Sipangkar
# 24060124120024

def jumlahN(n: str) -> int:
    if len(n) == 1 :
        return int(n)
    else :
        return int(n[0]) + int(jumlahN(n[1:]))

def sisaSatu(n: str) -> int:
    if len(n) == 1:
        return int(n)
    else:
        return sisaSatu(str(jumlahN(n)))

def digitKhusus(n, k):
    d = sisaSatu(str(n)) * k
    if len(str(d)) != 1:
        d = sisaSatu(str(d))
    print(d)
    if d % 2 == 0:
        print('A')
    else:
        print('B')

# n = int(input())
# k = int(input())
# digitKhusus(n, k)

digitKhusus(28, 3) # 3 B
digitKhusus(48, 4) # 3 B
