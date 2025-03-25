def deretP2 (n) :
    if n == 1 :
        return 1
    else :
        return n**2 + deretP2(n-1)
    
print(deretP2(3))
print(deretP2(4))