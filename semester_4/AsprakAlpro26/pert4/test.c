#include <stdio.h>

int main() {
    // int a[5];
    // a[5] = 9;
    // printf("%d", a[5]);

    int T[5];
    for(int i = 0; i < 5; i++) {
        scanf("%d", &T[i]);
    }

    for(int i = 0; i < 5; i++) {
        printf("%d", T[i]);
    }
}