def PecorineEat2(T, S) :
    if S == 7 :
        if T == S : return "Niku"
        elif T == (S + 1) or T == 1 : return "Puding"
        elif T <= 15 : return "Gohan"
        else : return "Pan"
    else :
        if (T % 7) == S : return "Niku"
        elif (T % 7) == (S + 1) : return "Puding"
        elif T <= (S + 13) : return "Gohan"
        else : return "Pan"

print(PecorineEat2(11, 4))
print(PecorineEat2(12, 4))
print(PecorineEat2(13, 4))
print(PecorineEat2(20, 4))
print(PecorineEat2(3, 4))
print(PecorineEat2(8, 4))
print(PecorineEat2(19, 4))
print(PecorineEat2(1, 4))
print(PecorineEat2(2, 1))
print(PecorineEat2(1, 2))
print(PecorineEat2(1, 1))
print(PecorineEat2(3, 1))
print(PecorineEat2(7, 7))
print(PecorineEat2(1, 7))
print(PecorineEat2(2, 7))


