// ======================================================
// Nama Program: mtstack.c
// Deskripsi   : driver ADT Tstack
// NIM/Nama    : 24060124120024/Ruth Septriana Sipangkar
// Tanggal     : 27/09/2025
// ======================================================
#include <stdio.h>
#include "tstack.h"
#include "boolean.h"

int main() {
	// Kamus
	Tstack A;
	char x;
	int N;
	
	// Algoritma
	printf("======== ADT STACK ========\n");

	createStack(&A);
	printStack(A);

	push(&A, 'a');
	push(&A, 'y');
	push(&A, 'a');
	push(&A, 'm');
	printStack(A);
	viewStack(A);

	pop(&A, &x);
	viewStack(A);
	pop(&A, &x);
	viewStack(A);
	pop(&A, &x);
	viewStack(A);
	push(&A, 'y');
	viewStack(A);
	push(&A, 'a');
	viewStack(A);
	push(&A, 'm');
	viewStack(A);

	printf("\nISI STACK\n");
	printf("Masukkan jumlah huruf yang ingin dimasukkan (N): ");
	scanf("%d", &N);
	printf("Masukkan huruf sebanyak N (pisahkan spasi): ");
	pushN(&A, N);
	viewStack(A);

	printf("\nPOLINDROM\n");
    char kata[30] = "kasurrusak";
	printf("%s isPalindrom: %s\n", kata, isPalindrom(kata) ? "True" : "False");
	char kata1[30] = "ayambakar";
	printf("%s isPalindrom: %s\n", kata1, isPalindrom(kata1) ? "True" : "False");
	
	printf("Cek kata palindrom: ");
	char kata0[30];
	scanf("%s", kata0);
	printf("%s isPalindrom: %s\n", kata0, isPalindrom(kata0) ? "True" : "False");
	
	return 0;
}
