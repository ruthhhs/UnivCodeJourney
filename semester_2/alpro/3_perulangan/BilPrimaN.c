// Nama File 	  : BilPrimaN.c
// Deskripsi 	  : BilPrimaN menegluarkan semua bilangan prima dari 1 sampai n
//                  (Bilangan Prima adalah Bilangan yang memiliki jumlah faktor bilangan sebanyak 2, yaitu 1 dan bilangan itu sendiri)
// Pembuat   	  : Ruth Septriana Sipangkar_2406124120024
// Tgl Pembuatan: 09/03/2025

// Header
#include <stdio.h>

// Program Utama
int main() {
// Kamus
  int n, i, j, faktor;
  
// Algoritma
  printf("masukkan bilangan sembarang (int): ");
  scanf("%d", &n);
  
  if (n>1){
    for (i=1; i<=n; i++){
      faktor = 1;
      for (j=1; j<i; j++){
          if (i %j == 0){
          faktor += 1;
        } 
      }
      if (faktor==2){
          printf("%d ", i);
      }
    }
  }
  else{
    printf("Tidak memiliki Bilangan Prima");
  }

  return 0;
}