// Nama File 	  : cekBilAll.c
// Deskripsi 	  : cekBilAll mengecek apakah sebuah bilangan termasuk bilangan Prima atau Sempurna atau Biasa
// Pembuat   	  : Ruth Septriana Sipangkar_2406124120024
// Tgl Pembuatan: 09/03/2025

// Header
#include <stdio.h>

// Program Utama
int main() {
// Kamus
  int n, i, faktor, jumlah;
  
// Algoritma
  printf("masukkan bilangan sembarang (int): ");
  scanf("%d", &n);
  
  jumlah = 0;
  faktor = 1;
  for (i=1; i<n; i++){
    if (n %i == 0){
        jumlah += i;
        faktor += 1;
    }
  }

  if (n==jumlah){
    printf("%d adalah Bilangan Sempurna", n);
  }
  else if (faktor==2){
    printf("%d adalah Bilangan Prima", n);
  }
  else {
    printf("%d adalah Bilangan Biasa", n);
  }

  return 0;
}