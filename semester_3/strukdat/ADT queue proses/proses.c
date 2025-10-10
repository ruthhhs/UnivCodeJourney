// ======================================================
// Nama Program: proses.c
// Deskripsi   : body realisasi ADT proses
// NIM/Nama    : 24060124120024/Ruth Septriana Sipangkar
// Tanggal     : 8/10/2025
// ======================================================
#include <stdio.h>
#include "proses.h"

// KONSTRUKTOR
void createProcess(process *P){
    P->IDprocess = '#';
    P->burstTime = 0;
}

// SELEKTOR
char infoIDprocess(process P){
    return P.IDprocess;
}
int infoBurstTime(process P){
    return P.burstTime;
}

// MUTATOR
void addProcess(process *P, char id, int t){
    P->IDprocess = id;
    P->burstTime = t;
}

// BACA TULIS
void printProcess (process P, int *currentTime){
    int startTime = *currentTime;
    int execTime = (P.burstTime > 3) ? 3 : P.burstTime;
    int sisa = P.burstTime - execTime;
    *currentTime += execTime;
    int endTime = *currentTime;

    printf("Jalankan Proses: <%c,%d> | Start: %d | End: %d",
       P.IDprocess, P.burstTime, startTime, endTime);

    if (sisa > 0) {
        printf(" | Sisa waktu: %d\n", sisa);
    } else {
        printf(" | Selesai\n");
    }
}