#include<stdio.h>

void ReverseArray(int tabel[], int size){
    int counter;
    for (int i=0; i<size/2; i++){
        counter = tabel[i];
        tabel[i] = tabel[size-1-i];
        tabel[size-1-i] = counter;
    }
}