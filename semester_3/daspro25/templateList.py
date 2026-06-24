#==========================================================================================
#Konstruktor

def konso(e, L):
    return [e] + L

def konsi(L, e):
    return L + [e]

#==============================================================================
# Selektor
def firstElmt(L):
    return L[0]

def lastElmt(L):
    return L[-1]

def head(L):
    return L[:-1]

def tail(L):
    return L[1:]

#=============================================================================
# Predikat

def isEmpty(L):
    return L == []

def isOneElmt(L):
    return len(L) == 1

def isMember(e, L) :
    if isEmpty(L) :
        return False
    elif e == firstElmt(L) :
        return True
    else :
        return isMember(e, tail(L))


#============================================================================
# operator

def nbElemen (L) :
    if isEmpty(L) :
        return 0
    else : 
        return 1 + nbElemen(tail(L))

def elemenkeN(N, L) :
    if isEmpty(L) :
        return 0
    elif N == 1 :
        return firstElmt(L)
    else :
        return elemenkeN(N-1, tail(L))

def konkat (L1, L2) :
    if isEmpty(L1) :
        return L2
    else :
        return konso(firstElmt(L1), konkat(tail(L1), L2))

#=======================================================================================

# def FirstList(L):
#     return L[0]
# def LastList(L):
#     return L[-1]
# def HeadList(L):
#     return L[:-1]
# def TailList(L):
#     return L[1:]
# def IsAtom(S):
#     return type(S) != list
# def IsList(S):
#     return type(S) == list
# def konso2 (a, b) :
#     return[a]+[b]
# def konkat (L1, L2) :
#     if IsTreeEmpty(L1) :
#         return L2
#     else :
#         return konso2(FirstList(L1), konkat(TailList(L1), L2))