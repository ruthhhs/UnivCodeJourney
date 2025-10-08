// Nama File 	  : main.c
// Deskripsi 	  : main adalah program utama yang akan menggunakan sub program
// Pembuat   	  : Ruth Septriana Sipangkar_2406124120024
// Tgl Pembuatan : 24/03/25

// Header
#include <stdio.h>
#include "MinMax.h" // memanggil subprogram

// Program Utama
int main() {
// Kamus
  int a, b, c;
  int *d;

// Algoritma
printf("================= Selamat Datang ! ==================\n");

printf("\n================ Inisialisasi Nilai =================\n");
  // input
  printf("masukkan integer (a): ");
  scanf("%d", &a);
  printf("masukkan integer (b): ");
  scanf("%d", &b);

  printf("\n========== MinMax Versi 1 (Return Integer) ==========\n");
  printf("MinV1(%d, %d) = %d\n", a, b, minV1(a, b));
  printf("MaxV1(%d, %d) = %d\n", a, b, maxV1(a, b));

  printf("\n============= MinMax Versi 2 (Prosedur) =============\n");
  minV2(a, b, &c);
  printf("minV2(%d, %d, &c) -> c = %d\n", a, b, c);
  maxV2(a, b, &c);
  printf("maxV2(%d, %d, &c) -> c = %d\n", a, b, c);

  printf("\n========== MinMax Versi 1 (Return Address) ==========\n");
  printAddress(&a, "a");
  printAddress(&b, "b");

  d = maxV3 (&a, &b);
  printf("\nd = maxV3(%d, %d) -> *d = %d\n", a, b, *d);
  printAddress(d, "d");

  d = minV3 (&a, &b);
  printf("\nd = minV3(%d, %d) -> *d = %d\n", a, b, *d);
  printAddress(d, "d");

  printf("\n======================= Swap =======================\n");
  swap(&a, &b);
  printf("swap (%d, %d)\n", a, b);
  printAddress(&a, "a");
  printAddress(&b, "b");

  printf("\n==================== Selesai ! =====================\n");

  return 0;
}