// Nama File 	  : kallSS.c
// Deskripsi 	  : kallSS adalah kalkulator super sederhana
// Pembuat   	  : Ruth Septriana Sipangkar_2406124120024
// Tgl Pembuatan: 02/03/25, 22.53 WIB

// Header
#include <stdio.h>

// Program Utama
int main() {
// Kamus
  int i, j;
  char oper;

// Algoritma
  printf("Masukkan nilai pertama: ");
  scanf("%d", &i);
  printf("Masukkan nilai kedua: ");
  scanf("%d", &j);
  printf("(a)penjumlahan\n(b)pengurangan\n(c)perkalian\n(d)pembagain\n(e)pembagian bulat\n(f)sisa pembagian\nPilih operasi: ");
  scanf(" %c", &oper);

  if (oper == 'a') {
    printf("\nHasil operasi %d+%d adalah %d", i, j, i+j);
} else if (oper == 'b') {
    printf("\nHasil operasi %d-%d adalah %d", i, j, i-j);
} else if (oper == 'c') {
    printf("\nHasil operasi %dx%d adalah %d", i, j, i*j);
} else if (oper == 'd') {
    if (j!=0) {
        printf("\nHasil operasi %d/%d adalah %f", i, j, (float) i/j);
    } else {
        printf("\nHasil tidak terdefinisi (penyebut 0)");
    }
} else if (oper == 'e') {
    if (j!=0) {
        printf("\nHasil operasi %d div %d adalah %d", i, j, i/j);
    } else {
        printf("\nHasil tidak terdefinisi (penyebut 0)");
    }
} else if (oper == 'f') {
    printf("\nHasil operasi %d mod %d adalah %d", i, j, i%j);
} else {
    printf("\nBukan pilihan menu yang benar");
}
  return 0;
}