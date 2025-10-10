// ======================================================
// Nama Program: mainPuskesmas.c
// Deskripsi   : mengelola antrean puskesmas
// NIM/Nama    : 24060124120024/Ruth Septriana Sipangkar
// Tanggal     : 9/10/2025
// ======================================================
#include<stdio.h>
#include "tqueue.h"
#include "pasien.h"

int main(){
    // kamus
    pasien p1, p2, p3, p4, p5, d;
    tqueue q;

    // algoritma
    printf("=============== ANTREAN PASIEN ===============\n");
    printf("Antrian Pasien Awal (Kosong)\n");
    createpasien(&p1);
    createpasien(&p2);
    createpasien(&p3);
    createpasien(&p4);
    createpasien(&p5);
    createQueue(&q);

    printQueue(q);
    viewQueue(q);

    printf("\nMenambahkan Antrian Pasien\n");
    addpasien(&p1, 10, 1);
    enqueue(&q, p1);
    printQueue(q);
    viewQueue(q);

    printf("\nMenambahkan Antrian Pasien\n");
    addpasien(&p2, 11, 2);
    enqueue(&q, p2);
    printQueue(q);
    viewQueue(q);

    printf("\nMenambahkan Antrian Pasien\n");
    addpasien(&p3, 12, 1);
    enqueue(&q, p3);
    printQueue(q);
    viewQueue(q);

    printf("\nMenambahkan Antrian Pasien\n");
    addpasien(&p4, 13, 3);
    enqueue(&q, p4);
    printQueue(q);
    viewQueue(q);

    printf("\nMenambahkan Antrian Pasien\n");
    addpasien(&p5, 14, 2);
    enqueue(&q, p5);
    printQueue(q);
    viewQueue(q);

}