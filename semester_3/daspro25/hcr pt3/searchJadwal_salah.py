def SearchJadwal(hari, mulai, akhir):
    if hari == "sen":
        if (mulai >= 15 or akhir <= 13):
            return "Dasar Pemrograman"
        else:
            return "Tidak ada"

    elif hari == "sel":
        if (mulai >= 13 or akhir <= 15):
            return "Aljabar Linier"
        else:
            return "Tidak ada"

    elif hari == "rab":
        if (mulai >= 7 or akhir <= 10) and (mulai >= 15 or akhir <= 16):
            return "Dasar Sistem & Bahasa Inggris I"
        elif (mulai >= 7 or akhir <= 10):
            return "Dasar Sistem"
        elif (mulai >= 15 or akhir <= 16):
            return "Bahasa Inggris I"
        else:
            return "Tidak ada"

    elif hari == "kam":
        if (mulai >= 7 or akhir <= 9) and (mulai >= 13 or akhir <= 15):
            return "Pancasila & Matematika I"
        elif (mulai >= 7 or akhir <= 9):
            return "Pancasila"
        elif (mulai >= 13 or akhir <= 15):
            return "Matematika I"
        else:
            return "Tidak ada"

    elif hari == "jum":
        if (mulai >= 7 or akhir <= 9) and (mulai >= 13 or akhir <= 16):
            return "Bahasa Indonesia & Struktur Diskrit"
        elif (mulai >= 7 or akhir <= 9):
            return "Bahasa Indonesia"
        elif (mulai >= 13 or akhir <= 16):
            return "Struktur Diskrit"
        else:
            return "Tidak ada"

    else:
        return "Tidak ada"

print(SearchJadwal("sen", 12, 14))
print(SearchJadwal("jum", 8, 16))