// Nama File 	  : FrekNilTabel.c
// Deskripsi 	  : FrekNilTabel menampilkan nilai elemen tabel T yang frekuensi kemunculannya lebih dari satu kali
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
  int count, sudahAda;
  int cetak[nt]; 
  
// Algoritma
  printf("elemen yang ganda adalah: ");
  for (int i=0; i<nt; i++){
    // Cek apakah elemen sudah dicetak sebelumnya
    sudahAda = 0; // false
    for (int k = 0; k < nt; k++) {
        if (tabel[i] == cetak[k]) {
            sudahAda = 1; // true
        }
    }

    // program berlanjut ketika elemen ganda blm dicetak
    // (jika sudah di cetak dilewati)
    if (sudahAda == 0){
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
        printf("%d ", cetak[i]);
      }
    }
  }

  return 0;
}