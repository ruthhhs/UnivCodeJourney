// Nama File 	  : NilMax2Tabel.c
// Deskripsi 	  : NilMax2Tabel menampilkan nilai maksimum ke-2 dari sebuah tabel integer
// Pembuat   	  : Ruth Septriana Sipangkar_2406124120024
// Tgl Pembuatan: 12/03/25

// Header
#include <stdio.h>

// Program Utama
int main() {
// contoh array
  int nt = 10;
  int tabel[] = {7, 4, 5, 7, 6, 5, 3, 5, 1, 4};

// Kamus
  int max, max2;

// Algoritma
 // mencari max1
  max = 0;
  for (int i=1; i<nt; i++){
    if (tabel[i] > max){
        max = tabel[i];
    }
  }

  // mencari max2
  max2 = 0;
  for (int i=1; i<nt; i++){
    if (tabel[i] > max2 && tabel[i] < max){
        max2 = tabel[i];
    }
  }

  printf("nilai max2 adalah %d", max2);
  return 0;
}
