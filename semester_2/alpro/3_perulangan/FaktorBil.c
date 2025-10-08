// Nama File 	  : FaktorBil.c
// Deskripsi 	  : FaktorBil mengeluarkan faktor faktor pengali bilangan n
// Pembuat   	  : Ruth Septriana Sipangkar_2406124120024
// Tgl Pembuatan: 05/03/2025

// Header
#include <stdio.h>

// Program Utama
int main() {
// Kamus
  int n, i;
  
// Algoritma
  printf("masukkan bilangan sembarang (int): ");
  scanf("%d", &n);
  
  if (n>0){
    for (i=1; i<n; i++){ // untuk notal i<=n
      if (n %i == 0){
        printf("%d, ", i);
      }
    }
    printf("%d", n);
  }
  else {
    printf("bilangan masukan harus >0");
  }

  return 0;
}