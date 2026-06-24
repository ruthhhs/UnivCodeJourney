# Ruth Septriana Sipangkar
# 24060124120024

def pakJoko (joko):
    # cari pola dulu
    freq = {}
    for huruf in joko:
        if huruf in freq:
            freq[huruf] += 1
        else:
            freq[huruf] = 1

    pola = "zzz"
    max_count = 0
    for huruf in freq:
        if freq[huruf] > max_count:
            max_count = freq[huruf]
            pola = huruf

    # ini baru anuin lokasi errornya
    error = []
    for i in range(len(joko)):
        if joko[i] != pola:
            error.append(str(i+1))
        else:
            continue

    if len(error) == 0:
        print(-1)
    else:
        print(" ".join(error))

# hcr
# pakJoko(input())

# test
pakJoko("AAABAAAA") # 4
pakJoko("AAaABAAA") # 3 5
pakJoko("aAAAABAA") # 1 6