// Nama File 	: rata2jualKota.c
// Deskripsi 	: rata2jualKota adalah rata-rata penjualan di masing-masing kota
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
    for(int i=0; i<3; i++){
        hasil = 0;
        for (int j=0; j<4; j++){
            hasil += arr[i][j];
        }
        hasil /= 4;
        printf("Rata-rata penjualan kota %s adalah %f produk\n", kota[i], hasil);
    }

}

// output
// Rata-rata penjualan kota Jakarta adalah 9.000000 produk
// Rata-rata penjualan kota Semarang adalah 6.000000 produk
// Rata-rata penjualan kota Kendal adalah 4.500000 produk