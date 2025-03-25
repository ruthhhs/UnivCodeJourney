# Nama File: BrokenDivergence.py
# Pembuat: Ruth Septriana Sipangkar 24060124120024
# Tanggal: 17/11/2024
# Deskripsi: Membalik elemen dalam List of List
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
def konkat (L1, L2) :
    if IsEmptyLoL(L1) :
        return L2
    else :
        return KonsoLoL(FirstList(L1), konkat(TailList(L1), L2))

def bukaKurung(S) :
    if IsEmptyLoL(S) :
        return []
    else :
        if IsAtom(FirstList(S)) :
            return KonsoLoL(FirstList(S), bukaKurung(TailList(S)))
        else :
            return bukaKurung(KonsoLoL(FirstList(FirstList(S)), bukaKurung(konkat(TailList(FirstList(S)), TailList(S)))))

def InverseLoL(S) :
    if IsEmptyLoL(S) :
        return []
    else :
        if IsAtom(LastList(S)) :
            return KonsoLoL(LastList(S), InverseLoL(HeadList(S)))
        else :
            return KonsoLoL(InverseLoL(LastList(S)), InverseLoL(HeadList(S)))

def NBElmtAtom(S) :
    if IsEmptyLoL(S) :
        return 0
    else :
        if IsAtom(FirstList(S)) :
            return 1 + NBElmtAtom(TailList(S))
        else :
            return NBElmtAtom(FirstList(S)) + NBElmtAtom(TailList(S))

def kurangiAtom (x, L) :   
    if IsEmptyLoL(L) or x<=0:
        return L
    else :
        return kurangiAtom(x-1, TailList(L))
 
def BrokenDivergenceHelp (L, S) :
    if IsEmptyLoL(S) or IsEmptyLoL(L) :
        return []
    else:
        if IsAtom(FirstList(S)) :
            return KonsoLoL(FirstList(L), BrokenDivergenceHelp(TailList(L), TailList(S)))
        else :
            return KonsoLoL(BrokenDivergenceHelp(L, FirstList(S)), BrokenDivergenceHelp(kurangiAtom(NBElmtAtom(FirstList(S)), L), TailList(S)))

def BrokenDivergence (S) :
    return BrokenDivergenceHelp(InverseLoL(bukaKurung(S)), S)

print(BrokenDivergence([1, 2, [3, 2]]))
print(BrokenDivergence([1, 2, [3, 4], 5, [6]]))
print(BrokenDivergence([1, 0, [4, [8, 5], [9], 6]]))
print(BrokenDivergence([[1, 2], [3, 4], 5]))
print(BrokenDivergence([1, [2, [3, [4, 5]]], [2, 3], [4, [5]]]))
print(BrokenDivergence([1, 2, [3, 4, [5, 6], 7], 8, 9]))
print(BrokenDivergence([1, [2, [[3], [4]]], [5, 6]]))

# APLIKASI
# print(eval(input()))
