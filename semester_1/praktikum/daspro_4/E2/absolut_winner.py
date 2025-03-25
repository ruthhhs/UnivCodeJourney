#nama_file :  Absolute Winner
#pembuat : Ruth Septriana Sipangkar (24060124120024)

def poin(x) : return x % 4 == 0
def tertinggi (A, B, C) :
    if A > B and A > C : return 'A'
    elif B > A and B > C : return 'B'
    elif C > A and C > B : return 'C'
    else : return "Tidak ada"
def game(A, B, C) : return (A + B + C) % 7 == 0

def absolute_winner(A, B, C) :
    if A == B > C or B == C > A or C == A > B : return "Tidak ada"
    else : 
        if game (A, B, C) and tertinggi(A, B, C)== 'A' and poin(A) : return "Aero"
        elif game (A, B, C) and tertinggi(A, B, C)== 'B' and poin(B) : return "Bocchi"
        elif game (A, B, C) and tertinggi(A, B, C)== 'C' and poin(C) : return "Charles"
        else : return "Tidak ada"
        
print (absolute_winner(1, 2, 4))
print (absolute_winner(6, 6, 4))
print (absolute_winner(8, 4, 2))
print (absolute_winner(2, 4, 4))









