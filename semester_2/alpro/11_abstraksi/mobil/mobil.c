#include <stdio.h>
#include "mobil.h"

void initMobil(Mobil* M){
    (*M).namaMobil = "Betmen";
    (*M).kecepatan = 0;
}
void mobilJalan(Mobil* M){
    (*M).kecepatan = 50;
}
void mobilBerhenti(Mobil* M){
    (*M).kecepatan = 0;
}
void mobilRem(Mobil* M, int n){
    (*M).kecepatan -= (*M).kecepatan*(n/100);

}
void mobilBelok(char* arah){
    // user hanya bisa input l/L/r/R
    if (arah == "l" || arah == "L"){
        printf("%s", "mobil belok Kiri");
    } else if (arah == "r" || arah == "R"){
        printf("%s", "mobil belok Kanan");
    }
    // user input bebas
    // printf("mobil belok %s", arah);
}