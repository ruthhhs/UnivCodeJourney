// Nama File 	  : kel5.c
// Deskripsi 	  : kel5 mengeluarkan bilangan kelipatan 5 dari kumpulan integer
// Pembuat   	  : Ruth Septriana Sipangkar_2406124120024

// Header
#include <stdio.h>

// Program Utama
int main() {
// Kamus
  int nt, i;
  
  // Algoritma
  // memasukkan tabel (user)
  printf("Masukkan panjang tabel: ");
  scanf("%d", &nt);
  int tabel[nt];

  printf("Masukkan elemen tabel: ");
  for (i=0; i<nt; i++){
    scanf("%d", &tabel[i]);
  }

  // tampilkan hasil
  printf("Yang merupakan kelipatan 5 adalah ");

  // kalkulasi hasil
  for (i=0; i<nt; i++){
    if (tabel[i] %5 == 0){
      printf("%d ", tabel[i]);
    }
  }
  
  return 0;
}