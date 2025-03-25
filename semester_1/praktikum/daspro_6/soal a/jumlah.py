def jumlah (x, y) :
    if y == 0 :
        return x
    else :
        return 1 + jumlah(x, y-1)
    
print (jumlah(2, 3))