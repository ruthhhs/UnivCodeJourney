// Nama File     : sisiTerang.c
// Deskripsi     : sisiTerang menunjukkan apakah Denis dapat pulang tergantung lampu jalan hidup atau mati
// Pembuat       : Ruth Septriana Sipangkar_2406124120024
// Tgl Pembuatan : 26/03/25

// Header
#include <stdio.h>

// Program Utama
int main() {
// Kamus
int N, K;

// Algoritma
  // memasukkan jalan dan lampu (user)
  printf("Masukkan panjang jalan dan jangkauan lampu: ");
  scanf("%d %d", &N, &K);

  // kondisi awal jalan dan lampu jalan
  int jalan[N];
  printf("Urutan lampu hidup dan mati (0 mati; 1 hidup): ");
  for (int i=0; i<N; i++){
    scanf("%d", &jalan[i]);
  }

  // inisialisasi jalan yang terkena cahaya (semuanya mati)
  int terang[N];
  for (int i=0; i<N; i++) {
    terang[i] = 0;
  }

  // mengecek lampu yang hidup dan daerah yang terkena cahaya lampu
  for (int i=0; i<N; i++){
    if (jalan[i] == 1){ // lampu hidup
        for (int j= i-K; j<= i+K; j++) {
            if (j>=0 && j<N){
                terang[j] = 1; // menandai daerah sekitar lampu = terang
            }
        }
    }
  }

  // mengecek apakah masih ada jalan yang gelap
  for (int i=0; i<N; i++) {
    if (terang[i] == 0) {
        printf("NO\n");
        return 0; // menghentikan program
    }
  }

  // jika semua jalan terkena cahaya lampu
  printf("YES\n");
  return 0;
}