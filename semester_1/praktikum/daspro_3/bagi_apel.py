def bagiApel(n) :
    if n%2 == 0 and n != 0  and n > 0 and n != 2:
        return "bisa"
    else :
        return "tidak"
    
print (bagiApel(8))
print (bagiApel(5))
print (bagiApel(0))
print (bagiApel(30))
print (bagiApel(100))
print (bagiApel(1))
print (bagiApel(2))
print (bagiApel(-10))