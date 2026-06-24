#include <stdio.h>

int main() {
    /* Kamus */
    FILE *file;
    int nim, nilai;
    char nama[50];

    /* Algoritma */
    file = fopen("mahasiswa.txt", "w");

    if (file == NULL) {
        printf("File gagal dibuat.\n");
    return 1;
    }

    printf("Masukkan NIM, 99999 untuk berhenti: ");
    scanf("%d", &nim);

    while (nim != 99999) {
        printf("Masukkan nama: ");
        scanf("%s", nama);
        printf("Masukkan nilai: ");
        scanf("%d", &nilai);

        fprintf(file, "%d %s %d\n", nim, nama, nilai);

        printf("\nMasukkan NIM, 99999 untuk berhenti: ");
        scanf("%d", &nim);
    }

    fprintf(file, "%d %s %d\n", 99999, "MARK", 0);

    fclose(file);
    return 0;
}