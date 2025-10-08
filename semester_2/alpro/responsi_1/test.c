// Nama File     : bonAppetit.c
// Deskripsi     : bonAppetit mengeluarkan berapa bulan minimal lama Kiss Shot dapat memakan 4 tipe manusia
// Pembuat       : Ruth Septriana Sipangkar_2406124120024
// Tgl Pembuatan : 2/4/25

// Header
#include <stdio.h>

// Program Utama
int main() {
// Kamus
  int bulan, A, B, C, D;

// Algoritma
  // masukkan jumlah tiap tipe manusia (user)
//   printf("Masukkan jumlah manusia A, B, C, D: ");
  scanf("%d %d %d %d", &A, &B, &C, &D);

  if (A > 0) {
    if (B > 0){
        if (C > 0){
            bulan = (A+2)/3 + (B+C+2)/3 + (D+2)/3;
        } else {
            bulan = (A+2)/3 + (B+D+2)/3;
        }
    }else if (C > 0){
        bulan = (A+C+2)/3 + (D+2)/3;
    }else {
        bulan = (A+D+2)/3;
    }
  } else if (B> 0){
    if (C>0){
        bulan = (B+C+2)/3 + (D+2)/3;
    } else {
        bulan =  (B+D+2)/3;
    }
  } else if (C>0){
        bulan = (C+2)/3 + (D+2)/3;
  } else {
        bulan =(D+2)/3;
  }

  printf("%d\n", bulan);
  return 0;
}