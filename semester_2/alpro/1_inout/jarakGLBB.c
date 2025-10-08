// Nama File 	: jarakGLBB.c
// Deskripsi 	: jarakjGLBB(s) adalah jarak lurus berubah beraturan
// Pembuat   	: Ruth Septriana Sipangkar_2406124120024
// Tgl Pembuatan: 26/02/25, 14.35WIB

// Header
#include <stdio.h>

// program utama
int main() {
// Kamus
  float v0, t, a, s;

//   Algoritma
printf("masukkan kecepata awal (v0): ");
scanf("%f", &v0);
printf("masukkan waktu (t): ");
scanf("%f", &t);
printf("masukkan percepatan (a): ");
scanf("%f", &a);

  s = v0*t + 0.5*(a*t*t);
  
  printf("jarak GLBB adalah : %f", s);
  return 0;
}