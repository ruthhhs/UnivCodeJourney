def max3(a:int, b:int, c: int) -> int:
    if a > b:
        if a > c:
            return a
        else:
            return b
    else:
        if b > c: 
            return b
        else:
            return c

print(max3(54,31,25))
print(max3(48,17,35))
print(max3(94,12,55))