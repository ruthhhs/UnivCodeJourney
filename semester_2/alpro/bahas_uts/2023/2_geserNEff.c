#include <stdio.h>

int main(){
    int N =8;
    int Neff =4;
    int tabel[N+1]; // di soal panjang tabel [1..N]

    // printf("Masukkan elemen (%d): ", Neff);
    for (int i=1; i<=N; i++){
        if (i<=Neff) {
            scanf("%d", &tabel[i]);
        } else {
            tabel[i]=0;
        }
    }
  
    //geser
    for (int i=N; i>0; i--){
        if (i>Neff){
            tabel[i] = tabel[i-Neff];
        } else {
            tabel[i] = 0;
        }
    }

    //Keluaran 
    for (int i=1; i<=N; i++){
        printf("%d ", tabel[i]);
    }
    return 0;
}