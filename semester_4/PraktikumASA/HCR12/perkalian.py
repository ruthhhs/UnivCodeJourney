# Ruth Septriana Sipangkar
# 24060124120024

a, b = list(map(int, input().split()))

def perkalian(a, b):
    if a == 0 or b == 0:
        return 0
    else:
        if b == 1 :
            return a
        else:
            c = perkalian(a, b//2)
            if b % 2 == 0:
                return c + c
            else :
                return c + perkalian(a, b//2 + 1)

print(perkalian(a, b))