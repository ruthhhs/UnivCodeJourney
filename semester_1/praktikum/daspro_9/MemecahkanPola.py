# Nama File: MemecahkanPola.py
# Pembuat: Ruth Septriana Sipangkar 24060124120024
# Tanggal: 15/11/2024
# Deskripsi: Menghapus elemen dan list di S yang sepola dengan x

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
def SumLoL (lol) :
    if IsEmptyLoL(lol) :
        return 0
    elif IsList(FirstList(lol)) :
        return SumLoL((FirstList(lol))) + SumLoL(TailList(lol))
    elif IsAtom(FirstList(lol)) :
        return FirstList(lol) + SumLoL(TailList(lol))
    else :
        return 0


def MemecahkanPola (x, S) :
    if IsEmptyLoL(S) :
        return []
    elif IsList(FirstList(S)) :
        if SumLoL(FirstList(S)) % x == 0 :
            return MemecahkanPola(x, TailList(S))
        else :
            return KonsoLoL(MemecahkanPola(x, FirstList(S)), MemecahkanPola(x, TailList(S)))
    else :
        if FirstList(S) == 0 :
            return KonsoLoL(0, MemecahkanPola(x, TailList(S)))
        elif FirstList(S) % x == 0 :
            return MemecahkanPola(x, TailList(S))
        else :
            return KonsoLoL(FirstList(S), MemecahkanPola(x, TailList(S)))

print(MemecahkanPola(3, [1, 2, 3, 4, [3, 6], 5, [2, 3]]))
print(MemecahkanPola(3, [3,6,9,[3,6,[12,15]]]))
print(MemecahkanPola(3, [1,2,3,[4,5,7,[10]]]))

print(MemecahkanPola(2, [1, 2, 3, 4, [3, 6], 5, [2, 3]]))
print(MemecahkanPola(2, [3,6,9,[3,6,[12,15]]]))
print(MemecahkanPola(2, [1,2,3,[4,5,7,[10]]]))

print(MemecahkanPola(2, [[], 0, 3, [[], 3], 2, [4, [5, 5], [], 4, 6]]))

print(MemecahkanPola(2, [1, 2, [3, 4, [5]], [2, 4], [7, 4, [4, [6, 6]]], 4]))

# APLIKASI
# import ast
# print(MemecahkanPola(ast.literal_eval(input()), ast.literal_eval(input())))
