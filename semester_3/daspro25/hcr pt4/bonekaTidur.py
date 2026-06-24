'''
    input : 
    hari: int (1 <= hari <= 7)
    minggu: int (minggu >= 1)

    output:
    boneka: str ("kobo"|| "zeta"|| "moona"|| "ollie"|| "risu")

    Story:
    anya punya banyak boneka : kobo, zeta, moona, ollie, risu
    tapi anya hanya bisa tidur dengan 1 boneka tiap malamnya. anya ingin adil agar tidak ada boneka yang merasa tidak disanyangi.
    Bantu anya membuat program untuk engatur jadwal tidur dengan bonekanya.

    Ketentuan :
    ⦁	weekday: di hari selasa dan kamis anya tidur dengan moona. di hari senin, rabu, dan jumat anya tidur dengan risu.
    ⦁	hari sabtu: jika minggu genap, anya tidur dengan kobo. dan jika minggu ganjil anya tidur dengan boneka zeta.
    ⦁	hari minggu: anya tidur dengan ollie. dan karena risu adalah kesayangan anya, setiap minggu ke 4 tiap bulannya, anya tidur dengan risu (asumsi 1 bulan ada 28 hari/4 minggu saja)
'''

def BonekaTidur (hari: int, minggu: int) -> str:
    if (hari == 6) :
        if (minggu % 2 == 0):
            return "kobo"
        else :
            return "zeta"
    elif (hari == 7):
        if (minggu % 4 == 0):
            return "risu"
        else :
            return "ollie"
    else:
        if (hari % 2 == 0):
            return "moona"
        else :
            return "risu"

print(BonekaTidur(1,1))
print(BonekaTidur(2,2))
print(BonekaTidur(6,1))
print(BonekaTidur(6,2))
print(BonekaTidur(7,1))
print(BonekaTidur(7,4))
print(BonekaTidur(7,5))
print(BonekaTidur(7,8))