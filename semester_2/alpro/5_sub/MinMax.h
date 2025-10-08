// Nama File 	  : subProgram.h
// Deskripsi 	  : subProgram adalah sub program yang akan digunakan dalam main program
// Pembuat   	  : Ruth Septriana Sipangkar_2406124120024
// Tgl Pembuatan : 24/03/25

// Header
#include <stdio.h>
#ifndef MINMAX
#define MINMAX

// sub program
int maxV1 (int a, int b){
    // Kamus lokal

    // Algoritma
    if (a>=b){
        return a;
    } else {
        return b;
    }
}

int minV1 (int a, int b){
    // Kamus lokal

    // Algoritma
    if (a<=b){
        return a;
    } else {
        return b;
    }
}

void maxV2 (int a, int b, int *c){
    // Kamus lokal

    // Algoritma
    if (a>=b){
        *c = a;
    } else {
        *c = b;
    }
}

void minV2 (int a, int b, int *c){
    // Kamus lokal

    // Algoritma
    if (a<=b){
        *c = a;
    } else {
        *c = b;
    }
}

int* maxV3 (int *a, int *b){
    // Kamus lokal

    // Algoritma
    if (*a>=*b){
        return a;
    } else {
        return b;
    }
}

int* minV3 (int *a, int *b){
    // Kamus lokal

    // Algoritma
    if (*a<=*b){
        return a;
    } else {
        return b;
    }
}

void swap (int *a, int *b){
    // Kamus lokal
    int temp;

    // Algoritma
    temp = *a;
    *a = *b;
    *b = temp;
}

void swapMaxA (int *a, int *b){
    // Kamus lokal

    // Algoritma
    if (*a < *b){
        swap(a, b);
    }
}

void swapMinA (int *a, int *b){
    // Kamus lokal

    // Algoritma
    if (*a > *b){
        swap(a, b);
    }
}

void printAddress (int *x, char s[]){
    // Kamus lokal
    
    // Algoritma
    printf("Address %s -> %X ; nilai %d\n", s, x, *x);
}

#endif