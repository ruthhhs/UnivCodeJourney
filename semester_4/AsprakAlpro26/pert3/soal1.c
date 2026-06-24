#include <stdio.h>

int main() {
    int n;
    int p = 0;
    printf("Masukkan nilai :");
    scanf("%d",&n);

    for (int i = 1; i <= n; i++){
        p = p + i;
    }

     printf("%d \n", p);
    
}