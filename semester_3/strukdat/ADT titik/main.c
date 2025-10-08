// ======================================================
// Nama Program: maintitik.c
// Deskripsi   : realisasi body modul Titik
// NIM/Nama    : 24060124120024/Ruth Septriana Sipangkar
// Tanggal     : 4 Sept 2025
// ======================================================
#include <stdio.h>
#include "titik.h"
#include "titik.c"
#include <stdbool.h>

int main(){
    // Kamus main
    Titik T1, T2, Tx;

    // Algpritma
    printf("BUAT TITIK\n");
    makeTitik(&T1,2,3);
    makeTitik(&T2,2,2);
    printf("Titik 1 : (%d, %d)\n", getAbsis(T1), getOrdinat(T1));
    printf("Titik 2 : (%d, %d)\n", getAbsis(T2), getOrdinat(T2));

    printf("\nMUTATOR\n");
    setAbsis(&T1, 0);
    setOrdinat(&T2, 0);
    printf("Titik 1 : (%d, %d)\n", getAbsis(T1), getOrdinat(T1));
    printf("Titik 2 : (%d, %d)\n", getAbsis(T2), getOrdinat(T2));

    printf("\nPREDIKAT\n");
    printf("// 0 = false, 1 = true\n");
    printf("isOrigin T1: %d\n", isOrigin(T1)) ? "True": "False";
    printf("isOnSumbuX T2: %d\n", isOnSumbuX(T2));
    printf("isOnSumbuY T1: %d\n", isOnSumbuY(T1));
    printf("isEqual T1 T2: %d\n", isEqual(T1, T2));

    printf("\nLAINNYA\n");
    geser(&T1, 2, 2);
    printf("Titik 1 : (%d, %d)\n", getAbsis(T1), getOrdinat(T1));
    refleksiX(&T1);
    printf("Titik 1 : (%d, %d)\n", getAbsis(T1), getOrdinat(T1));
    refleksiY(&T2);
    printf("Titik 2 : (%d, %d)\n", getAbsis(T2), getOrdinat(T2));
    dilatasi(&T1, 2);
    printf("Titik 1 : (%d, %d)\n", getAbsis(T1), getOrdinat(T1));
    makeTitik(&Tx, 3, 3);
    dilatasiX(&T2, Tx, 4);
    printf("Titik 2 : (%d, %d)\n", getAbsis(T2), getOrdinat(T2));
    printf("Kuadran T1: %d\n", kuadran(T1));
    printf("Kuadran T2: %d\n", kuadran(T2));
    
}