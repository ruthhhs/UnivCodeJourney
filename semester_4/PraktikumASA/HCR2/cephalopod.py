# Ruth Septriana Sipangkar
# 24060124120024

def XY(arr):
    if len(arr) < 2:
        return False
    else:
        if arr[0] == "X" and arr[1] == "Y":
            return 1 + XY(arr[2:])
        else:
            return XY(arr[1:])
        
def cephalopod(arr):
    jumlah = XY(arr)
    if jumlah % 2 == 0 and jumlah >=2:
        return True
    else:
        return False

# hcr
print(cephalopod(input()))