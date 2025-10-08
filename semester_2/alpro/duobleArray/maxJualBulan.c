// Nama File 	: maxJualBulan.c
// Deskripsi 	: maxJualBulan adalah bulan dengan penjualan paling besar
// Pembuat   	: Ruth Septriana Sipangkar_2406124120024

#include <stdio.h>

int main(){
    // Kamus
    int arr[3][4] = {
        {10, 15, 5, 6},
        {8, 7, 5, 4},
        {3, 5, 2, 8}
    };
    char kota[3][10] = {"Jakarta", "Semarang", "Kendal"};
    char bulan[4][10] = {"Januari", "Februari", "Maret", "April"};
    int jumlah, max, idxMax;

    // Algoritma
    int j;
    max = 0;
    for(j=0; j<4; j++){
        jumlah = 0;
        for (int i=0; i<3; i++){
            jumlah += arr[i][j];
        }
        if (jumlah > max){
            max = jumlah;
            idxMax = j;
        }
    }
    printf("Bulan dengan penjualan terbesar adalah %s.", bulan[idxMax]);
}

// output
// Bulan dengan penjualan terbesar adalah Februari.