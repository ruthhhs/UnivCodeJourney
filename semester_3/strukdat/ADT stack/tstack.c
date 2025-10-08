// ======================================================
// Nama Program: tstack.c
// Deskripsi   : body ADT Tstack
// NIM/Nama    : 24060124120024/Ruth Septriana Sipangkar
// Tanggal     : 27/09/2025
// ======================================================
#include <stdio.h>
#include "tstack.h"
#include "boolean.h"
#include <string.h>
#include <stdlib.h>

void createStack (Tstack *T){
    for(int i=0;i<10;i++){
        T->wadah[i] = '#';
    }
    T->top = 0;
}

boolean isEmptyStack (Tstack T){
    return T.top == 0;
}

boolean isFullStack (Tstack T){
    return T.top == 10;
}

void push (Tstack *T, char E){
    if (!isFullStack(*T)) {
        T->wadah[T->top] = E;
        T->top ++;
    }
}

void pop (Tstack *T, char *X){
    if (!isEmptyStack(*T)) {
        *X = T->wadah[T->top-1];
        T->top--;
    }
}

void printStack (Tstack T){
    printf("Isi stack sekarang: ");
    for(int i = 0; i < 10; i++) {
        printf("%c", T.wadah[i]);
    }
    printf("\n");
}

void viewStack (Tstack T){
    printf("Isi stack sekarang: ");
    for(int i = 0; i < T.top; i++) {
        printf("%c", T.wadah[i]);
    }
    printf("\n");
}

boolean isPalindrom(char kata[30]){
    int p = strlen(kata);
    boolean hasil = false;
    int i;
    char c;
    
    p = strlen(kata);
    if(p>0){
        Tstack SS;
        createStack(&SS);
        for(i=0; i<p/2; i++){
            push(&SS, kata[i]);
        }

        if(p % 2 == 1){
            i++;
        }

        while (i < p) {
            pop(&SS, &c);
            if (c != kata[i]) {
                return false;
            }
            i++;
        }
        hasil = true;
    return hasil;
    }
}

void pushN (Tstack *T, int N){
    for(int i=0; i<N; i++){
        if(!isFullStack(*T)){
            scanf(" %c", &T->wadah[T->top]);
            T->top++;
        }
    }
}