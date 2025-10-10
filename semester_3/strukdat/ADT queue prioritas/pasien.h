// ======================================================
// Nama Program: pasien.h
// Deskripsi   : header ADT pasien
// NIM/Nama    : 24060124120024/Ruth Septriana Sipangkar
// Tanggal     : 8/10/2025
// ======================================================
#ifndef pasien_H
#define pasien_H
#include "boolean.h"

// definisi type
typedef struct {
  int IDpasien; 
  int prioritas; 
} pasien;

// KONSTRUKTOR
void createpasien(pasien *P);

// SELEKTOR
#define IDpasien(P) (P).IDpasien
#define prioritas(P) (P).prioritas
char infoIDpasien(pasien P);
int infoprioritas(pasien P);

// MUTATOR
void addpasien(pasien *P, int id, int p);

// BACA TULIS

#endif
