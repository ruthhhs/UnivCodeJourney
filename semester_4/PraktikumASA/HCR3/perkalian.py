# Ruth Septriana Sipangkar
# 24060124120024

def perkalian(a, b):
    if a == 0 or b == 0:
        return 0
    else:
        if b == 1 :
            return a
        else:
            if b % 2 == 0:
                return perkalian(a, b//2) + perkalian(a, b//2)
            else :
                return perkalian(a, b//2) + perkalian(a, b//2 + 1)

a, b = list(map(int, input().split()))
print(perkalian(a, b))