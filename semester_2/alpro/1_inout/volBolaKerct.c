// Nama File 	: volBolaKerct.c
// Deskripsi 	: volBolaKerct(vk) adalah volume bola kerucut
// Pembuat   	: Ruth Septriana Sipangkar_2406124120024
// Tgl Pembuatan: 27/02/25, 11.56 WIB

// Header
#include <stdio.h>

// program utama
int main() {
// Kamus
  float r, vb, vk;
  const float phi = 3.1415;

//   Algoritma
printf("masukkan jari-jari (r): ");
scanf("%f", &r);

  vb = (4.0/3.0) * (phi* r*r*r);
  vk = (1.0/2.0) * vb;
  
  printf("volume bola adalah : %f\n", vb);
  printf("volume kerucut adalah : %f", vk);
  return 0;
}