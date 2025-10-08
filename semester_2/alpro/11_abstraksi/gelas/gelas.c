// Nama : Ruth Septriana Sipangkar
// NIM : 24060124120024

#include <stdio.h>
#include "gelas.h"

void isiPenuh(Gelas* g){
    (*g).isi = (*g).kapasitas;
}
void kosongkan(Gelas* g){
    g->isi = 0;
}
void isiDengan(Gelas* g, int volume){
    if ((*g).isi + volume < (*g).kapasitas){
        (*g).isi += volume;
    } else{
        (*g).isi = (*g).kapasitas;
    }
}
void tuangKe(Gelas* dari, Gelas* ke){
    if (dari->isi + ke->isi > ke->kapasitas){
        ke->isi = ke->kapasitas;
        dari->isi -= ke->isi; 
    } else{
        ke->isi += dari->isi;
        dari->isi = 0;
    }
}
void tampilkan(const Gelas* g){
    printf("\nIsi gelas adalah %d ml (kapasitas %d ml)", g->isi, g->kapasitas);
}