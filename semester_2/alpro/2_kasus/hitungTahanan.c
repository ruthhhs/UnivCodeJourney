// Nama File 	  : hitungTahanan.c
// Deskripsi 	  : hitungTahanan adalah nilai total dari 3 tahanan jika dirangkai seri
// Pembuat   	  : Ruth Septriana Sipangkar_2406124120024
// Tgl Pembuatan: 02/03/25, 20.50 WIB

// Header
#include <stdio.h>

// Program Utama
int main() {
// Kamus
  float i, j, k, total;

// Algoritma
  printf("Masukkan nilai tahanan pertama: ");
  scanf("%f", &i);
  printf("Masukkan nilai tahanan kedua: ");
  scanf("%f", &j);
  printf("Masukkan nilai tahanan ketiga: ");
  scanf("%f", &k);

  if (i>=0 && j>=0 && k>=0) {
    total = i+j+k;
    printf("Total tahanan rangkaian seri adalah %f", total);
  }
  else {
    printf("Masukan tahanan tidak boleh negatif");
  }
  return 0;
}