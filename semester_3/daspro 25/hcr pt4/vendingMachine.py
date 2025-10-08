'''
INPUT :
    Koin (K): integer
    Hari (H): integer [1..7]

OUTPUT:
    Minuman (M): string ("Teh" || "Kopi" || "Susu" || "Air Mineral" || "Jus")

STORY:
    Di sekolah Bochi ada sebuah vending machine unik yang akan mengeluarkan minuman berbeda-beda tergantung jumlah koin (K) yang dimasukkan dan hari (H) keberapa dalam seminggu. Sebagai teman Bochi yang seorang anak IT, kamu mau membantu dengan membuat program yang memberi tahu minuman apa yang akan keluar.
    (Notes: satu minggu dimulai dari hari Senin)

    Ketentuan mesinnya adalah jika jumlah koin sama dengan hari, keluar "Teh". Untuk 3 hari pertama dalam seminggu, jika koin lebih banyak dari hari, keluar "Susu". Khusus hari Selasa, Kamis, dan Sabtu, jika jumlah koin adalah setengah dari hari, keluar "Air Mineral", selain itu keluar "Kopi". Karena Minggu adalah Hari libur, minumannya spesial untuk setiap koin kelipatan 3, yaitu "Jus:. Selain semua ketentuan itu, akan keluar "Air Mineral".
'''

def Minuman(k, h):
    if (k==h):
        return "Teh"
    elif (h <= 3 and k > h):
        return "Susu"
    elif (h % 2 == 0):
        if (k == h/2):
            return "Air Mineral"
        else :
            return "Kopi"
    elif(h == 7 and k % 3 == 0):
        return "Jus"
    else :
        return "Air Mineral"
        
print(Minuman(1,1)) # Teh (contoh 0)
print(Minuman(1,2)) # Air Mineral (contoh 1)

print(Minuman(2,1)) # Susu 
print(Minuman(2,2)) # Teh
# print(Minuman(3,2)) # Susu
print(Minuman(2,3)) # Air Mineral
# print(Minuman(3,3)) # Teh
print(Minuman(6,3)) # Susu
# print(Minuman(2,4)) # Air Mineral
# print(Minuman(1,4)) # Kopi
# print(Minuman(4,4)) # Teh
print(Minuman(5,4)) # Kopi
print(Minuman(2,5)) # Air Mineral
# print(Minuman(5,5)) # Teh
print(Minuman(6,5)) # Air Mineral
print(Minuman(2,6)) # Kopi
# print(Minuman(3,6)) # Air Mineral
# print(Minuman(4,6)) # Kopi
# print(Minuman(6,6)) # Teh
# print(Minuman(7,6)) # Kopi
# print(Minuman(1, 7)) # Air Mineral
print(Minuman(3, 7)) # Jus
print(Minuman(5, 7)) # Air Mineral
# print(Minuman(7, 7)) # Teh