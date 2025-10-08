// Nama File 	  : bilInteger.c
// Deskripsi 	  : bilInteger menunjukkan apakah suatu bilangan positif, negatif, atau nol
// Pembuat   	  : Ruth Septriana Sipangkar_2406124120024
// Tgl Pembuatan: 02/03/25, 20.16 WIB

// Header
#include <stdio.h>

// Program Utama
int main() {
// Kamus
  int i;
  
// Algoritma
  printf("masukkan bilangan sembarang (int): ");
  scanf("%d", &i);

  if (i>0) {
    printf("%d adalah bil bul positif", i);}
  else if (i<0) {
    printf("%d adalah bil bul negatif", i);}
  else {
    printf("%d adalah bil nol", i);}

  return 0;
}