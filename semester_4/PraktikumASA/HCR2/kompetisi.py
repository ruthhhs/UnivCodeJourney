# Ruth Septriana Sipangkar
# 24060124120024

def kompetisi(n, arr):
    hasil_jumlah = -10**12
    hasilL = 0
    hasilR = 0

    jum = 0
    l = 0

    for i in range(n):
        if jum + arr[i] < arr[i]:
            jum = arr[i]
            l = i
        else:
            jum += arr[i]

        panjang = i - l
        hasil_panjang = hasilR - hasilL

        if (jum > hasil_jumlah or
            (jum == hasil_jumlah and panjang > hasil_panjang) or
            (jum == hasil_jumlah and panjang == hasil_panjang and l < hasilL)):
            hasil_jumlah = jum
            hasilL = l
            hasilR = i

    print(hasil_jumlah)
    print(hasilL + 1, hasilR + 1)

# hcr
# n = int(input())
# arr = list(map(int, input().split()))
# kompetisi(n, arr)

n = 7
arr = [1, 2, -4, 4, 2, 4, -1]
kompetisi(n, arr)