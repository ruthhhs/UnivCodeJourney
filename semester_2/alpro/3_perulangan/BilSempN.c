// Nama File 	  : BilSempN.c
// Deskripsi 	  : BilSempN menegluarkan semua bilangan sempurna dari 1 sampai n
//                  (Bilangan Sempurna adalah bilangan yang jumlahan faktor bilangannya (kecuali bilangan itu sendiri) sama dengan bilangan itu sendiri)
// Pembuat   	  : Ruth Septriana Sipangkar_2406124120024
// Tgl Pembuatan: 09/03/2025

// Header
#include <stdio.h>

// Program Utama
int main() {
// Kamus
  int n, i, j, jumlah;
  
// Algoritma
  printf("masukkan bilangan sembarang (int): ");
  scanf("%d", &n);
  
  if (n>=6){
    for (i=1; i<=n; i++){
      jumlah = 0;
      for (j=1; j<i; j++){
          if (i %j == 0){
              jumlah += j;
          }
      }
      if (i==jumlah){
          printf("%d ", i);
      }
    }
  }
  else{
    printf("Tidak memiliki Bilangan Sempurna");
  }

  return 0;
}