#include <stdio.h>

int main(){
    int jum=0;
    int jlh=0; // berapa kali jum += i*j dieksekusi

    for (int i=1; i<=3; i++){
        for (int j=i; j<=3; j++)
            if (i%2==1){
                jum += i*j;
                printf("jumlah += %d*%d --> %d\n", i, j, jum);
                jlh++;
        }
    }
    printf("%d", jlh);
}