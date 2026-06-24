# Ruth Septriana Sipangkar
# 24060124120024

def uangMinimum (n):
    # arrUang = [50, 25, 10, 5, 1]

    temp = n
    lembar = 0
    while temp > 0:
        if temp >= 50:
            lembar += 1
            temp -= 50
        elif temp >= 25:
            lembar += 1
            temp -= 25
        elif temp >= 10:
            lembar += 1
            temp -= 10
        elif temp >= 5:
            lembar += 1
            temp -= 5
        elif temp >= 1:
            lembar += 1
            temp -= 1
    
    return lembar

# hcr
# n = int(input())
# print(uangMinimum(n))

# test
print(uangMinimum(37))