#include <stdio.h>
#include "mobil.h"

int main(){
    Mobil mobil;
    initMobil(&mobil);
    printf("nama mobil adalah %s dengan kecepatan %d", mobil.namaMobil, mobil.kecepatan);
}