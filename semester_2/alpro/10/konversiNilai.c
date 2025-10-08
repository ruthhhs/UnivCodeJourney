#include<stdio.h>

int main(){
    int N=100;
    int tabNilai[N]; // array of integer
    printf("Masukkan tabel nilai:\n");
    for(int i=0; i<N; i++){
        scanf("%d", &tabNilai[i]);
    }

    float rata=0;
    char tabKonversi[N]; // array of string
    printf("Konversi nilai dalam skala huruf:\n");
    for(int i=0; i<N; i++){
        if(tabNilai[i]>=80){
            tabKonversi[i]='A';
        } else if(tabNilai[i]>=70){
            tabKonversi[i]='B';
        } else if(tabNilai[i]>=55){
            tabKonversi[i]='C';
        } else if(tabNilai[i]>=40){
            tabKonversi[i]='D';
        } else if(tabNilai[i]<40){
            tabKonversi[i]='E';
        } 
        rata += tabNilai[i];
        printf("%c ", tabKonversi[i]);
    }
    rata = (float)rata/N;
    printf("\nRata-rata nilai adalah %f.", rata);
}