#include <stdio.h>
#include <stdbool.h>
#include"ReverseArray.h"

// kamus global
int N = 5; // dari soal N=100

void isPolindrom(int tabel[]){
    // membuat duplikan tabel
    int t[N];
    for (int i=0; i<N; i++){
        t[i] = tabel[i];
    }
    // membalik tabel duplikat
    ReverseArray(t, N);
    
    // mengecek polindrom
    bool polindrom = true;
    for (int i=0; i<N; i++){
        if (t[i] != tabel[i]){
            polindrom = false;
        }
    }

    // hasil
    if (polindrom){
        printf("TRUE");
    } else {
        printf("FALSE");
    }
}

int main(){
    int tabel[N];
    for (int i=0; i<N; i++){
        scanf("%d", &tabel[i]);
    }

    isPolindrom(tabel);
}