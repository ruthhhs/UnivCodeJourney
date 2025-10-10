// ======================================================
// Nama Program: mainQ3.c
// Deskripsi   : driver ADT Tqueue3
// NIM/Nama    : 24060124120024/Ruth Septriana Sipangkar
// Tanggal     : 09/10/2025
// ======================================================
#include<stdio.h>
#include"tqueue3.h"

int Keadaan(tqueue3 Q){
    printQueue3(Q);
    viewQueue3(Q);
    printf("Head: %d\n", head3(Q));
    printf("Tail: %d\n", tail3(Q));
    printf("Size: %d\n", sizeQueue3(Q));
    printf("isTailOverHead: %s\n", isTailOverHead(Q) ? "True" : "False");
    printf("InfoHead: %c\n", infoHead3(Q));
    printf("InfoTail: %c\n", infoTail3(Q));
    printf("isEmptyQueue3: %s\n", isEmptyQueue3(Q) ? "True" : "False");
    printf("isFullQueue3 : %s\n", isFullQueue3(Q) ? "True" : "False");
    printf("isOneElement3: %s\n", isOneElement3(Q) ? "True" : "False");
}

int main(){
    // Kamus
    tqueue3 A;
    char x;

    // Algoritma
    printf("========== ADT QUEUE TYPE 3 =========\n");
    printf("INISIALISASI QUEUE KOSONG\n");
    createQueue3(&A);
    Keadaan(A);

    printf("\nENQUEUE KE QUEUE A\n");
    enqueue3(&A, 'a');
    Keadaan(A);
    printf("\nENQUEUE KE QUEUE A\n");
    enqueue3(&A, 'y');
    Keadaan(A);
    printf("\nENQUEUE KE QUEUE A\n");
    enqueue3(&A, 'a');
    Keadaan(A);
    printf("\nENQUEUE KE QUEUE A\n");
    enqueue3(&A, 'm');
    Keadaan(A);
    printf("\nENQUEUE KE QUEUE A\n");
    enqueue3(&A, 'm');
    Keadaan(A);

    dequeue3(&A, &x);
    printf("\nDEQUEUE '%c' DARI QUEUE A\n", x);
    Keadaan(A);
    dequeue3(&A, &x);
    printf("\nDEQUEUE '%c' DARI QUEUE A\n", x);
    Keadaan(A);

    printf("\nENQUEUE KE QUEUE A\n");
    enqueue3(&A, 'y');
    Keadaan(A);
    printf("\nENQUEUE KE QUEUE A\n");
    enqueue3(&A, 'a');
    Keadaan(A);

    dequeue3(&A, &x);
    printf("\nDEQUEUE '%c' DARI QUEUE A\n", x);
    Keadaan(A);
}
