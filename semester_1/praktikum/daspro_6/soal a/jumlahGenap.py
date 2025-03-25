# menjumlahkan bilangan genap saja dari 1 sampai x

def jumGenap (x) :
    if x <= 1 :
        return 0
    elif x % 2 == 0 :
        return x + jumGenap(x-2)
    else :
        return x-1 + jumGenap(x-3)
    
print (jumGenap(10))
print (jumGenap(11))