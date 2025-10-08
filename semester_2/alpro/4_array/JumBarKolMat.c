// Nama File 	  : JumBarKolMat.c
// Deskripsi 	  : JumBarKolMat menjumlahkan semua elemen pada baris dan kolom sebuat matriks
// Pembuat   	  : Ruth Septriana Sipangkar_2406124120024
// Tgl Pembuatan: 23/03/25

// Header
#include <stdio.h>

// Program Utama
int main() {
// matriks
int tabel[3][3] = {
    {1, 3, 5},
    {2, 5, 2},
    {4, 2, 4}
};

// Kamus
  int jlhB, jlhK;
  
// Algoritma
  // Menjumlahkan setiap baris
  for (int i=0; i<3; i++){
    jlhB = 0;
    printf("Baris ke-%d : ", i+1);
    for (int j=0; j<3; j++){
        jlhB += tabel[i][j];
        printf("%d", tabel[i][j]);
        if (j<2){
            printf("+");
        }
    }
    printf(" = %d\n", jlhB);
  }

  // Menjumlahkan setiap kolom
  for (int j=0; j<3; j++){
    jlhK = 0;
    printf("Kolom ke-%d : ", j+1);
    for (int i=0; i<3; i++){
        jlhK += tabel[i][j];
        printf("%d", tabel[i][j]);
        if (i<2){
            printf("+");
        }
    }
    printf(" = %d\n", jlhK);
  }
  
  return 0;
}