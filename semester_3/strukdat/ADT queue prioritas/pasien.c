// ======================================================
// Nama Program: pasien.c
// Deskripsi   : body realisasi ADT pasien
// NIM/Nama    : 24060124120024/Ruth Septriana Sipangkar
// Tanggal     : 8/10/2025
// ======================================================
#include <stdio.h>
#include "pasien.h"

// KONSTRUKTOR
void createpasien(pasien *P){
    P->IDpasien = 0;
    P->prioritas = 0;
}

// SELEKTOR
char infoIDpasien(pasien P){
    return P.IDpasien;
}
int infoprioritas(pasien P){
    return P.prioritas;
}

// MUTATOR
void addpasien(pasien *P, int id, int t){
    P->IDpasien = id;
    P->prioritas = t;
}

// BACA TULIS