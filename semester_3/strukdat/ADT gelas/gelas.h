// Nama : Ruth Septriana Sipangkar
// NIM : 24060124120024

#ifndef GELAS_H
#define GELAS_H

// Mendefinisikan tipe data Gelas
typedef struct{
    int kapasitas;  // kapasitas maks gelas (ml)
    int isi;        // isi saat ini (ml)
} Gelas;

// Mengisi gelas hingga penuh
void isiPenuh(Gelas* g);

// Mengosongkan gelas
void kosongkan(Gelas* g);

// Mengisi gelas dengan sejumlah volume tertentu
void isiDengan(Gelas* g, int volume);

// Menuangkan isi dari satu gelas ke gelas lain
void tuangKe(Gelas* dari, Gelas* ke);

// Menampilkan status gelas (kapasitas dan isi)
void tampilkan(const Gelas* g);

#endif