// Nama File 	  : CekSegitiga.c
// Deskripsi 	  : CekSegitiga menentukan jenis sebuah segitiga dari 3 buah bil int
// Pembuat   	  : Ruth Septriana Sipangkar_2406124120024
// Tgl Pembuatan: 02/03/25, 22.24 WIB

// Header
#include <stdio.h>

// Program Utama
int main() {
// Kamus
  int i, j, k;
  
// Algoritma
printf("Masukkan nilai sisi pertama: ");
scanf("%d", &i);
printf("Masukkan nilai sisi kedua: ");
scanf("%d", &j);
printf("Masukkan nilai sisi ketiga: ");
scanf("%d", &k);

// versi 1
  if (i>0 && j>0 && k>0) {
    if (i == j && i == k && j == k) {
        printf("Merupakan segitiga sama sisi");}
    else if (i==j || i==k || j==k) {
        printf("Merupakan segitiga sama kaki");}
    else {
        printf("Merupakan segitiga sembarang");}
  }
  else {
    printf("Terdapat nilai yang bukan sisi segitiga\n");
  }

// versi 2
if (i+j >k || j+k >i || k+i >j) {
  if (i == j && i == k && j == k) {
      printf("Merupakan segitiga sama sisi");}
  else if (i==j || i==k || j==k) {
      printf("Merupakan segitiga sama kaki");}
  else {
      printf("Merupakan segitiga sembarang");}
}
else {
  printf("Terdapat nilai yang bukan sisi segitiga");
}

  return 0;
}