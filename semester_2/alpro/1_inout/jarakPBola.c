// Nama File 	  : jarakPBola.c
// Deskripsi 	  : jarakPBola(y) adalah jarak parabola
// Pembuat   	  : Ruth Septriana Sipangkar_2406124120024
// Tgl Pembuatan: 27/02/25, 11.40 WIB

// Header
#include <stdio.h>

// Program Utama
int main() {
// Kamus
  float v0, t, y;
  const float g = 9.8;
  
  // Algoritma
  printf("masukkan kecepatan awal (v0): ");
  scanf("%f", &v0);
  printf("masukkan waktu (t): ");
  scanf("%f", &t);

  y = v0*t + 0.5*(g* t*t);

  printf("Jarak parabola adalah : %f", y);
  return 0;
}