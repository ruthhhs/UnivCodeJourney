// ======================================================
// Nama Program: mbrowser.c
// Deskripsi   : main file yang mengaplikasikan ADT Tstack
// NIM/Nama    : 24060124120024/Ruth Septriana Sipangkar
// Tanggal     : 28/09/2025
// ======================================================
#include <stdio.h>
#include "tstack.h"
#include "boolean.h"

int main(){
    // Kamus
    Tstack SIsi, SBack;
    int kode, exit, i;
    char x, c;

    // Algoritma
    printf("============= M_BROWSER =============\n");
    printf("Selamat datang di MBrowser\nBerikut instruktur penggunaan (kode):\n(1) Tambah 1 elemen char\n(2) Backward 1x\n(3) Forward 1x\n(4) Exit\n");
    createStack(&SIsi);
    createStack(&SBack);
    viewStack(SIsi);

    exit = 0;
    while(exit != 1){
        printf("\nMasukkan kode: ");
        scanf("%d", &kode);
        if(kode == 1 && !isFullStack(SIsi)) {
            printf("Masukkan char input: ");
            scanf(" %c", &x);
            push(&SIsi, x);
            viewStack(SIsi);
        } else if(kode == 2 && !isEmptyStack(SIsi)){
            pop(&SIsi, &c);
            push(&SBack, c);
            viewStack(SIsi);
        } else if(kode == 3&& !isEmptyStack(SBack)){
            pop(&SBack, &c);
            push(&SIsi, c);
            viewStack(SIsi);
        } else if(kode == 4){
            exit = 1;
            printf("Kamu sudah Exit\nTerima kasih sudah menggunakan MBrowser!");
        } else {
            printf("Kode tidak valid, ulangi\n");
        }
    }


}