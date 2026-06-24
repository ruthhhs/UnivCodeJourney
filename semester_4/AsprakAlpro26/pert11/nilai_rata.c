#include <stdio.h>

int main() {
    /* Kamus */
    FILE *file;
    int nim, nilai;
    char nama[50];
    int sumNilai = 0;
    int jumMhs = 0;
    float rata;

    /* Algoritma */
    file = fopen("mahasiswa.txt", "r");

    if (file == NULL) {
        printf("File tidak ditemukan.\n");
        return 1;
    }

    fscanf(file, "%d %s %d", &nim, nama, &nilai);

    while (nim != 99999) {
        sumNilai += nilai;
        jumMhs++;
        fscanf(file, "%d %s %d", &nim, nama, &nilai);
    }

    if (jumMhs == 0) {
        printf("Arsip kosong.\n");
    } else {
        rata = (float) sumNilai / jumMhs;
        printf("Rata-rata nilai = %.2f\n", rata);
    }

    fclose(file);
    return 0;
}