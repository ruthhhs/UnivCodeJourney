# Nama File: JalanBukit.py
# Pembuat: Ruth Septriana Sipangkar 24060124120024
# Tanggal: 17/11/2024
# Deskripsi: menentukan lokasi sebuah elemen di dalam list of list

# REALISASI
def IsEmptyLoL(S):
    return S == []

def IsOneElement(S):
    if IsEmptyLoL(S):
        return False
    else:
        return IsEmptyLoL(TailList(S))

def IsAtom(S):
    return type(S) != list

def IsList(S):
    return not IsAtom(S)

def KonsoLoL(L, S):
    return [L] + S

def KonsiLoL(S, L):
    return S + [L]

def FirstList(S):
    return S[0]

def LastList(S):
    return S[-1]

def HeadList(S):
    return S[:-1]

def TailList(S):
    return S[1:]

#========================================================================
def tambahSatu (x, y) :
    if x == y :
        return 0
    else :
        return 1 + tambahSatu(x, y-1)
    
print(tambahSatu(3, 3))

def JalanBukit(x, bukit) :
    if IsEmptyLoL(bukit) :
        return []
    else :
        if IsAtom(FirstList(bukit)) :
            if x == FirstList(bukit) :
                return [1]
            else :
                return KonsoLoL(1, JalanBukit(x, TailList(bukit)))

print(JalanBukit(5, [1, 2, 3, 4, 5]))



# APLIKASI
# import ast
# print(JalanBukit(ast.literal_eval(input()), ast.literal_eval(input())))