def determinan(a, b, c) :
    return (b*b) - (4*a*c)

def x1(a, b, c) :
    return (-b + (determinan(a, b, c))**0.5) / (2*a)

def x2(a, b, c) :
    return (-b - (determinan(a, b, c))**0.5) / (2*a)

def Aljabar(a,b,c):
    if determinan(a, b, c) < 0:
        return -999 
    else:
        if x1(a, b, c) > x2(a, b, c):
            return round(x2(a, b, c) / x1(a, b, c), 5)
        else:
            return round(x1(a, b, c) / x2(a, b, c), 5)

print (Aljabar(2, 4, 5))
print(Aljabar(1, -5, 6))