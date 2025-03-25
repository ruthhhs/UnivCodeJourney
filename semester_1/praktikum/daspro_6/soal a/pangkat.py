def pangkat(x, y) :
    if y == 0 :
        return 1
    else :
        return x * pangkat(x, y-1)
    
print(pangkat(3, 3))
print(pangkat(2, 5))