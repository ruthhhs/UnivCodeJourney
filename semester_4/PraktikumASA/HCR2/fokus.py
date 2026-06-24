# Ruth Septriana Sipangkar
# 24060124120024

def fokus(nt):
    n, t = nt

    durasi = []
    fokus = []

    for _ in range(n):
        lagu = list(map(int, input().split()))
        if lagu[0] < 5:
            durasi.append(lagu[0])
            fokus.append(lagu[1])

    n = len(durasi)
    if n == 0:
        return 0

    cekLagu = []
    for _ in range(t+1):
        cek = []
        for _ in range(n+1):
            cek.append(-1)
        cekLagu.append(cek)
    
    cekLagu[0][n] = 0

    for t in range(t+1):
        for last in range(n+1):
            if cekLagu[t][last] == -1:
                continue

            for i in range(n):
                if i == last:
                    continue

                nt = t + durasi[i]
                if nt <= t:
                    cekLagu[nt][i] = max(cekLagu[nt][i], 
                                         cekLagu[t][last] + fokus[i])

    hasil = 0
    for t in range(t+1):
        for last in range(n):
            hasil = max(hasil, cekLagu[t][last])

    return hasil

# hcr
nt = list(map(int, input().split()))
print(fokus(nt))