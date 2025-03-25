#NAMA: Ruth Septriana Sipangkar 
#NIM : 24060124120024
oper = input('pilih jenis operasi (+, -, *, /, ^, //, %): ')
print('masukkan 2 angka : ')
a = int(input(': '))
b = int(input(': '))

def kalkulator() :
    if oper == '+' :
        return a + b
    elif oper == '-' :
       return a - b
    elif oper == '*' :
        return a * b
    elif oper == '^' :
        return a ** b
    elif oper == '/' :
        if b == 0 :
            return "cannot be operated"
        else :
            return a / b
    elif oper == '//' :
        if b == 0 :
            return "cannot be operated"
        else :
            return a // b
    elif oper == '%' :
        if b == 0 :
            return "cannot be operated"
        else :
            return a % b
        
print(kalkulator())
# print(eval(input()))