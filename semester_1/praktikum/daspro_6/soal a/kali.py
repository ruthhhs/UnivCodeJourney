def kali (x, y) :
    if y == 1 :
        return x
    else : return x + kali (x, y-1)

print (kali(3, 2))
print (kali(5, 3))
print (kali(5, 2))