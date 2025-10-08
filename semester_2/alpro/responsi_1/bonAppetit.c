// Nama File     : bonAppetit.c
// Deskripsi     : bonAppetit mengeluarkan berapa bulan minimal lama Kiss Shot dapat memakan 4 tipe manusia
// Pembuat       : Ruth Septriana Sipangkar_2406124120024
// Tgl Pembuatan : 2/4/25

// Header
#include <stdio.h>

// Program Utama
int main() {
// Kamus
  int bulan, makan, A, B, C, D;

// Algoritma
  // masukkan jumlah tiap tipe manusia (user)
  printf("Masukkan jumlah manusia A, B, C, D: ");
  scanf("%d %d %d %d", &A, &B, &C, &D);

  bulan = 0; // inisiasi jumlah bulan minimal
  while (A>0 || B>0 || C>0 || D>0){
    // inisiasi manusia yang sudah termakan
    makan = 0;

    // makan sesuai prioritas
    if (A>0 && makan<3){
      A--; makan++;
    }
    if (B>0 && A==0 && makan<3){
      B--; makan++;
    }
    if (C>0 && (A<3 || B<3) && makan<3){
      C--; makan++;
    }
    if (D>0 && C==0 && (A<3 || B<3) && makan<3){
      D--; makan++;
    }

    bulan++;
  }

  printf("%d\n", bulan);
  return 0;
}