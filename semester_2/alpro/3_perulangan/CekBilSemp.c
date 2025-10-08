// Nama File 	  : CekBilSemp.c
// Deskripsi 	  : CekBilSemp mengecek apakah bilangan n merupakan bilangan sempurna atau bukan
//                  (Bilangan Sempurna adalah bilangan yang jumlahan faktor bilangannya (kecuali bilangan itu sendiri) sama dengan bilangan itu sendiri)
// Pembuat   	  : Ruth Septriana Sipangkar_2406124120024
// Tgl Pembuatan: 05/03/2025

// Header
#include <stdio.h>

// Program Utama
int main() {
// Kamus
  int n, i, jumlah;
  
// Algoritma
  printf("masukkan bilangan sembarang (int): ");
  scanf("%d", &n);
  
  jumlah = 0;
  for (i=1; i<n; i++){
    if (n %i == 0){
        jumlah += i;
    }
  }
  
  if (n==jumlah){
    printf("Bilangan Sempurna");
  }
  else {
    printf("Bukan Bilangan Sempurna");
  }

  return 0;
}