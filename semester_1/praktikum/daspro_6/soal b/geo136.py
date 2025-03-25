def geo3 (n) :
    if n == 1 :
        return 1
    else :
        return 3**(n-1) + geo3(n-1)
    
print(geo3(3))
print(geo3(4))