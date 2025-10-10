// ======================================================
// Nama Program: mainQ2.h
// Deskripsi   : driver ADT Tqueue2
// NIM/Nama    : 24060124120024/Ruth Septriana Sipangkar
// Tanggal     : 02/10/2025
// ======================================================
#include <stdio.h>
#include "tqueue2.h"

int main(){
    // Kamus
    tqueue2 A, B, C, D;
    char x;
    int N;

    // Algoritma
    printf("========== ADT QUEUE TYPE 2 =========\n");
    createQueue2(&A);
    printQueue2(A);
    viewQueue2(A);

    printf("Queue A\n");
    printf("Enqueue\n");
    enqueue2(&A, 'a');
    enqueue2(&A, 'y');
    enqueue2(&A, 'a');
    enqueue2(&A, 'm');
    printQueue2(A);
    viewQueue2(A);

    dequeue2(&A, &x);
    printf("Dequeue : %c\n", x);
    printQueue2(A);
    viewQueue2(A);

    dequeue2(&A, &x);
    printf("Dequeue : %c\n", x);
    printQueue2(A);
    viewQueue2(A);

    printf("Enqueue\n");
    enqueue2(&A, 'y');
    printQueue2(A);
    viewQueue2(A);

    printf("Enqueue\n");
    enqueue2(&A, 'a');
    printQueue2(A);
    viewQueue2(A);

    printf("Enqueue\n");
    enqueue2(&A, 'm');
    printQueue2(A);
    viewQueue2(A);

    createQueue2(&B);
    createQueue2(&C);
    enqueue2(&B, 'x');
    enqueue2(&B, 'y');
    enqueue2(&B, 'z');
    enqueue2(&C, 'w');
    enqueue2(&C, 'x');
    enqueue2(&C, 'y');
    enqueue2(&C, 'q');
    dequeue2(&C, &x);
    printf("perbandingan 2 queue (B dan C)\n");
    printQueue2(B);
    printQueue2(C);
    printf("isEqualQueue2: %s\n",isEqualQueue2(B, C) ? "True" : "False");

    printf("\n========== MASUKKAN ELEMEN QUEUE MELALUI KEYBOARD =========\n");
    printf("Matriks A awal:\n");
    printQueue2(A);
    printf("Masukkan jumlah elemen (N) maks 5: ");
    scanf("%d", &N);
    printf("Masukkan elemen (sejumlah N), pisahkan spasi: \n");
    enqueue2N(&A, N);

    printf("\nMatriks C awal:\n");
    printQueue2(C);
    printf("Masukkan jumlah elemen (N) maks 5: ");
    scanf("%d", &N);
    enqueue2N(&C, N);

    createQueue2(&D);
    printf("\nMatriks D awal (kosong):\n");
    printQueue2(D);
    printf("Masukkan jumlah elemen (N) maks 5: ");
    scanf("%d", &N);
    enqueue2N(&D, N);

    printf("\n========== SELESAI =========\n");

}
