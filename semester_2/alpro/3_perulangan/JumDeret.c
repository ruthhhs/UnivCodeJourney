// Nama File 	  : JumDeret.c
// Deskripsi 	  : JumDeret mengeluarkan hasil penjumlahan total deret bilangan n
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
  
  if (n>0){
    for (i=1; i<n; i++){ // untuk notal i<=n
      jumlah +=i;
      printf("%d + ", i);
    }
    printf("%d = %d", n, jumlah+n);
  }
  else {
    printf("bilangan masukan harus >0");
  }
  return 0;
}