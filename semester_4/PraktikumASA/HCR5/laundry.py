# Ruth Septriana Sipangkar
# 24060124120024

def laundry(nm, kpl, kmr):
    lewat = []
    jumlah = 0
    for jlh in kpl:
        jumlah += jlh
        lewat.append(jumlah)

    for kamar in kmr:
        lantai = cariLantai(lewat, kamar)
        if lantai == 0 :
            print(lantai + 1, kamar)
        else :
            print(lantai + 1, kamar - lewat[lantai - 1])

# cari lantai pake bst
def cariLantai(lewat, kamar):
    left = 0
    right = len(lewat) - 1
    lantai = right

    while left <= right:
        mid = (left + right) // 2
        if lewat[mid] >= kamar:
            lantai = mid
            right = mid - 1
        else:
            left = mid + 1

    return lantai

# input
nm = list(map(int, input().split())) # ga kepake si
kpl = list(map(int, input().split())) # jumlah kamar per lantai
kmr = list(map(int, input().split())) # no kamar lama
laundry(nm, kpl, kmr)