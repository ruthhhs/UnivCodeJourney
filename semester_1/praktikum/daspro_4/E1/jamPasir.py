def jam(j, m, s) :
    if 0 <= j <= 24 and 0 <= m <= 59 and 0 <= s <= 59 :
        return f"Jam: {j}, Menit: {m}, Detik: {s}"
    else :
        return "Waktu tidak valid"
    
print(jam(12,30,45))
print(jam(12,45,60))
