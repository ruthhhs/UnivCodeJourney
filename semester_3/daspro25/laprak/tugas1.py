# Ruth Septriana Sipangkar
# 024

# 01 Mean Olympique
def max2(a:int, b:int) -> int:
    return(a+b + abs(a-b))/2
def min2(a:int, b:int) -> int:
    return(a+b - abs(a-b))//2
def max4(a:int, b:int, c:int, d:int) -> int:
    return max2(max2(a,b), max2(c,d))
def min4(a:int, b:int, c:int, d:int) -> int:
    return min2(min2(a,b), min2(c,d))
def MO(a:int, b:int, c:int, d:int) -> int:
    return (a+b+c+d - min4(a,b,c,d) - max4(a,b,c,d))//2
# jangan pakai max min bawaan python

# 02 Is Positif
def is_positif(a:int) -> bool:
    return a > 0
    # a >= 1
    # a >= 0

# 03 Is A
def is_A(a:str) -> bool:
    return a == 'A'

# 04 Is Valid (x<5 or x>500)
def is_valid(a:int) -> bool:
    # return a < 5 or a > 500
    # a < 5 and a > 500
    return 5 < a and a < 500

# 05 Least Squares
def fx2(x:float) -> float:
    return x*x
    # x**2
def dif2(x:float, y:float) -> float:
    return fx2(x-y)
def LS(x1:float, y1:float, x2:float, y2:float) -> float:
    return (dif2(y2, y1) + dif2(x2, x1)) ** 0.5
    # import math dihindari
    