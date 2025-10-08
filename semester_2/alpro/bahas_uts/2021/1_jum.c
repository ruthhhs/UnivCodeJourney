#include<stdio.h>

int main(){
    int jum=0;

    for(int i=1; i<=5; i++){
        if (i%2==0){ //genap
            if (i%4==0){
                jum += i;
                printf("i=%d (genap, mod4)  --> jumlah=%d\n", i, jum);
            } else{ // ganjil
                jum += 2*i;
                printf("i=%d (genap, !mod4) --> jumlah=%d\n", i, jum);
            }
        } else {
            jum += jum*i*i;
            printf("i=%d (ganjil)       --> jumlah =%d\n", i, jum);
        }
    }

    printf("%d", jum);
}