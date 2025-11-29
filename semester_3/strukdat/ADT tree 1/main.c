// ================================================================================
// Nama Program: main.c
// Deskripsi   : ADT bintree berkait dengan representasi fisik pointer
// NIM/Nama    : 24060124120024/Ruth Septriana Sipangkar
// Tanggal     : 27 November 2025
// ================================================================================
#include "pohon1.h"

int main()
{//kamus
    bintree B, kiri, kanan;

 //algirtma
     printf("========== POHON FUNCTION ==========\n");
     printf("\nBUAT POHON\n");
    B = Tree('T',
             Tree('I',
                  Tree('N',NIL,NIL),
                  Tree('F',
                       Tree('O',NIL,NIL),
                       NIL)),
             Tree('R',
                  Tree('M',
                       Tree('A',NIL,NIL),
                       Tree('T',NIL,NIL)),
                  Tree('I',
                       NIL,
                       Tree('K',
                            NIL,
                            Tree('A',NIL,NIL))))
            );

     PrintPrefix(B);
     printf("\nIsEmptyTree : %s\n", IsEmptyTree(B) ? "True" : "False");
     printf("IsDaun      : %s\n", IsDaun(B) ? "True" : "False");
     printf("IsBiner     : %s\n", IsBiner(B) ? "True" : "False");
     printf("IsUnerLeft  : %s\n", IsUnerLeft(B) ? "True" : "False");
     printf("IsUnerRight : %s\n", IsUnerRight(B) ? "True" : "False");
     printf("NbElm       : %d\n", NbElm(B));
     printf("NbDaun      : %d\n", NbDaun(B));
     printf("Tinggi      : %d\n", Tinggi(B));

     printf("\n\nDAHAN KIRI\n");
     kiri = GetLeft(B);
     PrintPrefix(kiri);
     printf("\nIsEmptyTree : %s\n", IsEmptyTree(kiri) ? "True" : "False");
     printf("IsDaun      : %s\n", IsDaun(kiri) ? "True" : "False");
     printf("IsBiner     : %s\n", IsBiner(kiri) ? "True" : "False");
     printf("IsUnerLeft  : %s\n", IsUnerLeft(kiri) ? "True" : "False");
     printf("IsUnerRight : %s\n", IsUnerRight(kiri) ? "True" : "False");
     printf("NbElm       : %d\n", NbElm(kiri));
     printf("NbDaun      : %d\n", NbDaun(kiri));
     printf("Tinggi      : %d\n", Tinggi(kiri));

     printf("\n\nDAHAN KANAN\n");
     kanan = GetRight(B);
     PrintPrefix(kanan);
     printf("\nIsEmptyTree : %s\n", IsEmptyTree(kanan) ? "True" : "False");
     printf("IsDaun      : %s\n", IsDaun(kanan) ? "True" : "False");
     printf("IsBiner     : %s\n", IsBiner(kanan) ? "True" : "False");
     printf("IsUnerLeft  : %s\n", IsUnerLeft(kanan) ? "True" : "False");
     printf("IsUnerRight : %s\n", IsUnerRight(kanan) ? "True" : "False");
     printf("NbElm       : %d\n", NbElm(kanan));
     printf("NbDaun      : %d\n", NbDaun(kanan));
     printf("Tinggi      : %d\n", Tinggi(kanan));

     printf("\nSearchX ('K') : %s\n", SearchX(B, 'A') ? "True" : "False");
     printf("SearchX ('C') : %s\n", SearchX(B, 'B') ? "True" : "False");

     printf("\nUbah K menjadi C\nPohon sebelum:\n");
     PrintPrefix(B);
     UpdateX(&B, 'K', 'C');
     printf("\nPohon sesudah:\n");
     PrintPrefix(B);

     printf("\n\n========== POHON MORE FUNCTION ==========\n");

     printf("\nPrintPrefixRingkas\n");
     PrintPrefixRingkas(B);

     printf("\n\nCountX (A)   : %d\n", CountX(B, 'A'));
     printf("CountX (M)   : %d\n", CountX(B, 'M'));
     printf("CountX (E)   : %d\n", CountX(B, 'E'));

     printf("\nIsSkewLeft   : %s\n", IsSkewLeft(B) ? "True" : "False");
     printf("IsSkewRight  : %s\n", IsSkewRight(B) ? "True" : "False");
     printf("IsSkewLeft (I) pertama : %s\n", IsSkewLeft(kiri) ? "True" : "False");
     printf("IsSkewRight (I) kedua  : %s\n", IsSkewRight(GetRight(kanan)) ? "True" : "False");

     printf("\nLevelX (T)   : %d\n", LevelX(B, 'T'));
     printf("LevelX (A)   : %d\n", LevelX(B, 'A'));
     printf("LevelX (K)   : %d\n", LevelX(B, 'K'));

     printf("\nCountLevel (1)   : %d\n", CountLevel(B, 1));
     printf("CountLevel (4)   : %d\n", CountLevel(B, 4));
     printf("CountLevel (2)   : %d\n", CountLevel(B, 2));
     printf("CountLevel (0)   : %d\n", CountLevel(B, 0));

     printf("\nPrintLevel (1)   :");
     PrintLevel(B, 1);
     printf("\n");
     printf("PrintLevel (4)   :");
     PrintLevel(B, 4);
     printf("\n");
     printf("PrintLevel (2)   :");
     PrintLevel(B, 2);
     printf("\n");
     printf("PrintLevel (0)   :");
     PrintLevel(B, 0);
     printf("\n");

     printf("\nGetDaunTerkiri   : %c\n", GetDaunTerkiri(B));

     printf("\nFrekuensiX (A)   : %f\n", FrekuensiX(B, 'A'));
     printf("FrekuensiX (M)   : %f\n", FrekuensiX(B, 'M'));
     printf("FrekuensiX (E)   : %f\n", FrekuensiX(B, 'E'));

     printf("\nCountVocal    : %d\n", CountVocal(B));
     printf("PrintVocal    :");
     PrintVocal(B);
     printf("\n");

     printf("\nCountConsonant : %d\n", CountConsonant(B));
     printf("PrintConsonant :");
     PrintConsonant(B);
     printf("\n");


    return 0;
}
