def akar(x, y) :
    if x == 1 :
        return 0
    else :
        return 1 + akar(x/y, y)
    
print(akar(32, 2))
print(akar(27, 3))
print(akar(128, 2))