// ======================================================
// Nama Program: PenjadwalanProsesCPU.c
// Deskripsi   : program untuk mensimulasikan penjadwalan proses pada CPU menggunakan algoritma penjadwalan Round Robin dengan quantum 3 per process
// NIM/Nama    : 24060124120024/Ruth Septriana Sipangkar
// Tanggal     : 8/10/2025
// ======================================================
#include<stdio.h>
#include "tqueue.h"
#include "proses.h"

int main(){
    // kamus
    process p1, p2, p3, p4, p5, d;
    tqueue q;
    int currentTime = 0;

    // algoritma
    printf("=============== Proses CPU (Round Robin)===============\n");
    printf("\nSTATE AWAL (0)\n");
    printf("Antrian Proses Awal (Kosong)\n");
    createProcess(&p1);
    createProcess(&p2);
    createProcess(&p3);
    createProcess(&p4);
    createProcess(&p5);
    createQueue(&q);

    printQueue(q);
    viewQueue(q);

    printf("\nSTATE 1\n");
    printf("Menambahkan Antrian Proses\n");
    addProcess(&p1, 'A', 2);
    enqueue(&q, p1);
    printQueue(q);
    viewQueue(q);

    printf("\nSTATE 2\n");
    printf("Menambahkan Antrian Proses\n");
    addProcess(&p2, 'B', 5);
    enqueue(&q, p2);
    printQueue(q);
    viewQueue(q);

    printf("\nSTATE 3\n");
    printf("Menambahkan Antrian Proses\n");
    addProcess(&p3, 'C', 8);
    enqueue(&q, p3);
    printQueue(q);
    viewQueue(q);

    printf("\nSTATE 4\n");
    printf("Menambahkan Antrian Proses\n");
    addProcess(&p4, 'D', 2);
    enqueue(&q, p4);
    printQueue(q);
    viewQueue(q);

    printf("\nSTATE 5\n");
    printf("Menambahkan Antrian Proses\n");
    addProcess(&p5, 'E', 4);
    enqueue(&q, p5);
    printQueue(q);
    viewQueue(q);

    printf("\nSTATE 6\n");
    printf("Menjalankan Proses berdasarkan penjadwalan Round Robin q3\n");
    dequeue(&q, &d);
    printProcess(d, &currentTime);
    printQueue(q);
    viewQueue(q);

    printf("\nSTATE 7\n");
    printf("Menjalankan Proses berdasarkan penjadwalan Round Robin q3\n");
    dequeue(&q, &d);
    printProcess(d, &currentTime);
    printQueue(q);
    viewQueue(q);

    printf("\nSTATE 8\n");
    printf("Menjalankan Proses berdasarkan penjadwalan Round Robin q3\n");
    dequeue(&q, &d);
    printProcess(d, &currentTime);
    printQueue(q);
    viewQueue(q);

    printf("\nSTATE 9\n");
    printf("Menjalankan Proses berdasarkan penjadwalan Round Robin q3\n");
    dequeue(&q, &d);
    printProcess(d, &currentTime);
    printQueue(q);
    viewQueue(q);

    printf("\nSTATE 10\n");
    printf("Menjalankan Proses berdasarkan penjadwalan Round Robin q3\n");
    dequeue(&q, &d);
    printProcess(d, &currentTime);
    printQueue(q);
    viewQueue(q);

    printf("\nSTATE 11\n");
    printf("Menjalankan Proses berdasarkan penjadwalan Round Robin q3\n");
    dequeue(&q, &d);
    printProcess(d, &currentTime);
    printQueue(q);
    viewQueue(q);

    printf("\nSTATE 12\n");
    printf("Menjalankan Proses berdasarkan penjadwalan Round Robin q3\n");
    dequeue(&q, &d);
    printProcess(d, &currentTime);
    printQueue(q);
    viewQueue(q);

    printf("\nSTATE 13\n");
    printf("Menjalankan Proses berdasarkan penjadwalan Round Robin q3\n");
    dequeue(&q, &d);
    printProcess(d, &currentTime);
    printQueue(q);
    viewQueue(q);

    printf("\nSTATE 13\n");
    printf("Menjalankan Proses berdasarkan penjadwalan Round Robin q3\n");
    dequeue(&q, &d);
    printProcess(d, &currentTime);
    printQueue(q);
    viewQueue(q);
}