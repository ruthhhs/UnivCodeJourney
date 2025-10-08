def SearchJadwal(hari, mulai, akhir):
    if hari == "sen":
        if not (akhir <= 13 or mulai >= 15):
            return "Dasar Pemrograman"
        else:
            return "Tidak ada"

    elif hari == "sel":
        if not (akhir <= 13 or mulai >= 15):
            return "Aljabar Linier"
        else:
            return "Tidak ada"

    elif hari == "rab":
        if not (akhir <= 7 or mulai >= 10) and not (akhir <= 15 or mulai >= 16):
            return "Dasar Sistem & Bahasa Inggris I"
        elif not (akhir <= 7 or mulai >= 10):
            return "Dasar Sistem"
        elif not (akhir <= 15 or mulai >= 16):
            return "Bahasa Inggris I"
        else:
            return "Tidak ada"

    elif hari == "kam":
        if not (akhir <= 7 or mulai >= 9) and not (akhir <= 13 or mulai >= 15):
            return "Pancasila & Matematika I"
        elif not (akhir <= 7 or mulai >= 9):
            return "Pancasila"
        elif not (akhir <= 13 or mulai >= 15):
            return "Matematika I"
        else:
            return "Tidak ada"

    elif hari == "jum":
        if not (akhir <= 7 or mulai >= 9) and not (akhir <= 13 or mulai >= 16):
            return "Bahasa Indonesia & Struktur Diskrit"
        elif not (akhir <= 7 or mulai >= 9):
            return "Bahasa Indonesia"
        elif not (akhir <= 13 or mulai >= 16):
            return "Struktur Diskrit"
        else:
            return "Tidak ada"

    else:
        return "Tidak ada"

print(SearchJadwal("sen", 12, 14))
print(SearchJadwal("jum", 8, 16))