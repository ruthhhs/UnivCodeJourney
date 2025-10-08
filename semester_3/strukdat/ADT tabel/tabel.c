// ======================================================
// Nama Program: tabel.c
// Deskripsi   : program body modul tabel character
// NIM/Nama    : 24060124120024/Ruth Septriana Sipangkar
// Tanggal     : 11 Sept 2025
// ======================================================
#ifndef tabel_c
#define tabel_c
#include "tabel.h"

void createTable(Tabel *T){
    // kamus lokal
    int i;

    // algoritma
    T->size = 0;
    for (i=0;i<10;i++){
        T->wadah[i] = '*';
    }
}

int getSize(Tabel T){
    // kamus lokal

    // algoritma
    return T.size;
}

boolean isEmptyTable(Tabel T){
    // kamus lokal

    // algoritma
    return T.size == 0;
}

boolean isFullTable(Tabel T){
    // kamus lokal

    // algoritma
    return T.size == 10;
}

void searchX(Tabel T, char x, int *pos){
    // kamus lokal
    int i=0;

    // algoritma
    *pos = 0;
    for(i=0;i<T.size;i++){
        if(T.wadah[i]==x){
            *pos = i+1;
            break;
        } else{
            *pos = -999;
        }
    }
    printf("Elemen %c ditemukan di indeks: %d\n", x, *pos);
}

int countX(Tabel T, char x){
    // kamus lokal
    int i, count=0;

    // algoritma
    for(i=0; i<T.size; i++){
        if(T.wadah[i]==x){
            count++;
        }
    }
    return count;
}

int countVocal(Tabel T){
    // kamus lokal
    int i, j, count=0;
    char vokal[] = {'A','I','U','E','O'};

    // algoritma
    for(i=0; i<T.size; i++){
        for(j=0; j<5; j++){
            if(T.wadah[i]==vokal[j]){
                count++;
                break;
            }
        }
    }
    return count;
}

void addXTable(Tabel *T, char x){
    // kamus lokal

    // algoritma
    if(T->size<10){
        T->wadah[T->size] = x;
        T->size ++;
    }
}

void addUniqueXTable(Tabel *T, char x){
    // kamus lokal
    int pos, i;

    // algoritma
    searchX(*T, x, &pos);
    if(pos == -999){
        addXTable(T, x);
    }
}

void delXTable(Tabel *T, char x){
    // kamus lokal
    int i, j;

    // algoritma
    for(i=0; i<T->size;i++){
        if(T->wadah[i]==x){
            for(j=i; j<T->size-1;j++){
                T->wadah[j] = T->wadah[j+1];
            }
            T->size --;
            break;
        }
    }
}

void delTable(Tabel *T, int idx){
    // kamus lokal
    int i;

    // algoritma
    for(i=idx; i<T->size-1;i++){
        T->wadah[i] = T->wadah[i+1];
    }
    T->size --;
}


void delAllXTable(Tabel *T, char x){
    // kamus lokal
    int i, j;

    // algoritma
    for(i=0; i<T->size;i++){
        if(T->wadah[i]==x){
            for(j=i; j<T->size-1;j++){
                T->wadah[j] = T->wadah[j+1];
            }
            T->size --;
            i--;
        }
    }
}

void printTable(Tabel T){
    // kamus lokal
    int i;

    // algoritma
    printf("Print tabel (size= %d): ", T.size);
    for(i=0; i<10; i++){
        printf("%c ", T.wadah[i]);
    }
    printf("\n");
}

void viewTable(Tabel T){
    // kamus lokal
    int i;

    // algoritma
    printf("-> View tabel (size= %d): ", T.size);
    for(i=0; i<T.size; i++){
        printf("%c ", T.wadah[i]);
    }
    printf("\n");
}

void populateTable(Tabel *T, int N){
    // kamus lokal
    int i;

    // algoritma
    T->size = 0;
    for(i=0; i<N; i++){
        scanf(" %c", &T->wadah[i]);
        T->size++;
    }
}

int Modus(Tabel T){
    // kamus lokal
    int i, j;
    int freq, maxFreq = 0;
    int modus;

    // algoritma
    for(i = 0; i < T.size; i++){
        freq = 0;
        for(j = 0; j < T.size; j++){
            if(T.wadah[i] == T.wadah[j]){
                freq++;
            }
        }
        if(freq > maxFreq){
            maxFreq = freq;
            modus = T.wadah[i];
        }
    }

    return modus;
}

boolean isEqualTable(Tabel T1, Tabel T2){
    // kamus lokal
    int i;

    // algoritma
    if(T1.size==T2.size){
        for(i=0;i<T1.size;i++){
            if(T1.wadah[i]==T2.wadah[i]){
                return 1<0;
            }
        }
    }
}

Tabel getInverseTable(Tabel T){
    Tabel result;
    result.size = T.size;

    for(int i = 0; i < T.size; i++){
        result.wadah[i] = T.wadah[T.size - 1 - i];
    }

    return result;
}

void inverseTable(Tabel *T){
     int i;
    char temp;

    for(i = 0; i < T->size / 2; i++){
        temp = T->wadah[i];
        T->wadah[i] = T->wadah[T->size - 1 - i];
        T->wadah[T->size - 1 - i] = temp;
    }
}

void sortAsc(Tabel *T){
    //  kamus lokal
    int i, j;
    char temp;

    // algoritma
    for(i = 0; i < T->size - 1; i++){
        for(j = 0; j < T->size - i - 1; j++){
            if(T->wadah[j] > T->wadah[j+1]){
                temp = T->wadah[j];
                T->wadah[j] = T->wadah[j+1];
                T->wadah[j+1] = temp;
            }
        }
    }
}

void sortDesc(Tabel *T){
    // kamus lokal
    int i, j;
    char temp;

    // algoritma
    for(i = 0; i < T->size - 1; i++){
        for(j = 0; j < T->size - i - 1; j++){
            if(T->wadah[j] < T->wadah[j+1]){
                temp = T->wadah[j];
                T->wadah[j] = T->wadah[j+1];
                T->wadah[j+1] = temp;
            }
        }
    }
}

#endif