// ======================================================
// Nama Program: tqueue.h
// Deskripsi   : header ADT Tqueue tipe 1
// NIM/Nama    : 24060124120024/Ruth Septriana Sipangkar
// Tanggal     : 09/10/2025
// ======================================================
#ifndef tqueue_H
#define tqueue_H
#include "boolean.h"
#include "pasien.h"

// DEFINISI TYPE
typedef struct {
  pasien wadah[6]; //kapasitas 5 elemen, indeks 0 tidak dipakai
  int head; 
  int tail; 
} tqueue;

// KONSTRUKTOR
void createQueue(tqueue *Q);

// SELEKTOR
#define head(Q) (Q).head 
#define tail(Q) (Q).tail 

pasien infoHead(tqueue Q);
pasien infoTail(tqueue Q);

// BACA TULIS
void printQueue(tqueue Q);
void viewQueue(tqueue Q);

// PREDIKAT
boolean isEmptyQueue(tqueue Q);
boolean isFullQueue(tqueue Q);
boolean isOneElement(tqueue Q);

// MUTATOR
void enqueue(tqueue *Q, pasien p);
void dequeue(tqueue *Q, pasien *e);

#endif
