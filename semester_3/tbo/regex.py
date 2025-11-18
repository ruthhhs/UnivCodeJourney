import re

teks = "Narahubung kami dapat dihubungi melalui 0853-6689-8234 atau 0852-3457-9364"
pola = r"08[0-9]{2}-[0-9]{4}-[0-9]{4}"
hasil = re.findall(pola, teks)

if hasil:
    print("Nomor ditemukan pada:")
    for nomor in hasil:
        print(nomor)
else:
    print("Nomor tidak ditemukan.")
