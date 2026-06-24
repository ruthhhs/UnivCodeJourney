# Ruth Septriana Sipangkar
# 24060124120024

def fpb(a, b):
    if b == 0:
        return a
    else:
        return fpb(b, a % b)
    
def ronde(n, a, b):
    g = fpb(a, b)
    red = b//g
    green = a//g
    k = n//red

    apel = k * (red + green)
    return apel

def simulasi(n, a, b):
    apel = ronde(n, a, b)
    anew = fpb(a, b)
    bnew = a

    if fpb(a, b) != a:
        return apel + simulasi(n, anew, bnew)
    else:
        return apel

# input hcr
n, a, b = list(map(int, input().split()))
print(simulasi(n, a, b))

# test
# print(fpb(4, 6))
# print(ronde(6, 4, 6))
# print(simulasi(6, 4, 6))