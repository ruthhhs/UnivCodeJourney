// ================================================================================
// Nama Program: pohon1.c
// Deskripsi   : ADT bintree berkait dengan representasi fisik pointer
// NIM/Nama    : 24060124120024/Ruth Septriana Sipangkar
// Tanggal     : 27 November 2025
// ================================================================================
#include "pohon1.h"

bintree AlokasiTree(infotype E) {
    //kamus lokal
    bintree P;
    //algoritma
    P = (bintree)malloc(sizeof(node));
    if (P != NIL) {
        info(P) = E;
        left(P) = NIL;
        right(P) = NIL;
    }
    return P;
}

void DealokasiTree (bintree *P){
    // kamus

    // algoritma
    if (P != NIL){
        free(P);
        P = NIL;
    }
}

void PrintPrefix(bintree P) {
    //kamus lokal
    
    //algoritma 
    if (P == NIL) {
        printf("()");
    } else {
        printf("%c(",info(P));
        PrintPrefix(left(P));
        printf(",");
        PrintPrefix(right(P));
        printf(")");
    }
}

bintree Tree (infotype akar, bintree left, bintree right) {
    //kamus lokal
    bintree P;
    //algoritma
    P = AlokasiTree(akar);
    if (P != NIL) {
        left(P) = left;
        right(P) = right;
    }
    return P;
}

bintree GetLeft(bintree P){
    return left(P);
}

bintree GetRight(bintree P){
    return right(P);
}

boolean IsEmptyTree (bintree P){
    return P == NIL;
}

boolean IsDaun(bintree P){
    if (!IsEmptyTree(P)){
        return left(P) == NIL && right(P) == NIL;
    } else { // Pohon kosong
        return false;
    }
}

boolean IsBiner(bintree P){
    if (!IsEmptyTree(P)){
        return left(P) != NIL && right(P) != NIL;
    } else { // Pohon kosong
        return false;
    }
}

boolean IsUnerLeft(bintree P){
    if (!IsEmptyTree(P)){
        return left(P) != NIL && right(P) == NIL;
    } else { // Pohon kosong
        return false;
    }
}

boolean IsUnerRight(bintree P){
    if (!IsEmptyTree(P)){
        return left(P) == NIL && right(P) != NIL;
    } else { // Pohon kosong
        return false;
    }
}

int NbElm(bintree P){
    if (IsEmptyTree(P)){
        return 0; 
    } else { // Pohon tidak kosong
        return 1 + NbElm(left(P)) + NbElm(right(P));
    }
}

int NbDaun(bintree P){
    if (IsEmptyTree(P)){
        return 0; 
    } else { // Pohon tidak kosong
        if (IsDaun(P)){
            return 1;
        } else { // bukan daun
            return NbDaun(left(P)) + NbDaun(right(P));
        }
    }
}

int max2(int a, int b){
    if (a>b){
        return a;
    } else { // a<b
        return b;
    }
}

int Tinggi(bintree P){
    if (IsEmptyTree(P) || IsDaun(P)){
        return 0;
    } else { // tinggi >= 1
        return 1 + max2(Tinggi(left(P)), Tinggi(right(P)));
    }
}

boolean SearchX(bintree P, infotype X){
    if (IsEmptyTree(P)){
        return false;
    } else { // pohon tidak kosong
        if(info(P)==X){
            return true;
        } else{ // X belum ketemu
            return SearchX(left(P), X) || SearchX(right(P), X);
        }
    }
}

void UpdateX(bintree *P, infotype X, infotype Y){
    if(!IsEmptyTree(*P)){
        if(info(*P)==X){
            info(*P) = Y;
        } else{ // X belum ketemu
            UpdateX(&left(*P), X, Y);
            UpdateX(&right(*P), X, Y);
        }
    }
}

// ==================================================
int CountX(bintree P, infotype X){
    if (IsEmptyTree(P)){
        return 0;
    } else { // pohon tidak kosong
        if(info(P)==X){
            return 1 + CountX(left(P), X) + CountX(right(P), X);
        } else{ // akar bukan X
            return CountX(left(P), X) + CountX(right(P), X);
        }
    }
}

