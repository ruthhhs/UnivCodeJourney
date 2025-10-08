/***************************************************************/
/* */
/* Nama File : tabel.c */
/* Deskripsi : Body Abstract Data Type Tabel */
/* */
/***************************************************************/
#ifndef TABEL_C
#define TABEL_C

#include "tabel.h"
#include <stdio.h>

/*Body Prototype*/
/***************************************************************/
/* */
/* KONSTRUCTOR */
/* */
/***************************************************************/

void CreateEmpty(TabInt *T){
    // Proses : Mengeset nilai T.neff dengan nilai 0.
    // I.S : sembarang.
    // F.S : terbentu tabel T kosong dengan kapasitas Nmax - Nmin+1.
    /*Kamus Lokal*/

    /*Algoritma*/
    (*T).NEff=0; /*dapat dengan cara T->Neff=0 karena pointer*/

}
/***************************************************************/
/* */
/* OPERASI TERHADAP INDEKS TABEL */
/* */
/***************************************************************/
boolean IsIdxValid(TabInt T, IdxType i){
    /* Mengirimkan true apabila i merupakan index yang valid bagi TabInt T, yaitu IdxMin <= i <= IdxMax. */

    /*Kamus Lokal*/
    /*Algoritma*/
    if (i>=IdxMin && i<=IdxMax){
        return(true);
    }
    else{
        return(false);
    }
    /*atau dipersingkat return ((i >= IdxMin) && (i <= IdxMax));*/
}
    
boolean IsIdxEff(TabInt T, IdxType i){
        /* Mengirimkan true apabila i merupakan indeks yang efektif */
        /* berisi suatu nilai, yaitu idxmin <= i <= NEff. */
        /*Kamus Lokal*/
        /*Algoritma*/
        if (i>=IdxMin && i<=T.NEff){
            return(true);
        }
        else{
            return(false);
        }
        
        /*atau dipersingkat return ( ( i >= IdxMin ) && ( i <= T.NEff);*/
}
/***************************************************************/
/* */
/* PREDIKAT TABEL */
/* */
/***************************************************************/
boolean IsEmpty(TabInt T){
    /* Mengirimkan true apabila T merupakan TabInt yang kosong, */
    /* yaitu apabila T.NEff == 0. */
    /*Kamus Lokal*/
    /*Algoritma*/
    return (T.NEff == 0);
}
boolean IsFull(TabInt T){
    /* Mengirimkan true apabila T merupakan TabInt yang penuh, */
    /* yaitu apabila T.NEff == IdxMax. */
    /*Kamus Lokal*/
    /*Algoritma*/
    return (T.NEff == IdxMax);
}
/***************************************************************/
/* */
/* BACA TULIS, HUBUNGAN DENGAN I/O DEVICE */
/* */
/***************************************************************/
void PrintTabel(TabInt T){
    /* Proses : Melakukan traversal sebanyak banyaknya elemen */
    /* efektif, dan menuliskan nilainya ke layar. */
    /* I.S : T boleh kosong. */
    /* F.S : Elemen tabel ditulis ke layar, jika tidak kosong. */
    /* jika tabel kosong menampilkan "Tabel Kosong." */
    /*Kamus Lokasl*/
    int i; /*counter*/
    /*Algoritma*/
    if (T.NEff!=0){
        for (i = IdxMin; i <= T.NEff; i++) {
            printf("Data ke-%d : %d\n",i,T.TI[i]);
        }
        /* i > T.NEff */
    }
    else{
    printf("Tabel Kosong\n");
    }
}
void IsiTabel(TabInt* T, ElmtType N){
    /* Proses : Melakukan traversal sebanyak N untuk mengisi nilai */
    /* elemen-elemen Tabel T dengan 2 kali indexnya */
    /* I.S : Sembarang. */
    /* F.S : Tabel T terdefinisi. */
    /*Kamus Lokasl*/
    int i; /*counter*/
    /*Algoritma*/
    CreateEmpty(T); /*karena pointer*/
    if (N>=IdxMin && N<=IdxMax){
        for(i=1;i<=N;i++){
            (*T).TI[i]=2*i;
            (*T).NEff=i;
        }
    }
    else{
    printf("Harus N>=IdxMin && N<=IdxMax\n");
    }
}
/***************************************************************/
/* */
/* NILAI EKSTRIM */
/* */
/***************************************************************/
ElmtType ValMax(TabInt T){
    /* Mengirimkan nilai maksimum TabInt T. */
    /* Pre Condition : Tabel tidak kosong. */
    /*Kamus Lokasl*/
    ElmtType max; /*nilai maksimum*/
    int i; /*counter*/
    /*Algoritma*/
    max=T.TI[1];
    for(i=IdxMin+1;i<=T.NEff;i++){
        if(T.TI[i]>max){
            max=T.TI[i];
        }
    }
    return max;
}
ElmtType ValMin(TabInt T){
    /* Mengirimkan nilai minimum TabInt T. */
    /* Pre Condition : Tabel tidak kosong. */
    /*Kamus Lokasl*/

    ElmtType min; /*nilai minimum*/
    int i; /*counter*/

    /*Algoritma*/
    min=T.TI[1];
    for(i=IdxMin+1;i<=T.NEff;i++){
        if(T.TI[i]<min){
            min=T.TI[i];
        }
    }
    return min;
} 

/***************************************************************/
/* */
/* INDEX NILAI EKSTRIM */
/* */
/***************************************************************/
ElmtType IdxValMax(TabInt T){
    /* Mengirimkan index nilai maksimum TabInt T. */
    /* Pre Condition : Tabel tidak kosong. */
    /*Kamus Lokasl*/

    ElmtType indexMax; /*index nilai maksimum*/
    int i; /*counter*/
    /*Algoritma*/

    indexMax=IdxMin;
    for(i=IdxMin+1;i<=T.NEff;i++){
        if(T.TI[i]>indexMax){
            indexMax=i;
        }
    }  
    return indexMax;
}
ElmtType IdxValMin(TabInt T){
    /* Mengirimkan index nilai minimum TabInt T. */
    /* Pre Condition : Tabel tidak kosong. */
    /*Kamus Lokasl*/

    ElmtType indexMin; /*nilai minimum*/
    int i; /*counter*/

    /*Algoritma*/

    indexMin=IdxMin;
    for(i=IdxMin+1;i<=T.NEff;i++){
        if(T.TI[i]<indexMin){
            indexMin=i;
        }
    }
    return indexMin;
}
#endif