def faktorial(n):
    if n == 0 or n == 1:
        return 1
    else:
        return n * faktorial (n-1)

def add(a, b):
    if b == 0:
        return a
    elif b>0:
        return add(a+1, b-1)
    elif b<0:
        return add(a-1, b+1)
    
def min(a,b):
    if a>=0 and b>=0:
        if b == 0:
            return a
        else:
            return min(a-1,b-1)
    elif a >=0 and b <0:
        return min(a+1,b+1)
    elif a <=0 and b <=0:
        if b == 0:
            return a
        else:
            return min(a+1,b+1)

# print(min(5,3))
# print(min(5,-3))
# print(min(-3,-2))

def mul(a, b):
    if b == 0:
        return 0
    else:
        if b < 0:
            return -a + (mul(a,b+1))
        else:
            return a + (mul(a,b-1))

# print(mul(5,4))
# print(mul(5,-1))
# print(mul(5,-4))
# print(mul(-5,-4))

def dif(a, b):
    if b==0:
        return "gabisaaa"
    elif a<b:
        return 0
    else:
        return 1+dif(a-b,b)
print(dif(9,3))
print(dif(3,9))