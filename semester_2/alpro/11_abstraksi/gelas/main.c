// Nama : Ruth Septriana Sipangkar
// NIM : 24060124120024

#include <stdio.h>
#include "gelas.h"

int main(){
    // inisialisasi kedua gelas
    Gelas gelasA = {250, 0};
    Gelas gelasB = {100, 0};

    //  tampilkan status awal gelas
    printf ("\nStatus awal gelas:");
    tampilkan(&gelasA);
    tampilkan(&gelasB);

    // isi penuh kedua gelas
    printf("\n\nIsi kedua gelas:");
    isiPenuh(&gelasA);
    isiPenuh(&gelasB);
    tampilkan(&gelasA);
    tampilkan(&gelasB);

    // kosongkan kedua gelas
    printf("\n\nKosongkan kedua gelas:");
    kosongkan(&gelasA);
    kosongkan(&gelasB);
    tampilkan(&gelasA);
    tampilkan(&gelasB);

    // isi gelas masing masing 300ml
    printf("\n\nIsi kedua gelas sebanyak 300 ml:");
    isiDengan(&gelasA, 300);
    isiDengan(&gelasB, 300);
    tampilkan(&gelasA);
    tampilkan(&gelasB);

    // isi gelas B dari gelas A
    printf("\n\nIsi gelas B dari gelas A jika B kosong:");
    kosongkan(&gelasB);
    tuangKe(&gelasA, &gelasB);
    tampilkan(&gelasA);
    tampilkan(&gelasB);
}