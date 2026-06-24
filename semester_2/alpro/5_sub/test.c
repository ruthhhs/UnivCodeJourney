#include <stdio.h>
int main() {
    int num = 5;
    printf("Num bernilai %d dengan alamat %p.\n", num, &num);

    int* P = &num;
    printf("Isi %p adalah %d.\n", P, *P);

    num = 7;
    printf("Isi %p adalah %d.\n", P, *P);

    *P = 8;
    printf("Num bernilai %d\n", num);

    return 0;
}
