#include<stdio.h>
#include<stdbool.h>
#include "mesinkarakter.h"

int main(){
    char CK1, CK2; // cek karakter sebelum CC
    
    START(); // i=0
    int endle=0; // jumlah kata akhiran le
    CK2 = CC; ADV();
    CK1 = CC; ADV();
    
    while (!EOP(CC)){ // i < size
        if (CC==' ' || CC=='.' || CC==','){ // mendeteksi sebuah kata
            if (CK1 == 'e' && CK2 == 'l'){ // true jika kata diakhiri hurif le
                endle++;
            }
        }

    CK2 = CK1;
    CK1 = CC;
    ADV(); // i++
    }

    printf("Ada %d kata yang berakhiran le.\n", endle);
   return 0;
}