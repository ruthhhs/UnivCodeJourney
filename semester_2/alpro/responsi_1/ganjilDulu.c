// Nama File 	: ganjilDulu.c
// Deskripsi 	: ganjilDulu ngurutin ganjil dulu baru genap
// Pembuat   	: Ruth Septriana Sipangkar_2406124120024
// Tgl Pembuatan: <diisikan tanggal dan jam>

// Header
#include <stdio.h>

// Program Utama
int main() {
// Kamus
  int N;

// Algoritma
  // memasukkan tabel (user)
  printf("Masukkan panjang tabel: ");
  scanf("%d", &N);
  int tabel[N];

  printf("Masukkan elemen tabel: ");
  for (int i=0; i<N; i++){
    scanf("%d", &tabel[i]);
  }

  // menyeleksi dan mengurutkan bilangan ganjil dahulu
  for (int i=0; i<N; i++){
    if (tabel[i] %2 == 1){
        printf("%d ", tabel[i]);
    }
  }

  // mengeluarkan sisa bilangan genap
  for (int i=0; i<N; i++){
    if (tabel[i] %2 == 0){
        printf("%d ", tabel[i]);
    }
  }

  return 0;
}