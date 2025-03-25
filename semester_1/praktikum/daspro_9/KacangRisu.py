# Nama File: KacangRisu.py
# Pembuat: Ruth Septriana Sipangkar 24060124120024
# Tanggal: 12/11/2024
# Deskripsi: Mengembalikan list of list berisi posisi kacang jika belum penuh, jika penuh mengembalikan "Mending Pulang"

# DEFINISI DAN SPESIFIKASI
# KacangRisu --> list, list of list: list of list / string
# KacangRisu(L, S) mengembalikan list of list berisi posisi kacang jika belum penuh, jika penuh mengembalikan "Mending Pulang"

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
def nbElmt (L) :
    if IsEmptyLoL(L) :
        return 0
    else : 
        return 1 + nbElmt(TailList(L))
    
def jlhListKosong(S) :
    if IsEmptyLoL(S) :
        return 0
    elif IsAtom(FirstList(S)) :
        return jlhListKosong(TailList(S))
    else :
        if IsEmptyLoL(FirstList(S)) :
            return 1 + jlhListKosong(TailList(S))
        else :
            return jlhListKosong(TailList(S))

# print(nbElmt([1, 2, 3, [4], [5, 6], 7]))
# print(jlhListKosong([1, [2, 3], [], [2], [], 3]))

def KacangRisu(L, S) :
    if IsEmptyLoL(L) :
        return S
    elif (nbElmt(L)-2) > jlhListKosong(S) :
        return "Mending Pulang"
    else :
        if IsEmptyLoL(S) :
            return []
        else :
            if IsEmptyLoL(FirstList(S)) :
                return KonsoLoL([FirstList(L)], KacangRisu(TailList(L), TailList(S)))
            else :
                return KonsoLoL(FirstList(S), KacangRisu(L, TailList(S)))

print(KacangRisu([1,2,3,4,5,6], [[],[4,5,6],[],[4,9],[]]))
print(KacangRisu([1,2,3,4,5], [[],[4,5,6],[],[4,9],[]]))
print(KacangRisu([1,2,3,4], [[],[4,5,6],[],[4,9],[]]))
print(KacangRisu([1,2,3], [[],[4,5,6],[],[4,9],[]]))
print(KacangRisu([1,2], [[],[4,5,6],[],[4,9],[]]))
print(KacangRisu([1], [[],[4,5,6],[],[4,9],[]]))
print(KacangRisu([], [[],[4,5,6],[],[4,9],[]]))   

# APLIKASI
# import ast
# print(KacangRisu(ast.literal_eval(input()), ast.literal_eval(input())))