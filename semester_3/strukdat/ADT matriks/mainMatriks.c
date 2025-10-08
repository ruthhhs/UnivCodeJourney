// ======================================================
// Nama Program: mainMatriks.c
// Deskripsi   : driver ADT matriks integer
// NIM/Nama    : 24060124120024/Ruth Septriana Sipangkar
// Tanggal     : 18 Sept 2025
// ======================================================
#include <stdio.h>
#include "matriks.h" 
#include "boolean.h"
#include <stdlib.h>
#include <time.h>

int main() {
	// kamus
	Matriks M0, Mrand, M1, M2, M3, M4;
	int x, y, row, col;

	// algoritma
	printf("========== ADT MATRIKS ===========\n");

	printf("\nKONSTRUKTOR\n");
	// printf("\nMatriks M0 (isi sendiri)\n");
	// printf("Masukkan baris(x) dan kolom(y) (pisahkan sapsi): ");
	// scanf("%d %d", &x, &y);
	// printf("Masukkan elemen matriks dengan jumlah baris x kolom (pisahkan sapsi): \n");
	// populateMatriks(&M0, x, y);
	// printMatriks(M0);
	// viewMatriks(M0);

	printf("\nMatriks M1 (diisi dengan prosedur mutasi addX)\n");
	initMatriks(&M1);
	addX(&M1, 1, 0, 0);
	addX(&M1, 2, 0, 1);
	addX(&M1, 3, 0, 2);
	addX(&M1, 4, 1, 0);
	addX(&M1, 5, 1, 1);
	addX(&M1, 6, 1, 2);
	printMatriks(M1);
	viewMatriks(M1);
	
	printf("\nMatriks M2 (kosong)\n");
	initMatriks(&M2);
	printMatriks(M2);
	viewMatriks(M2);
	
	printf("\nPREDIKAT\n\n");
	printf("isEmptyMatriks M1: %s\n", isEmptyMatriks(M1) ? "True" : "False");
	printf("isEmptyMatriks M2: %s\n", isEmptyMatriks(M2) ? "True" : "False");
	printf("isFullMatriks M1: %s\n", isFullMatriks(M1) ? "True" : "False");
	printf("isFullMatriks M2: %s\n", isFullMatriks(M2) ? "True" : "False");
	
	printf("\nMUTATOR\n");
	printf("\nMatriks M3 (identitas)\n");
	initMatriks(&M3);
	isiMatriksIdentitas(&M3, 5);
	printMatriks(M3);
	viewMatriks(M3);
	
	printf("\nMatriks random Mrand\n");
	initMatriks(&Mrand);
	srand(time(0));
	isiMatriksRandom(&Mrand, 3, 3);
	printMatriks(Mrand);
	viewMatriks(Mrand);

	printf("\nMatriks M2 (setelah di isi dengan addX)\n");
	addX(&M2, 1, 0, 0);
	addX(&M2, 2, 0, 1);
	addX(&M2, 3, 1, 0);
	addX(&M2, 4, 1, 1);
	addX(&M2, 5, 2, 0);
	addX(&M2, 6, 2, 1);
	printMatriks(M2);
	viewMatriks(M2);

	printf("\nMatriks M4 (di isi dengan addX)\n");
	initMatriks(&M4);
	addX(&M4, 3, 0, 0);
	addX(&M4, 6, 0, 1);
	addX(&M4, 9, 1, 0);
	addX(&M4, 3, 1, 1);
	addX(&M4, 4, 2, 0);
	addX(&M4, 7, 2, 1);
	addX(&M4, 0, 3, 0);
	printMatriks(M4);
	viewMatriks(M4);

	printf("\nMatriks M4 (delX)\n");
	delX(&M4, 0);
	printMatriks(M4);
	viewMatriks(M4);


	printf("\nSELEKTOR\n");
	printf("Baris M1: %d\n",getNBaris(M1));
	printf("Kolom M1: %d\n", getNKolom(M1));
	printf("Baris M2: %d\n",getNBaris(M2));
	printf("Kolom M2: %d\n", getNKolom(M2));
	printf("Baris M3: %d\n",getNBaris(M3));
	printf("Kolom M3: %d\n", getNKolom(M3));
	printf("Baris M4: %d\n",getNBaris(M4));
	printf("Kolom M4: %d\n", getNKolom(M4));

	printf("\nOPERASI ARITMATIKA\n");
	Matriks M5 = addMatriks(M4, M2);
	printf("\nMatriks M5 (M4 add M2)\n");
	printMatriks(M5);
	viewMatriks(M5);

	Matriks M6 = subMatriks(M4, M2);
	printf("\nMatriks M6 (M4 sub M2)\n");
	printMatriks(M6);
	viewMatriks(M6);

	Matriks M7 = kaliMatriks(M1, M2);
	printf("\nMatriks M7 (M1 kali M2)\n");
	printMatriks(M7);
	viewMatriks(M7);

	Matriks M8 = kaliSkalarMatriks(M1, 2);
	printf("\nMatriks M8 (M1 kali skalar 2)\n");
	printMatriks(M8);
	viewMatriks(M8);

	printf("\nOPERASI LAINNYA\n");

	printf("\nOPERASI PENCARIAN\n");
	searchX(M4, 7, &row, &col);
	printf("Angka 7 di M4 ditemukan di row %d dan col %d\n", row, col);
	printf("Jumlah angka 1 di M3(identitas): %d\n", countX(M3, 1));

	return 0;
}
