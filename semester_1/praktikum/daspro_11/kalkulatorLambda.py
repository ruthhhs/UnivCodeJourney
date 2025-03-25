#NAMA: Ruth Septriana Sipangkar 
#NIM : 24060124120024

def kalkulator(a, b, oper) :
    return oper(a, b)

print(kalkulator(2, 3, lambda x, y : x + y))
print(kalkulator(2, 3, lambda x, y : x - y))
print(kalkulator(2, 3, lambda x, y : x * y))
print(kalkulator(2, 3, lambda x, y : x / y))
print(kalkulator(2, 3, lambda x, y : x ** y))
print(kalkulator(2, 3, lambda x, y : x // y))
print(kalkulator(2, 3, lambda x, y : x % y))

# print(eval(input()))