#Konstruktor
def konso(e, L):
    return [e] + L
def konsi(L, e):
    return L + [e]

# Selektor
def firstElmt(L):
    return L[0]
def lastElmt(L):
    return L[-1]
def head(L):
    return L[:-1]
def tail(L):
    return L[1:]
def IsAtom(S):
    return type(S) != list
def IsList(S):
    return type(S) == list

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
def FilterBilGen(L) :
    if isEmpty(L) :
        return []
    elif firstElmt(L) % 2 == 0 :
        return konso (firstElmt(L), FilterBilGen(tail(L)))
    else : 
        return FilterBilGen(tail(L))
    
# print(FilterBilGen([1,2,3,4,5,6,7,8,9,10]))
# print(FilterBilGen([2,3,7,11,13,17,19,23]))

def filterBilLambda(f, L) :
    if isEmpty(L) :
        return []
    elif f(firstElmt(L)) :
        return konso (firstElmt(L), filterBilLambda(f, tail(L)))
    else : 
        return filterBilLambda(f, tail(L))
    
# print(filterBilLambda(lambda x: x%2==0, [1,2,3,4,5,6,7,8,9,10]))
# print(filterBilLambda(lambda x: x%2==0, [2,3,7,11,13,17,19,23]))
# print(filterBilLambda(lambda x: x%3==0, [1,2,3,4,5,6,7,8,9,10]))
# print(filterBilLambda(lambda x: x%3==0, [2,3,7,11,13,17,19,23]))

def IsContaintList(L) :
    if isEmpty(L) :
        return []
    elif isOneElmt(L) and IsAtom(firstElmt(L)) :
        return False
    else :
        if IsList(firstElmt(L)) :
                return True
        else :
            return IsContaintList(tail(L))
    
# print(IsContaintList([1,2,3,4,[5,6],7,8]))
# print(IsContaintList([1,2,3,4,5,6,7,8]))

def makePN(A, PN):
    return [A, PN]
def Akar(T):
    return T[0]
def Anak(T):
    return T[1]

# DEFINISI DAN SPESIFIKASI SOAL NO 4
# SubListX: Tree NAry, Elemen --> list of Elemen
# SubListX mengembalikan list of elemen yang merupakan semua elemen yang berada di dalam tree yang memiliki akar X
def SubListXhelp1(P, X):
    if isEmpty(P) :
        return []
    elif Akar(P) == X :
            return P
    else :
        return SubListXhelp2(Anak(P), X)
    
def SubListXhelp2 (P, X) :
    if isEmpty(P) :
        return []
    else :
        return SubListXhelp1(firstElmt(P), X) + SubListXhelp2(tail(P), X)
    
def toList(S) :
    if isEmpty(S) :
        return []
    elif IsAtom(firstElmt(S)) :
        return konso(firstElmt(S), toList(tail(S)))
    else :
        return toList(firstElmt(S)) + toList(tail(S))
    
def SubListX(P, X) :
    return toList(SubListXhelp1(P, X))
        
