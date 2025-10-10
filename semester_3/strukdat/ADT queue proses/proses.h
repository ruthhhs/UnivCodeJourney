// ======================================================
// Nama Program: proses.h
// Deskripsi   : header ADT proses
// NIM/Nama    : 24060124120024/Ruth Septriana Sipangkar
// Tanggal     : 8/10/2025
// ======================================================
#ifndef proses_H
#define proses_H
#include "boolean.h"

// definisi type
typedef struct {
  char IDprocess; 
  int burstTime; 
} process;

// KONSTRUKTOR
void createProcess(process *P);

// SELEKTOR
#define IDprocess(P) (P).IDprocess
#define burstTime(P) (P).burstTime
char infoIDprocess(process P);
int infoBurstTime(process P);

// MUTATOR
void addProcess(process *P, char id, int t);

// BACA TULIS
void printProcess (process P, int *currentTime);

#endif
