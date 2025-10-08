// Nama File 	  : SimetriTabel.c
// Deskripsi 	  : SimetriTabel menentukan bahwa T1 dan T2 simetri atau tidak
// Pembuat   	  : Ruth Septriana Sipangkar_2406124120024
// Tgl Pembuatan: 23/03/25

// Header
#include <stdio.h>

// Program Utama
int main() {
// array
  int n1 = 10;
  int tabel1[] = {7, 4, 5, 7, 6, 5, 3, 5, 1, 4};
  // (ubah sesuai kebutuhan)
  // int n2 = 10;
  // int tabel2[] = {7, 4, 5, 7, 6, 5, 3, 5, 1, 4};
  int n2 = 10;
  int tabel2[] = {7, 4, 5, 12, 6, 5, 3, 5, 1, 4};
  // int n2 = 8;
  // int tabel2[] = {7, 4, 5, 7, 6, 5, 1, 4};

// bandingkan panjang tabel
if (n1 != n2){
  printf("tabel1 dan tabel2 tidak simetris");
} else {
  // cek tiap elemen tabel
  int cek = 0;
  for (int i=0; i<n1; i++){
    if (tabel1[i] == tabel2[i]){
      cek ++;
    }
  }
  if (cek == n1){
    printf("tabel1 dan tabel2 simetris");
  } else {
    printf("tabel1 dan tabel2 tidak simetris");
  }
}

  return 0;
}