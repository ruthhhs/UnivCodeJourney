// Nama File 	: luasKellLayang.c
// Deskripsi 	: luasLayang(Luas) adalah luas layang-layang dan KellLayang (Kell) adalah keliling layang-layang
// Pembuat   	: Ruth Septriana Sipangkar_2406124120024
// Tgl Pembuatan: 27/02/25, 12.50 WIB

// Header
#include <stdio.h>

// program utama
int main() {
// Kamus
  float s1, s2, d1, d2, Luas, Kell;

//   Algoritma
printf("masukkan sisi 1 : ");
scanf("%f", &s1);
printf("masukkan sisi 2: ");
scanf("%f", &s2);
printf("masukkan diameter 1: ");
scanf("%f", &d1);
printf("masukkan diameter 2: ");
scanf("%f", &d2);
  
  Luas = 0.5 * d1*d2;
  Kell = 2.0 * (s1 + s2);
  
  printf("Luas layang-layang adalah : %f\n", Luas);
  printf("Keliling layang-layang adalah : %f", Kell);
  return 0;
}