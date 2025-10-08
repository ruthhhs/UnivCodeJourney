// Nama File 	: gayaSentr.c
// Deskripsi 	: gayaSentr(F) adalah gaya senripetal Newtom
// Pembuat   	: Ruth Septriana Sipangkar_2406124120024
// Tgl Pembuatan: 27/02/25, 11.45WIB

// Header
#include <stdio.h>

// program utama
int main() {
// Kamus
  float m, v, r, F;

//   Algoritma
printf("masukkan massa (m): ");
scanf("%f", &m);
printf("masukkan kecepatan (v): ");
scanf("%f", &v);
printf("masukkan jari-jari (r): ");
scanf("%f", &r);

  F = m* ((v*v) /r);
  
  printf("Besar gaya sentripetal adalah : %f", F);
  return 0;
}