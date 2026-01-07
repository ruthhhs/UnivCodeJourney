// ================================================================================
// Nama Program: pohon2.c
// Deskripsi   : ADT bintree berkait dengan representasi fisik pointer
// NIM/Nama    : 24060124120024/Ruth Septriana Sipangkar
// Tanggal     : 4 Desember 2025
// ================================================================================
#include "pohon1.h"
#include "pohon2.h"

void PrintTreeInden(bintree P, int H ){
    // kamus
    int i;

    // algpritma
    if(!IsEmptyTree(P)){
        printf("%c", info(P));

        if(left(P) != NIL){
            printf("\n");
            for(i = 1; i<= H; i++){
                printf(" ");
            }
                PrintTreeInden(left(P), H*2);
        }

        if(right(P) != NIL){
            printf("\n");
            for(i = 1; i<= H; i++){
                printf(" ");
            }
                PrintTreeInden(right(P), H*2);
        }
    }
}

void PrintLevel(bintree P, int N); // sudah dikerjakan di modul pohon1.c
// void PrintLevel(bintree P, int N){
//     if (!IsEmptyTree(P)){
//         if (N==1){ // akar
//             printf(" %c", info(P));
//         }
//         // print lainnya
//         PrintLevel(left(P), N-1);
//         PrintLevel(right(P), N-1);
//     }
// }

void UpdateAllX(bintree *P, infotype X, infotype Y){
    // kamus

    // algoritma
    if(!IsEmptyTree(*P)){
        if(info(*P)==X){
            info(*P)=Y;
        } else { // cari x
            UpdateAllX(&left(*P), X, Y);
            UpdateAllX(&right(*P), X, Y);
        }
    }
}

void AddDaunTerkiri(bintree *P, infotype X){
    // kamus
    bintree A;

    // algoritma
    A = AlokasiTree(X);
    if(IsEmptyTree(*P)){
        *P = A;
    } else{ // not empty
        if (IsUnerRight(*P) || IsDaun(*P)){
            left(*P) = A;
        } else{ // cari di kiri
            AddDaunTerkiri(&left(*P), X);
        }
    }
}

void AddDaun(bintree P, infotype X, infotype Y, boolean Kiri){
    // kamus
    bintree A;

    // algoritma
    A = AlokasiTree(Y);
    if(!IsEmptyTree(P)){
        if(info(P)==X){
            if(Kiri){
                left(P) = A;
            } else{ // kanan
                right(P) = A;
            }
        } else{ // cari X
            if(!IsDaun(P)){
                if(SearchX(left(P), X)){
                    AddDaun(left(P), X, Y, Kiri);
                } else { // x di kanan
                    AddDaun(right(P), X, Y, Kiri);
                }
            }
        }
    }
}

void DelDaunTerkiri(bintree *P, infotype *X){
    // kamus

    // alhgoritma
    if(!IsEmptyTree(*P)){
        if(IsDaun(*P)){
            *X = info(*P);
            DealokasiTree(P);
        } else { // cari daun X
            if(!IsEmptyTree(left(*P))){ // X di kiri
                DelDaunTerkiri(&left(*P), X);
            } else { // X di kanan
                DelDaunTerkiri(&right(*P), X);
            }
        }
    }
}

void DelDaun(bintree *P, infotype X){
    // kamus

    // algoritma
    if(!IsEmptyTree(*P)){
        if(IsDaun(*P) && info(*P)==X){
            X = info(*P);
            DealokasiTree(P);
        }
        else{ // cari x
            if(SearchX(left(*P), X)){
                DelDaun(&left(*P), X);
            } else { // x di kanan
                DelDaun(&right(*P), X);
            }
        }
    }
}

void InsertX(bintree *P, infotype X){
    // asumsi : menambahkan X ke daun paling kiri jika belum ada di P

    // kamus
    bintree A;

    // algoritma
    A = AlokasiTree(X);
    if(IsEmptyTree(*P)){
        *P = A;
    } else{ // not empty
        if(!(SearchX(*P, X))){ // kalau ga ada x
            if (IsUnerRight(*P) || IsDaun(*P)){
                left(*P) = A;
            } else{ // cari di kiri
                AddDaunTerkiri(&left(*P), X);
            }
        }
    }
}

