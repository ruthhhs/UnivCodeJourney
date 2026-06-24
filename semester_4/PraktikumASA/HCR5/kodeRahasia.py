# Ruth Septriana Sipangkar
# 24060124120024

def rahasia(n, k, s):
    if n == 1:
        return s
    
    tengah = 2**(n - 1)
    huruf = chr(ord(s) + n - 1)

    if k == tengah :
        return huruf
    elif k < tengah :
        return rahasia(n-1, k, s)
    else :
        return rahasia(n-1, k-tengah, s)

# input
n, k = list(map(int, input().split()))
s = str(input())
print(rahasia(n, k, s))