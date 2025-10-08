// Nama File 	: BiayaKirim.c
// Deskripsi 	: BiayaKirim(biaya) adalah biaya pengiriman berdasarkan berat dan jarak
// Pembuat   	: Ruth Septriana Sipangkar_2406124120024
// Tgl Pembuatan: 03/03/25, 21.38 WIB

// Header
#include <stdio.h>

// program utama
int main() {
// Kamus
  int w, s, biaya; // w= berat, s= jarak
  const int hd = 10000; //harga dasar
  const int hw = 5000; //harga per kg
  const int hs = 2000; //harga per km

//   Algoritma
printf("masukkan berat barang (kg): ");
scanf("%d", &w);
printf("masukkan jarak pengiriman (km): ");
scanf("%d", &s);
  
  biaya = hd + hw*w + hs*s;
  
  printf("biaya pengiriman barang adalah : %d", biaya);
  return 0;
}