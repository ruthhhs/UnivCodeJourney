// ================================================================================
// Nama Program: pohon3.h
// Deskripsi   : ADT bintree3 dengan representasi fisik pointer
// NIM/Nama    : 24060124120024/Ruth Septriana Sipangkar
// Tanggal     : 11 Desember 2025
// ================================================================================
#include <stdio.h>
#include <stdlib.h>
#include "pohon3.h"

bintree3 Tree3 (bintree3 A, infotype X, boolean V, bintree3 kiri, bintree3 kanan){
    //kamus lokal
    bintree3 P;

    //algoritma
    P = (bintree3)malloc(sizeof(node3)); // alokasi
    if (P != NIL) {
        parent(P) = A;
        info(P) = X;
        visited(P) = V;
        left(P) = kiri;
        right(P) = kanan;
    }
    return P;
}

void printDFS (bintree3 P){
    //kamus lokal
    
    //algoritma 
    if (P == NIL) {
        printf("()");
    } else {
        printf("%c(",info(P));
        printDFS(left(P));
        printf(",");
        printDFS(right(P));
        printf(")");
    }
}

int Max2 (int a, int b){
    // kamus

    // algoritma
    if(a>b){
        return a;
    } else{
        return b;
    }
}

int Tinggi(bintree3 P){
    // kamus

    //algoritma
    if (IsEmptyTree(P) || IsDaun(P)){
        return 0;
    } else { // tinggi >= 1
        return 1 + Max2(Tinggi(left(P)), Tinggi(right(P)));
    }
}

void PrintLevel (bintree3 P, int N){
    if (!IsEmptyTree(P)){
        if (N==1){ // akar
            printf(" %c", info(P));
        }
        // print lainnya
        PrintLevel(left(P), N-1);
        PrintLevel(right(P), N-1);
    }
}

void PrintBFS (bintree3 P){
    // kamus
    List1 L;
    bintree3 X;

    // algoritma
    // if (!IsEmptyTree(P)){
    //     CreateList(&L);
    //     InsertVLast(&L, P); 

    //     while (!IsEmpty(L)) {
    //         DeleteVFirst(&L, &X);
    //         printf("%c ", info(X));
    
    //         if (left(X) != NIL)
    //             InsertVLast(&L, left(X));
    
    //         if (right(X) != NIL)
    //             InsertVLast(&L, right(X));
    //     }
    // }
}

boolean IsEmptyTree (bintree3 P){
    return P == NIL;
}

boolean IsDaun (bintree3 P){
    if (IsEmptyTree(P)){
        return false;
    } else { // ada isi
        return IsEmptyTree(left(P)) && IsEmptyTree(right(P));
    }
}

boolean IsBiner (bintree3 P){
    if (IsEmptyTree(P)){
        return false;
    } else { // ada isi
        return !IsEmptyTree(left(P)) && !IsEmptyTree(right(P));
    }
}

boolean IsUnerLeft (bintree3 P){
    if (IsEmptyTree(P)){
        return false;
    } else { // ada isi
        return IsEmptyTree(left(P)) && !IsEmptyTree(right(P));
    }
}

boolean IsUnerRight (bintree3 P){
    if (IsEmptyTree(P)){
        return false;
    } else { // ada isi
        return !IsEmptyTree(left(P)) && IsEmptyTree(right(P));
    }
}

// ===================

void resetVisited (bintree3 P){
    // kamus

    // algoritma
    if(!IsEmptyTree(P)){
        P->visited = false;         // reset akar
        resetVisited(left(P));      // reset kiri
        resetVisited(right(P));     // reset kanan
    }
}

// void printVisitedPath (bintree3 P){
//     if (IsEmptyTree(P)) return;

//     if (visited(P)) {
//         printf("%c ", info(P));
//         printVisitedPath(left(P));
//         printVisitedPath(right(P));
//     }
// }

void printPathX (bintree3 P, infotype X){
    // kamus

    //algoritma
    if(!IsEmptyTree(P) && !visited(P)){
        visited(P) = true;
        printf("%c ", info(P));

        if (info(P) == X) {
            printf("\n");
        } else {
            printPathX(left(P), X);
            printPathX(right(P), X);
        }

        visited(P) = false;
    }
}

void printPathDaunX (bintree3 P, infotype X){
    // kamus

    //algoritma
    if(!IsEmptyTree(P) && !visited(P)){
        visited(P) = true;
        printf("%c ", info(P));

        if (info(P) == X && left(P) == NIL && right(P) == NIL) {
            printf("\n");
        } else {
            printPathDaunX(left(P), X);
            printPathDaunX(right(P), X);
        }

        visited(P) = false; 
    }
}

void printAllPaths (bintree3 P){
    // kamus

    //algoritma
    if(!IsEmptyTree(P) && !visited(P)){
        visited(P) = true;
        printf("%c ", info(P));

        if (left(P) == NIL && right(P) == NIL) {
            printf("\n");
        } else {
            printAllPaths(left(P));
            printAllPaths(right(P));
        }

        visited(P) = false;
    }
}

int NbElmTree (bintree3 P){
    // kamus

    // algoritma
    if (IsEmptyTree(P)){
        return 0; 
    } else { // Pohon tidak kosong
        return 1 + NbElmTree(left(P)) + NbElmTree(right(P));
    }
}

int NbDaun (bintree3 P){
    // kamus

    // algoritma
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

int Level (bintree3 P){
    // kamus

    // algpritma
    if (IsEmptyTree(P)) {
        return 0;
    } else {
        if (Level(left(P)) > Level(right(P))){
            return Level(left(P)) + 1;
        } else {
            return Level(right(P)) + 1;
        }
    }
}

int CountLevelT (bintree3 P, int T){
    // kamus

    // algpritma
    if (IsEmptyTree(P)){
        return 0;
    } else{
        if (T==1){ // akar
            return T;
        } else { // bukan akar
            return CountLevelT(left(P), T-1) + CountLevelT(right(P), T-1);
        }
    }
}


