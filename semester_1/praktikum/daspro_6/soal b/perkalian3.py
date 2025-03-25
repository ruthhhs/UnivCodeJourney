def kali3 (n) :
    if n==1 :
        return 3
    else :
        return 3 + kali3(n-1)
    
print(kali3(10))