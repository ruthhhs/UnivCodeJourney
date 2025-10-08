#include <stdio.h>
#include<stdbool.h>
// kamus global
const int N = 100; //panjang t1 dan t2 selalu 100 (dari soal)

//subprogram
void ceksimetri(int t1[], int t2[]){
    bool simetri = true; 

    for (int i=0; i<N; i++){
        if (t1[i] != t2[i]){
            simetri = false; 
        }
    }
    if (simetri){
        printf("TRUE");
    } else {
        printf("FALSE");
    }
}

 // program utama
int main(){
    int t1[N], t2[N];
    for (int i=0; i<N; i++){
        scanf("%d", &t1[i]);
    }
    for (int i=0; i<N; i++){
        scanf("%d", &t2[i]);
    }

    ceksimetri(t1, t2); // mengecek di subprogram
    return 0;
}