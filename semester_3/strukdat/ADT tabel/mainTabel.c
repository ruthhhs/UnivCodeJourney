// ======================================================
// Nama Program: mainTabel.c
// Deskripsi   : driver ADT tabel character
// NIM/Nama    : 24060124120024/Ruth Septriana Sipangkar
// Tanggal     : 11 Sept 2025
// ======================================================
#include <stdio.h>
#include "tabel.h"

int main() {
	// kamus
	Tabel T1, T2, T3, T4;
	int N, i;
	
	// algoritma
	printf("======== ADT TABEL ========\n");

	createTable(&T3);
	printf("Buat tabel sendiri (T3)");
	printf("Masukkan panjang tabel (N): ");
	scanf("%d", &N);
	printf("Ketikkan isi tabel, huruf kapital, pisahkan spasi: ");
	populateTable(&T3, N);
	printTable(T3);
	viewTable(T3);
	
	printf("\n");
	
	printf("INISIALISAI\n");
	createTable(&T1);
	addXTable(&T1,'A');
	addXTable(&T1,'C');
	addXTable(&T1,'A');
	addXTable(&T1,'B');
	createTable(&T2);
	addXTable(&T2,'B');
	addXTable(&T2,'A');
	addXTable(&T2,'C');
	addXTable(&T2,'A');

	printTable(T1);
	viewTable(T1);
	printTable(T2);
	viewTable(T2);

	printf("\nPREDIKAT\n");

	printf("IsEmpty T1: %s\n", isEmptyTable(T1) ? "True" : "False");
	printf("IsFull T1: %s\n", isFullTable(T1) ? "True" : "False");
	printf("IsEqual T1 T2: %s\n", isEqualTable(T1, T2) ? "True" : "False");

	printf("\nOPERATOR\n");
	
	printf("GetSize T1: %d\n", getSize(T1));
	printf("GetSize T2: %d\n", getSize(T2));
	int pos;
	searchX(T1, 'D', &pos);
	searchX(T1, 'C', &pos);
	printf("Jumlah A di T1: %d\n", countX(T1, 'A'));
	printf("Jumlah huruf vokal di T1: %d\n", countVocal(T1));
	printf("Elemen terbanyak (modus) di T1 adalah '%c'\n", Modus(T1));

	printf("\nMUTATOR\n");

	printf("addUniqueXTable T1 'A'\n");
	addUniqueXTable(&T1, 'A');
	viewTable(T1);
	printf("addUniqueXTable T1 'D'\n");
	addUniqueXTable(&T1, 'D');
	viewTable(T1);

	printf("delTable T1 idx 4\n");
	delTable(&T1, 4);
	viewTable(T1);
	printf("delTable T1 idx 2\n");
	delTable(&T1, 1);
	viewTable(T1);

	printf("delXTable T2 'A'\n");
	delXTable(&T2, 'A');
	viewTable(T2);
	printf("delXTable T2 'B'\n");
	delXTable(&T2, 'B');
	viewTable(T2);

	printf("delAllXTable T1 'A'\n");
	delAllXTable(&T1, 'A');
	viewTable(T1);

	printf("\nOPERASI LAINNYA\n");
	viewTable(T3);
	printf("getInverseTable : %s\n", getInverseTable(T3));
	inverseTable(&T3);
	viewTable(T3);
	sortAsc(&T3);
	viewTable(T3);
	sortDesc(&T3);
	viewTable(T3);

	return 0;
}