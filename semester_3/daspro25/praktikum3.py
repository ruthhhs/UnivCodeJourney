# def jam(x:int) -> str:
#     if (x > 12):
#         return x-12, "PM"
#     else :
#         return x, "AM"
    
# print(jam(4))

def jamInteger(x:int) -> str:
    if x > 12:
        return str(x%12)+" PM"
    elif x >=0:
        return str(x)+" AM"

# print(jamInteger(13))
# print(jamInteger(1))
# print(jamInteger(23))    

def h20(x:int) -> int:
    if x <= 0:
        return "Es"
    elif x > 0 and x < 100:
        return "Air" 
    elif x >= 100:
        return "Uap"
# print(h20(120))
# print(h20(-12))

def konversi(x:int,y:str) -> int:
    if y == 'R':
        return x * (4/5)
    elif y == 'F':
        return (x * (9/5)) + 32
    elif y == 'K':
        return x + 273
print(konversi(100,'R'))
print(konversi(100,'F'))
print(konversi(100,'K'))