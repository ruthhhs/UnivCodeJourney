# Ruth Septriana Sipangkar
# 24060124120024

def cari(n, arr):
    freq = {}
    for angka in arr:
        if angka in freq:
            freq[angka] += 1
        else:
            freq[angka] = 1

    maks = -1
    max_count = 0
    for angka in freq:
        if freq[angka] > max_count:
            max_count = freq[angka]
            maks = angka
    
    if max_count > (n/2):
        return maks
    else:
        return -1

def dominan(nq, arr):
    n = nq[0]
    q = nq[1]

    for i in range(q):
        l, r = list(map(int, input().split()))

        sub = arr[l-1:r]
        panjang = r - l + 1
        hasil = cari(panjang, sub)
        print(hasil)


# hcr
nq = list(map(int, input().split()))
arr = list(map(int, input().split()))
dominan(nq, arr)