def bagi (x, y) :
    if x == 0 :
        return 0
    else :
        return 1 + bagi(x-y, y)
    
print (bagi(9, 3))