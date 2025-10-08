// ======================================================
// Nama Program: mainQ1.h
// Deskripsi   : driver ADT Tqueue
// NIM/Nama    : 24060124120024/Ruth Septriana Sipangkar
// Tanggal     : 02/10/2025
// ======================================================
#include <stdio.h>
#include "tqueue.h"

int main(){
    // Kamus
    tqueue A, B;
    char x;

    // Algoritma
    printf("========== ADT QUEUE TYPE 1 =========\n");
    createQueue(&A);
    printQueue(A);
    viewQueue(A);

    printf("Enqueue\n");
    enqueue(&A, 'a');
    enqueue(&A, 'y');
    enqueue(&A, 'a');
    enqueue(&A, 'm');
    printQueue(A);
    viewQueue(A);

    dequeue(&A, &x);
    printf("Dequeue : %c\n", x);
    printQueue(A);
    viewQueue(A);

    printf("Enqueue\n");
    enqueue(&A, 'm');
    printQueue(A);
    viewQueue(A);

    createQueue(&B);
    printf("Enqueue\n");
    enqueue(&B, 'y');
    enqueue(&B, 'e');
    enqueue(&B, 'y');
    printQueue(B);
    viewQueue(B);

    enqueue2Q(&A, &B, 'i');
    printf("Enqueue2\n");
    printQueue(A);
    viewQueue(A);
    printQueue(B);
    viewQueue(B);

    dequeue2Q(&A, &B, &x);
    printf("Dequeue2 : %c\n", x);
    printQueue(A);
    viewQueue(A);
    printQueue(B);
    viewQueue(B);

    dequeue2Q(&A, &B, &x);
    printf("Dequeue2 : %c\n", x);
    printQueue(A);
    viewQueue(A);
    printQueue(B);
    viewQueue(B);
}