# print(SubListX(makePN("Ridho",[makePN("Silvani",[makePN("Nuha",[]), makePN("Syahrafi",[makePN("Ega", [])]), makePN("Noci",[])]), makePN("Rendi",[makePN("Fikhrul",[])]), makePN("Ruth",[makePN("Aji",[])]), makePN("Eko",[makePN("Raffi",[])])]),"Ridho"))
# print(SubListX(makePN("Ridho",[makePN("Silvani",[makePN("Nuha",[]), makePN("Syahrafi",[makePN("Ega", [])]), makePN("Noci",[])]), makePN("Rendi",[makePN("Fikhrul",[])]), makePN("Ruth",[makePN("Aji",[])]), makePN("Eko",[makePN("Raffi",[])])]),"Silvani"))
# print(SubListX(makePN("Ridho",[makePN("Silvani",[makePN("Nuha",[]), makePN("Syahrafi",[makePN("Ega", [])]), makePN("Noci",[])]), makePN("Rendi",[makePN("Fikhrul",[])]), makePN("Ruth",[makePN("Aji",[])]), makePN("Eko",[makePN("Raffi",[])])]),"Nuha"))
# print(SubListX(makePN("Ridho",[makePN("Silvani",[makePN("Nuha",[]), makePN("Syahrafi",[makePN("Ega", [])]), makePN("Noci",[])]), makePN("Rendi",[makePN("Fikhrul",[])]), makePN("Ruth",[makePN("Aji",[])]), makePN("Eko",[makePN("Raffi",[])])]),"Syahrafi"))
# print(SubListX(makePN("Ridho",[makePN("Silvani",[makePN("Nuha",[]), makePN("Syahrafi",[makePN("Ega", [])]), makePN("Noci",[])]), makePN("Rendi",[makePN("Fikhrul",[])]), makePN("Ruth",[makePN("Aji",[])]), makePN("Eko",[makePN("Raffi",[])])]),"Ega"))
# print(SubListX(makePN("Ridho",[makePN("Silvani",[makePN("Nuha",[]), makePN("Syahrafi",[makePN("Ega", [])]), makePN("Noci",[])]), makePN("Rendi",[makePN("Fikhrul",[])]), makePN("Ruth",[makePN("Aji",[])]), makePN("Eko",[makePN("Raffi",[])])]),"Noci"))
# print(SubListX(makePN("Ridho",[makePN("Silvani",[makePN("Nuha",[]), makePN("Syahrafi",[makePN("Ega", [])]), makePN("Noci",[])]), makePN("Rendi",[makePN("Fikhrul",[])]), makePN("Ruth",[makePN("Aji",[])]), makePN("Eko",[makePN("Raffi",[])])]),"Rendi"))
# print(SubListX(makePN("Ridho",[makePN("Silvani",[makePN("Nuha",[]), makePN("Syahrafi",[makePN("Ega", [])]), makePN("Noci",[])]), makePN("Rendi",[makePN("Fikhrul",[])]), makePN("Ruth",[makePN("Aji",[])]), makePN("Eko",[makePN("Raffi",[])])]),"Fikhrul"))
# print(SubListX(makePN("Ridho",[makePN("Silvani",[makePN("Nuha",[]), makePN("Syahrafi",[makePN("Ega", [])]), makePN("Noci",[])]), makePN("Rendi",[makePN("Fikhrul",[])]), makePN("Ruth",[makePN("Aji",[])]), makePN("Eko",[makePN("Raffi",[])])]),"Ruth"))
# print(SubListX(makePN("Ridho",[makePN("Silvani",[makePN("Nuha",[]), makePN("Syahrafi",[makePN("Ega", [])]), makePN("Noci",[])]), makePN("Rendi",[makePN("Fikhrul",[])]), makePN("Ruth",[makePN("Aji",[])]), makePN("Eko",[makePN("Raffi",[])])]),"Aji"))
# print(SubListX(makePN("Ridho",[makePN("Silvani",[makePN("Nuha",[]), makePN("Syahrafi",[makePN("Ega", [])]), makePN("Noci",[])]), makePN("Rendi",[makePN("Fikhrul",[])]), makePN("Ruth",[makePN("Aji",[])]), makePN("Eko",[makePN("Raffi",[])])]),"Eko"))
# print(SubListX(makePN("Ridho",[makePN("Silvani",[makePN("Nuha",[]), makePN("Syahrafi",[makePN("Ega", [])]), makePN("Noci",[])]), makePN("Rendi",[makePN("Fikhrul",[])]), makePN("Ruth",[makePN("Aji",[])]), makePN("Eko",[makePN("Raffi",[])])]),"Raffi"))

def MakePB(A, L, R):
    return [A, L, R]
def Akar(P):
    return P[0]
def Left(P):
    return P[1]
def Left(P):
    return P[1]
def Right(P):
    return P[2]

def isOneElmtPB (P) :
    return isEmpty(Right(P)) and isEmpty(Left(P))
def IsExistRight(P):
    return not isEmpty(Right(P))

# DEFINISI DAN SPESIFIKASI SOAL NO 5
# IsMaxMod4: lambda, Binary Tree --> boolean
# IsMaxMod4 mengembalikan True jika elemen terbesar dari tree habis dibagi 4
def IsMaxMod4(f, P):
    if isEmpty(P) :
        return False
    elif isOneElmtPB(P) :
        return f(Akar(P))
    else :
        return IsMaxMod4(f, Right(P))
    
# print(IsMaxMod4(lambda x: x % 4 == 0, MakePB(40, [], [])))
# print(IsMaxMod4(lambda x: x % 4 == 0,(MakePB(50, MakePB(35, [], []), MakePB(75, MakePB(60, [], []), MakePB(100, [], MakePB(120, [], [])))))))
# print(IsMaxMod4(lambda x: x % 4 == 0,(MakePB(50, MakePB(35, [], []), MakePB(75, MakePB(60, [], []), MakePB(100, [], MakePB(120, [], MakePB(121, [], []))))))))

# APLIKASI
# import sys
# exec(''.join(sys.stdin.readlines()))