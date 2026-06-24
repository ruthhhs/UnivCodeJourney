# Ruth Septriana Sipangkar
# 24060124120024

# Buatlah implementasi algoritma QuickSort menggunakan bahasa 
# pemrograman dengan strategi pemilihan pivot pertama 
# secara acak (random pivot).
# Gunakan array dengan jumlah elemen minimal 7.
# Lakukan beberapa percobaan dengan variasi pivot awal,
# kemudian bandingkan performa algoritma berdasarkan jumlah 
# perbandingan atau iterasi yang terjadi selama proses sorting.
# Dari hasil percobaan tersebut, tentukan indeks pivot yang 
# paling optimal dan berikan analisisnya.

import random

def quicksort(senarai, left, right) :
    if left < right :
        idx = random.randint(left, right)
        pivot = senarai[idx]
        print(senarai)
        print(f"pivot : {pivot}, pada index : {idx + 1}")

        p = partisi(senarai, left, right, pivot)
        quicksort(senarai, left, p)
        quicksort(senarai, p + 1, right)

def partisi(senarai, left, right, pivot) :
    while True :
        while senarai[left] < pivot :
            left += 1
        while senarai[right] > pivot :
            right -= 1
        if left < right :
            # tukar
            senarai[left], senarai[right] = senarai[right], senarai[left]
            left += 1
            right -= 1
        if left >= right :
            break
    return right

# main
senarai = [4,3,6,7,2,6,1,5,8]
quicksort(senarai, 0, len(senarai) - 1)
print("Senarai terurut :")
print(senarai)