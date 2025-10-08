#include<stdio.h>

int main(){
    int nMK; // jlh (elemen array) mata kuliah
    int MKx; // mata kuliah tambahan
    scanf("%d %d", &nMK, &MKx);

    int ada=0; // false
    int tabMK[nMK]; // array berisi mata kuliah
    for(int i=0; i<nMK; i++){
        scanf("%d", &tabMK[i]);
        if(tabMK[i]==MKx){
            ada=1; // true
        }
    }

    if(ada==0){
        printf("Penambahan MK baru: %d\nTabel baru:\n", MKx);
        nMK +=1;
        tabMK[nMK-1]=MKx;
        for(int i=0; i<nMK; i++){
            printf("%d ", tabMK[i]);
        }
    } else {
        printf("Tidak ada penambahan MK baru");
    }
}