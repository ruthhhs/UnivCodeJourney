def air(x) :
    if x<=0 :
        return "es"
    elif x>=100 :
        return "uap"
    elif x<100 and x>0 :
        return "cair"
    
print (air(50))
print (air(-50))
print (air(150))