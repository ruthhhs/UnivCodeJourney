#include <stdio.h>

int main(){
    int n, s;
    printf("Masukkan Bilangan :");
    scanf("%d", &n);

    for (int i = 1; i < n; i++)
    {
        if (n % i == 0){
            s += i;
        }
    }
    printf("%d\n", s);
    if (s == n){
        printf("Bilangan Sempurna");
    } else{
        printf("Bukan Bilangan Sempurna");
    }
}