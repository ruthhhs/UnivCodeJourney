def arit3 (n) :
    if n == 1 :
        return 3
    else :
        return 3*n + arit3(n-1)
    
print(arit3(3))
print(arit3(4))