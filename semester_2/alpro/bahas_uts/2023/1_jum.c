#include <stdio.h>

int main() {
    int jum=0;

    for (int i=1; i<=4; i++){
        if (i %2 ==0){ // i genap
            for (int j=1; j<=i; j++){
                jum += i+j;
                printf("i= %d (genap)  --> jumlah= %d+%d = %d\n", i, i, j, jum);
            }
        } else { // i ganjil
            jum += i+1;
            printf("i= %d (ganjil) --> jumlah= %d+1 = %d\n", i, i, jum);
        }
    }

    printf("jumlah akhir= %d", jum);
  return 0;
}