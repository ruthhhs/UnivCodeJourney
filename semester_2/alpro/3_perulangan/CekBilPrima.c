// Nama File 	  : CekBilPrima.c
// Deskripsi 	  : CekBilPrima mengecek apakah bilangan n merupakan bilangan prima atau bukan
//                  (Bilangan Prima adalah Bilangan yang memiliki jumlah faktor bilangan sebanyak 2, yaitu 1 dan bilangan itu sendiri)
// Pembuat   	  : Ruth Septriana Sipangkar_2406124120024
// Tgl Pembuatan: 09/03/2025

// Header
#include <stdio.h>

// Program Utama
int main() {
// Kamus
  int n, i, faktor;
  
// Algoritma
  printf("masukkan bilangan sembarang (int): ");
  scanf("%d", &n);
  
  faktor = 1;
  for (i=1; i<n; i++){
    if (n %i == 0){
      faktor += 1;
    }
  }

  if (faktor==2){
    printf("Bilangan Prima");
  }
  else {
    printf("Bukan Bilangan Prima");
  }

  return 0;
}