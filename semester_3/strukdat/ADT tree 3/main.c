// ================================================================================
// Nama Program: main.c
// Deskripsi   : ADT bintree3 dengan representasi fisik pointer
// NIM/Nama    : 24060124120024/Ruth Septriana Sipangkar
// Tanggal     : 11 Desember 2025
// ================================================================================
#include <stdio.h>
#include <stdlib.h>
#include "pohon3.h"

int main() {
    //kamus
    bintree3 W;
    
    //algoritma
    printf("========== POHON 3 ==========\n");
    W = Tree3(NIL,'A',false,
              Tree3(W,'B',false, 
                    NIL, 
                    Tree3(left(W),'D',false,NIL,NIL)),
              Tree3(W,'C',false, 
                    Tree3(right(W),'E',false,NIL,NIL),
                    Tree3(right(W),'F',false,NIL,NIL)));

    printf("\nPrint DFS:\n");
//     printDFS(W);

    printf("\n\nPrint BFS:\n");
    PrintBFS(W);

    printf("\n\nTinggi      : %d\n", Tinggi(W));

    printf("\nPrintLevel (1)   :");
    PrintLevel(W, 1);
    printf("\nPrintLevel (2)   :");
    PrintLevel(W, 2);
    printf("\nPrintLevel (3)   :");
    PrintLevel(W, 3);
    printf("\nPrintLevel (0)   :");
    PrintLevel(W, 0);

    printf("\n\nIsEmptyTree : %s\n", IsEmptyTree(W) ? "True" : "False");
    printf("IsDaun      : %s\n", IsDaun(W) ? "True" : "False");
    printf("IsBiner     : %s\n", IsBiner(W) ? "True" : "False");
    printf("IsUnerLeft  : %s\n", IsUnerLeft(W) ? "True" : "False");
    printf("IsUnerRight : %s\n", IsUnerRight(W) ? "True" : "False");

    printf("\nNbElmTree      : %d\n", NbElmTree(W));
    printf("NbDaun         : %d\n", NbDaun(W));
    printf("Level          : %d\n", Level(W));
    printf("CountLevelT(1) : %d\n", CountLevelT(W, 1));
    printf("CountLevelT(2) : %d\n", CountLevelT(W, 2));
    printf("CountLevelT(3) : %d\n", CountLevelT(W, 3));

    printf("\n========== PENELUSURAN ==========\n");

    resetVisited(W);
    printf("\nprintPathX (B):\n");
    printPathX(W, 'B');

    resetVisited(W);
    printf("\nprintPathDaunX (E):\n");
    printPathDaunX(W, 'E');

    resetVisited(W);
    printf("\nprintAllPaths:\n");
    printAllPaths(W);

    return 0;
}