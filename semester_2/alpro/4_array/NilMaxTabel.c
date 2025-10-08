// Pembuat   	  : Ruth Septriana Sipangkar_2406124120024

// Header
#include <stdio.h>

// Program Utama
int main() {
// Kamus
  int nt, max;
  
// Algoritma
  // memasukkan tabel (user)
  printf("Masukkan panjang tabel: ");
  scanf("%d", &nt);
  int tabel[nt];

  printf("Masukkan elemen tabel: ");
  for (int i=0; i<nt; i++){
    scanf("%d", &tabel[i]);
  }

  // mencari max
  max = 0;
  for (int i=1; i<nt; i++){
    if (max < tabel[i]){
        max = tabel[i];
    }
  }

  printf("nilai max adalah %d", max);
  return 0;
}
