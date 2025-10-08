// Nama File 	  : namaHari.c
// Deskripsi 	  : namaHari menunjukkan nama hari dari angka 1 s.d. 7
// Pembuat   	  : Ruth Septriana Sipangkar_2406124120024
// Tgl Pembuatan: 02/03/25, 20.34 WIB

// Header
#include <stdio.h>

// Program Utama
int main() {
// Kamus
  int i;
  
// Algoritma
  printf("Masukkan angka hari (1 s.d. 7): ");
  scanf("%d", &i);

  if (1<=i && i<=7) {
    if (i == 1) {
        printf("Hari ini adalah Senin");}
    else if (i == 2) {
        printf("Hari ini adalah Selasa");}
    else if (i == 3) {
        printf("Hari ini adalah Rabu");}
    else if (i == 4) {
        printf("Hari ini adalah Kamis");}
    else if (i == 5) {
        printf("Hari ini adalah Jumat");}
    else if (i == 6) {
        printf("Hari ini adalah Sabtu");}
    else if (i == 7) {
        printf("Hari ini adalah Minggu");}
    }
  else {
    printf("Masukan nomor hari tidak tepat");
  }

  return 0;
}