boolean IsSkewLeft (bintree P){
    if (IsEmptyTree(P)){
        return true;
    } else { // pohon ada isi
        if (IsUnerLeft(P)){
            return true;
        } else { // mengecek cabang kanan
            return IsEmptyTree(right(P)) && IsSkewLeft(left(P));
        }
    }
}

boolean IsSkewRight (bintree P){
    if (IsEmptyTree(P)){
        return true;
    } else { // pohon ada isi
        if (IsUnerRight(P)){
            return true;
        } else { // mengecek cabang kiri
            return IsEmptyTree(left(P)) && IsSkewRight(left(P));
        }
    }
}

void PrintPrefixRingkas(bintree P){
    if (P == NIL) {
        printf("");
    } else {
        printf("%c(",info(P));
        PrintPrefixRingkas(left(P));
        printf(",");
        PrintPrefixRingkas(right(P));
        printf(")");
    }
}

int LevelX(bintree P, infotype X){
    if(IsEmptyTree(P)){
        return 0;
    } else { // ga kosong
        if (info(P)==X){
            return 1;
        } else{ // cari X yang bukan akar
            if(LevelX(left(P), X) != 0){
                return 1 + LevelX(left(P), X);
            } else if(LevelX(right(P), X) != 0){
                return 1 + LevelX(right(P), X);
            } else{
                return 0;
            }
        }
    }
}

int CountLevel(bintree P, int T){
    if (IsEmptyTree(P)){
        return 0;
    } else{
        if (T==1){ // akar
            return T;
        } else { // bukan akar
            return CountLevel(left(P), T-1) + CountLevel(right(P), T-1);
        }
    }
}

void PrintLevel(bintree P, int N){
    if (!IsEmptyTree(P)){
        if (N==1){ // akar
            printf(" %c", info(P));
        }
        // print lainnya
        PrintLevel(left(P), N-1);
        PrintLevel(right(P), N-1);
    }
}

infotype GetDaunTerkiri(bintree P){
    if(IsEmptyTree(P)){
        return '#';
    } else{ // ada isi
        if(IsDaun(P)){ // ketemu
            return info(P);
        } else{ //cari
            if (!IsEmptyTree(left(P))){ // cari di kiri
                return GetDaunTerkiri(left(P));
            } else{ // cari di kanan
                return GetDaunTerkiri(right(P));
            }
        }
    }
}

float FrekuensiX(bintree P, infotype X){
    return (float) CountX(P, X) / NbElm(P);
}

int CountVocal(bintree P){
    if (IsEmptyTree(P)){
        return 0;
    } else{
        if (info(P)=='A' || info(P)=='E' || info(P)=='I' || info(P)=='O' || info(P)=='U'){
            return 1 + CountVocal(left(P)) + CountVocal(right(P));
        } else {
            return CountVocal(left(P)) + CountVocal(right(P));
        }
    }
}

void PrintVocal(bintree P){
    if (!IsEmptyTree(P)){
        if (info(P)=='A' || info(P)=='E' || info(P)=='I' || info(P)=='O' || info(P)=='U'){
            printf(" %c", info(P));
        }
        // print lainnya
        PrintVocal(left(P));
        PrintVocal(right(P));
    }
}

int CountConsonant(bintree P){
    if (IsEmptyTree(P)){
        return 0;
    } else{
        if (info(P)!='A' && info(P)!='E' && info(P)!='I' && info(P)!='O' && info(P)!='U'){
            return 1 + CountConsonant(left(P)) + CountConsonant(right(P));
        } else {
            return CountConsonant(left(P)) + CountConsonant(right(P));
        }
    }
}

void PrintConsonant(bintree P){
    if (!IsEmptyTree(P)){
        if (info(P)!='A' && info(P)!='E' && info(P)!='I' && info(P)!='O' && info(P)!='U'){
            printf(" %c", info(P));
        }
        // print lainnya
        PrintConsonant(left(P));
        PrintConsonant(right(P));
    }
}

char Modus(bintree P);
