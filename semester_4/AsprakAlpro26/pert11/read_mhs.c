#include <stdio.h>

int main() {
    /* Kamus */
    FILE *file;
    int nim, nilai;
    char nama[50];

    /* Algoritma */
    file = fopen("mahasiswa.txt", "r");

    if (file == NULL) {
        printf("File tidak ditemukan.\n");
        return 1;
    }

    fscanf(file, "%d %s %d", &nim, nama, &nilai);

    while (nim != 99999) {
        printf("NIM : %d\n", nim);
        printf("Nama : %s\n", nama);
        printf("Nilai : %d\n\n", nilai);
        fscanf(file, "%d %s %d", &nim, nama, &nilai);
    }

    fclose(file);
    return 0;
}