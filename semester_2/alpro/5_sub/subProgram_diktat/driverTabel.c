/***************************************************************/
/* */
/* Nama File : driverTabel.c */
/* Deskripsi : Driver Abstract Data Type Tabel */
/* */
/***************************************************************/

#include "tabel.c"
#include <stdio.h>

int main(){
    /*Kamus Lokal*/

    TabInt T;

    /*Algoritma*/
    CreateEmpty(&T);
    printf("Index Efektif CreateEmprty(TabInt* T) = %d\n", T.NEff);
    printf("IsIdxValid(TabInt T, IdxType i) = %d\n", IsIdxValid(T, 2000));
    printf("IsIdxEff(TabInt T, IdxType i) = %d\n", IsIdxEff(T, 2));
    printf("IsEmpty(TabInt T) = %d\n", IsEmpty(T));
    printf("IsFull(TabInt T) = %d\n", IsFull(T));
    PrintTabel(T);
    IsiTabel(&T, 10);
    PrintTabel(T);
    printf("ValMax(TabInt T) = %d\n", ValMax(T));
    printf("ValMin(TabInt T)= %d\n", ValMin(T));
    printf("IdxValMax(TabInt T) = %d\n", IdxValMax(T));
    printf("IdxValMin(TabInt T) %d\n", IdxValMin(T));
    return 0;
}   