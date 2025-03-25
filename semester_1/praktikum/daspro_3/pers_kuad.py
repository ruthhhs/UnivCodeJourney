def determinan(a, b, c) :
    return (b*b) - (4*a*c)

def pers_kuad1(a, b, c) :
    return (-b + (determinan(a, b, c))**0.5) / (2*a)

def pers_kuad2(a, b, c) :
    return (-b - (determinan(a, b, c))**0.5) / (2*a)

def pembagian(a, b, c) :
    if pers_kuad1(a, b, c) > pers_kuad2(a, b, c) :
        return pers_kuad1(a, b, c) / pers_kuad2(a, b, c)
    else :
        return pers_kuad2(a, b, c) / pers_kuad1(a, b, c)
    
print (pembagian(1, -6, 9))
print(pembagian(1, -5, 6))