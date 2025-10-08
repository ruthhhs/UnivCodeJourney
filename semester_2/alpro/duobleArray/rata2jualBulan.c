// Nama File 	: rata2jualBulan.c
// Deskripsi 	: rata2jualBulan adalah rata-rata penjualan di masing-masing bulan
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
    char bulan[4][10] = {"Januari", "februari", "Maret", "April"};
    float hasil;

    // Algoritma
    for(int j=0; j<4; j++){
        hasil = 0;
        for (int i=0; i<3; i++){
            hasil += arr[i][j];
        }
        hasil /= 3;
        printf("Rata-rata penjualan pada bulan %s adalah %f produk\n", bulan[j], hasil);
    }

}

// output
// Rata-rata penjualan pada bulan Januari adalah 7.000000 produk
// Rata-rata penjualan pada bulan februari adalah 9.000000 produk
// Rata-rata penjualan pada bulan Maret adalah 4.000000 produk
// Rata-rata penjualan pada bulan April adalah 6.000000 produk