void DeleteX(bintree *P, infotype X){
    // asumsi : kalau daun, langsung hapus
    //          kalau bukan daun, simpul dibawahnya naik, prioritas yang di kiri (kalau 2 anak)

    // kamus
    bintree temp, leftChild, rightChild, rm;

    // alhgoritma
    if(!IsEmptyTree(*P)){
        // ketemu x
        if(info(*P)==X){
            temp = *P;      // posisi x saat ini

            if(IsDaun(*P)){      // daun
                *P = NIL;
            }
            else if(IsEmptyTree(left(*P))){ // 1 anak (kanan)
                *P = right(*P);             // kanan naik
            }
            else if(IsEmptyTree(right(*P))){ // 1 anak (kiri)
                *P =  left(*P);             // kiri naik
            }
            else{                // 2 anak
                leftChild = left(*P);       // simpan anak
                rightChild = right(*P);
                *P = leftChild;            // kiri naik

                // cari rightmost dari anak kiri
                rm = *P;
                while (right(rm) != NIL) {
                    rm = right(rm);
                }
                // tempelkan anak kanan ke rightmost kiri
                right(rm) = rightChild;
            }
            DealokasiTree(&temp);
            return;                 // 1 x aja yang dihapus
        }

        // cari posisi x
        DeleteX(&left(*P), X);
        DeleteX(&right(*P), X);
    }
}

// Tambahan ================================
bintree BuildBalanceTree(int n){
    // kamus
    infotype x;
    bintree P;
    int nl, nr;

    // algoritma
    if(n==0){
        return NIL;
    }
    else{ // n > 0
        scanf(" %c", &x);
        P = AlokasiTree(x);

        if(!IsEmptyTree(P)){
            nl = n / 2;
            nr = n - nl - 1;
            left(P) = BuildBalanceTree(nl);
            right(P) = BuildBalanceTree(nr);
            return P;
        }
    }
}

boolean IsBalanceTree(bintree P){
    if(IsEmptyTree(P)){
        return false;
    } else{ // ga kosong
        if(IsDaun(P)){ // one elememt
            return true;
        }
        return NbElm(left(P)) == NbElm(right(P));
    }
}

int maxTree(bintree P){
    // kamus
    infotype maxV;

    // algoritma
    if(!IsEmptyTree(P)){
        maxV = info(P);

        if(!IsEmptyTree(left(P))){
            if(maxV < maxTree(left(P))){
                maxV = maxTree(left(P));
            }
        }
        if(!IsEmptyTree(right(P))){
            if(maxV < maxTree(right(P))){
                maxV = maxTree(right(P));
            }
        }
    }
    return maxV;
}

int minTree(bintree P){
    // kamus
    infotype minV;

    // algoritma
    if(!IsEmptyTree(P)){
        minV = info(P);

        if(!IsEmptyTree(left(P))){
            if(minV > minTree(left(P))){
                minV = minTree(left(P));
            }
        }
        if(!IsEmptyTree(right(P))){
            if(minV > minTree(right(P))){
                minV = minTree(right(P));
            }
        }
    }
    return minV;
}

// BST =================== 
boolean BSearch(bintree P, infotype X){
    // kamus

    // algoritma
    if(IsEmptyTree(P)){
        return false;
    } else{ // cari x
        if(info(P)==X){
            return true;
        }
        else{ // banyak elemen
            if(X < info(P)){ // x di kiri akar
                return (BSearch(left(P), X));
            } else{ // x di kanan akar
                return (BSearch(right(P), X));
            }
        }
    }
}

bintree InsSearch(bintree P, infotype X){
    // kamus

    // algoritma
    if(IsEmptyTree(P)){ // kosong, langsung tambah
        return AlokasiTree(X);
    }

    // cari ke kiri dan kanan
    if(info(P) > X){ // kiri
        left(P) = InsSearch(left(P), X);
    }
    else if (info(P) < X) { // kanan
        right(P) = InsSearch(right(P), X);
    }
    // kalau p == t ga lakukan apa apa

    return P;
}

void DelBtree(bintree *P, infotype X){
    // kamus
    bintree Temp;

    // algoritma
    if(!IsEmptyTree(*P)){
        if(IsDaun(*P) && info(*P) == X){
            DealokasiTree(P);
            *P = NULL;
        }
        else{ // cari x
            if(info(*P) > X){ //kiri
                DelBtree(&left(*P), X);
            }
            else if(info(*P) < X){ // kanan
                DelBtree(&right(*P), X);
            }

            else { // x ketemu
                if (IsDaun(*P)) {
                    DealokasiTree(P);
                    *P = NULL;
                }
                else if (left(*P) == NULL) { // punya anak kanan aja
                    Temp = *P;
                    *P = right(*P);
                    DealokasiTree(&Temp);
                }
                else if (right(*P) == NULL) { // punya anak kiri aja
                    Temp = *P;
                    *P = left(*P);
                    DealokasiTree(&Temp);
                }
                else { // dua anak
                    info(*P) = maxTree(left(*P));
                    DelBtree(&left(*P), info(*P));
                }
            }
        }
    } else { // p kosong
        return;
    }
}
