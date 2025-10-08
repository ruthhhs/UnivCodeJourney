// Nama File 	: maxJualKota.c
// Deskripsi 	: maxJualKota adalah kota dengan penjualan paling besar
// Pembuat   	: Ruth Septriana Sipangkar_2406124120024

#include <stdio.h>
#include <string.h>

int main(){
    // Kamus
    int arr[3][4] = {
        {10, 15, 5, 6},
        {8, 7, 5, 4},
        {3, 5, 2, 8}
    };
    char kota[3][10] = {"Jakarta", "Semarang", "Kendal"};
    char bulan[4][10] = {"Januari", "februari", "Maret", "April"};
    int jumlah, max, idxMax;

    // Algoritma
    int i;
    max = 0;
    for(i=0; i<3; i++){
        jumlah = 0;
        for (int j=0; j<4; j++){
            jumlah += arr[i][j];
        }
        if (jumlah > max){
            max = jumlah;
            idxMax = i;
        }
    }
    printf("Kota dengan penjualan terbesar adalah %s.", kota[idxMax]);
}

// output
// Kota dengan penjualan terbesar adalah Jakarta.