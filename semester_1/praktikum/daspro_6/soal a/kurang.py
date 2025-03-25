def kurang (x, y) :
    if y == 0 :
        return x
    else :
        return 1 - kurang(x-1, y-1)
    
print (kurang(5, 2))