def Determine(a):
    if a > 0 :
        if a == 2 :
            return "Ya"
        elif a % 2 == 0 or a % 3 == 0 or a % 5 == 0 or a % 7 == 0:
            return "Tidak"
        else:
            return "Ya"

print(Determine(3))
print(Determine(4))