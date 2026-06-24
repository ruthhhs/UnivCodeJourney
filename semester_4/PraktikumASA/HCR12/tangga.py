# Ruth Septriana Sipangkar
# 24060124120024

n = int(input())

def tangga(n):
    if n == 1:
        return 1
    else:
        if n > 2:
            return tangga(n-1) + tangga(n-2)
        else :
            return 1 + tangga(n-1)

print(tangga(n))