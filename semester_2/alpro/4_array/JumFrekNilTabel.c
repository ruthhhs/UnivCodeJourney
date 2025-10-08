// Nama File 	  : JumFrekNilTabel.c
// Deskripsi 	  : JumFrekNilTabel menampilkan jumlah nilai-nilai elemen tabel T yang frekuensi kemunculannya lebih dari satu kali
// Pembuat   	  : Ruth Septriana Sipangkar_2406124120024
// Tgl Pembuatan: 23/03/25

// Header
#include <stdio.h>

// Program Utama
int main() {
// array
  int nt = 10;
  int tabel[] = {7, 4, 5, 7, 6, 5, 3, 5, 1, 4};

// Kamus
  int count;
  int cetak[nt];
  
// Algoritma
  for (int i=0; i<nt; i++){
    // mengecek berapa kali kemunculan elemen ganda
    count = 0;
    for (int j=0; j<nt; j++){
      if (tabel[i] == tabel[j]){
        count ++;
      }
    }

    // menyimpan data elemen2 ganda ke array baru
    if (count >1){
      cetak[i] = tabel[i];
      // printf("%d", cetak[i]);
    }
  }

  // menjumlahkan elemen dalam array cetak
  int jumlah = 0;
  for (int i=0; i<nt; i++){
    jumlah += tabel[i];
  }

  printf("jumlah total elemen ganda: %d", jumlah);
  return 0;
}