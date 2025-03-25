#NAMA: Ruth Septriana Sipangkar 
#NIM : 24060124120024

def kalkulator(a, b, oper) :
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
                

# print(eval(input()))