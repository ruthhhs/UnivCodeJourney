#include <stdio.h>
#include <string.h>

#ifndef MESINKARAKTER_H
#define MESINKARAKTER_H

/*Kamus Lokal*/
#define N 100 /*Ganti sesuai kebutuhan panjang string*/
int CI = 0;
char CC;
char str[N + 1];

/*START()
Inisialisasi pita dan CC*/
void START() {
   printf("Masukkan pita: ");
   fgets(str, N, stdin);

   size_t len = strlen(str);
   if (str[len - 1] == '\n') {
      str[len - 1] = '\0';
   }
   
   CI = 0;
   CC = str[CI];

   return;
}

/*ADV()
Maju satu karakter*/
void ADV() {
   CI++;
   CC = str[CI];
}

/*EOP()
Apakah sudah berada di akhir pita?*/
int EOP() {
   return CC == '\0';
}

#endif