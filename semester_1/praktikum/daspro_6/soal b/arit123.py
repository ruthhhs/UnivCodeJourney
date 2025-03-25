def aritInt(n) :
    if n == 1 :
        return 1
    else :
        return n + aritInt(n-1)
    
print(aritInt(3))
print(aritInt(4))
print(aritInt(5))
