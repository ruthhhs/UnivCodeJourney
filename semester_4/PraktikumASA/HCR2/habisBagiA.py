# Ruth Septriana Sipangkar
# 24060124120024

def sieve(n):
    prime = [True] * (n + 1)
    p = 2

    while p * p <= n:
        if prime[p]:
            for i in range(p * p, n + 1, p):
                prime[i] = False
        p += 1

    res = [1]
    for p in range(2, n + 1):
        if prime[p]:
            res.append(p)

    return res

def habisBagiA(q):
    for _ in range(q):
        l, r = list(map(int, input().split()))
        prima = sieve(r)

        hasil = []
        for angka in prima:
            if angka >= l:
                hasil.append(angka)

        print(len(hasil))
        if q == 1:
            print(*hasil)

# hcr
habisBagiA(int(input()))