// Nama File 	  : namaBulan.c
// Deskripsi 	  : namaBulan menunjukkan nama bulan dari angka 1 s.d. 12
// Pembuat   	  : Ruth Septriana Sipangkar_2406124120024
// Tgl Pembuatan: 02/03/25, 20.39 WIB

// Header
#include <stdio.h>

// Program Utama
int main() {
// Kamus
  int i;
  
// Algoritma
  printf("Masukkan angka bulan (1 s.d. 12): ");
  scanf("%d", &i);

  if (1<=i && i<=12) {
    if (i == 1) {
        printf("Sekarang bulan Januari");}
    else if (i == 2) {
        printf("Sekarang bulan Februari");}
    else if (i == 3) {
        printf("Sekarang bulan Maret");}
    else if (i == 4) {
        printf("Sekarang bulan April");}
    else if (i == 5) {
        printf("Sekarang bulan Mei");}
    else if (i == 6) {
        printf("Sekarang bulan Juni");}
    else if (i == 7) {
        printf("Sekarang bulan Juli");}
    else if (i == 8) {
        printf("Sekarang bulan Agustus");}
    else if (i == 9) {
        printf("Sekarang bulan September");}
    else if (i == 10) {
        printf("Sekarang bulan Oktober");}
    else if (i == 11) {
        printf("Sekarang bulan November");}
    else if (i == 12) {
        printf("Sekarang bulan Desember");}
    }
  else {
    printf("Masukan nomor bulan tidak tepat");
  }

  return 0;
}