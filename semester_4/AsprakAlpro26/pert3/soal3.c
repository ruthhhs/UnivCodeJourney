#include <stdio.h>

int main() {
    int angka;
    int i;
    int a = 0;
    printf("Angka: ");
    scanf("%d", &angka);
    for (i =1;i<=angka;i++){
        if(angka%i==0){
            a += 1;
        }
    }
    if (a == 2){
        printf("Prima");}
    else{
        printf("Bukan Prima");
    }
}