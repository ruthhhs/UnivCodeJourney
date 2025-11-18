// ===============================================================================
// Nama Program: list2.c
// Deskripsi   : aplikasi driver ADT list berkait representasi fisik pointer
// NIM/Nama    : 24060124120024/Ruth Septriana Sipangkar
// Tanggal     : 13 November 2025
// ================================================================================
#include <stdio.h>
#include <stdlib.h>
#include "list2.h"
int main()
{ //kamus
  address P, A, B;
  infotype V;
  List2 Senarai;
  
  //algoritma
  printf("================== SENARAI 2 START! ===================\n");

  CreateList(&Senarai);
  printf("\nCreate Senarai!\n");
  PrintList(Senarai);
  printf("IsEmptyList : %s\n", IsEmptyList(Senarai) ? "True" : "False");
  printf("IsOneElm    : %s\n", IsOneElm(Senarai) ? "True" : "False");
  printf("NbElm       : %d\n", NbElm(Senarai));
  
  printf("\n============ SENARAI INSERT AND DELETE =============\n");
  InsertVFirst(&Senarai, 'A');
  printf("\nAdd A as First!\n");
  PrintList(Senarai);
  printf("IsEmptyList : %s\n", IsEmptyList(Senarai) ? "True" : "False");
  printf("IsOneElm    : %s\n", IsOneElm(Senarai) ? "True" : "False");
  printf("NbElm       : %d\n", NbElm(Senarai));

  InsertVFirst(&Senarai, 'B');
  printf("\nAdd B as First!\n");
  PrintList(Senarai);
  printf("IsEmptyList : %s\n", IsEmptyList(Senarai) ? "True" : "False");
  printf("IsOneElm    : %s\n", IsOneElm(Senarai) ? "True" : "False");
  printf("NbElm       : %d\n", NbElm(Senarai));

  DeleteVFirst(&Senarai, &V);
  printf("\nDelete '%c' from First!\n", V);
  PrintList(Senarai);
  printf("IsEmptyList : %s\n", IsEmptyList(Senarai) ? "True" : "False");
  printf("IsOneElm    : %s\n", IsOneElm(Senarai) ? "True" : "False");
  printf("NbElm       : %d\n", NbElm(Senarai));

  InsertVLast(&Senarai, 'C');
  printf("\nAdd C as Last!\n");
  PrintList(Senarai);
  printf("IsEmptyList : %s\n", IsEmptyList(Senarai) ? "True" : "False");
  printf("IsOneElm    : %s\n", IsOneElm(Senarai) ? "True" : "False");
  printf("NbElm       : %d\n", NbElm(Senarai));

  InsertVLast(&Senarai, 'A');
  printf("\nAdd A as Last!\n");
  PrintList(Senarai);
  printf("IsEmptyList : %s\n", IsEmptyList(Senarai) ? "True" : "False");
  printf("IsOneElm    : %s\n", IsOneElm(Senarai) ? "True" : "False");
  printf("NbElm       : %d\n", NbElm(Senarai));

  DeleteVLast(&Senarai, &V);
  printf("\nDelete '%c' from Last!\n", V);
  PrintList(Senarai);
  printf("IsEmptyList : %s\n", IsEmptyList(Senarai) ? "True" : "False");
  printf("IsOneElm    : %s\n", IsOneElm(Senarai) ? "True" : "False");
  printf("NbElm       : %d\n", NbElm(Senarai));

  printf("\n============== SENARAI MORE FUNCTIONS ==============\n");

  InsertVLast(&Senarai, 'E');
  InsertVLast(&Senarai, 'A');
  InsertVLast(&Senarai, 'C');
  InsertVLast(&Senarai, 'D');
  printf("\nSenarai Upgrade Version!\n");
  PrintList(Senarai);
  printf("IsEmptyList : %s\n", IsEmptyList(Senarai) ? "True" : "False");
  printf("IsOneElm    : %s\n", IsOneElm(Senarai) ? "True" : "False");
  printf("NbElm       : %d\n", NbElm(Senarai));

  SearchX(Senarai, 'A', &A);
  printf("\nSearching A's location ...\n");
  if (A != NIL){printf("It is on: %p\n", A);}
  else {printf("Not found\n");}

  SearchX(Senarai, 'B', &A);
  printf("\nSearching B's location ...\n");
  if (A != NIL){printf("It is on: %p\n", A);}
  else {printf("Not found\n");}

  SearchX(Senarai, 'C', &A);
  printf("\nSearching C's location ...\n");
  if (A != NIL){printf("It is on: %p\n", A);}
  else {printf("Not found\n");}

  SearchX(Senarai, 'D', &A);
  printf("\nSearching D's location ...\n");
  if (A != NIL){printf("It is on: %p\n", A);}
  else {printf("Not found\n");}

  SearchX(Senarai, 'E', &A);
  printf("\nSearching E's location ...\n");
  if (A != NIL){printf("It is on: %p\n", A);}
  else {printf("Not found\n");}

  SearchX(Senarai, 'X', &A);
  printf("\nSearching X's location ...\n");
  if (A != NIL){printf("It is on: %p\n", A);}
  else {printf("Not found\n");}

  UpdateX(&Senarai, 'A', 'X');
  printf("\nChange (the first) A into X!\n", V);
  PrintList(Senarai);
  printf("IsEmptyList : %s\n", IsEmptyList(Senarai) ? "True" : "False");
  printf("NbElm       : %d\n", NbElm(Senarai));

  UpdateX(&Senarai, 'A', 'X');
  printf("\nChange (the first) A into X!\n", V);
  PrintList(Senarai);
  printf("IsEmptyList : %s\n", IsEmptyList(Senarai) ? "True" : "False");
  printf("NbElm       : %d\n", NbElm(Senarai));

  UpdateX(&Senarai, 'D', 'Y');
  printf("\nChange (the first) D into Y!\n", V);
  PrintList(Senarai);
  printf("IsEmptyList : %s\n", IsEmptyList(Senarai) ? "True" : "False");
  printf("NbElm       : %d\n", NbElm(Senarai));

  DeleteX(&Senarai, 'C');
  printf("\nDeleteX (the first) C!\n");
  PrintList(Senarai);
  printf("IsEmptyList : %s\n", IsEmptyList(Senarai) ? "True" : "False");
  printf("IsOneElm    : %s\n", IsOneElm(Senarai) ? "True" : "False");
  printf("NbElm       : %d\n", NbElm(Senarai));

  DeleteX(&Senarai, 'X');
  printf("\nDeleteX (the first) X!\n");
  PrintList(Senarai);
  printf("IsEmptyList : %s\n", IsEmptyList(Senarai) ? "True" : "False");
  printf("IsOneElm    : %s\n", IsOneElm(Senarai) ? "True" : "False");
  printf("NbElm       : %d\n", NbElm(Senarai));

  DeleteX(&Senarai, 'Y');
  printf("\nDeleteX (the first) Y!\n");
  PrintList(Senarai);
  printf("IsEmptyList : %s\n", IsEmptyList(Senarai) ? "True" : "False");
  printf("IsOneElm    : %s\n", IsOneElm(Senarai) ? "True" : "False");
  printf("NbElm       : %d\n", NbElm(Senarai));

  Invers(&Senarai);
  printf("\nInvers Senarai!\n");
  PrintList(Senarai);
  printf("IsEmptyList : %s\n", IsEmptyList(Senarai) ? "True" : "False");
  printf("IsOneElm    : %s\n", IsOneElm(Senarai) ? "True" : "False");
  printf("NbElm       : %d\n", NbElm(Senarai));

  printf("\n============ SENARAI MORE-MORE FUNCTIONS ============\n");

  InsertVLast(&Senarai, 'E');
  InsertVLast(&Senarai, 'A');
  InsertVLast(&Senarai, 'D');
  printf("\nSenarai Upgrade Version!\n");
  PrintList(Senarai);
  printf("IsEmptyList : %s\n", IsEmptyList(Senarai) ? "True" : "False");
  printf("IsOneElm    : %s\n", IsOneElm(Senarai) ? "True" : "False");
  printf("NbElm       : %d\n", NbElm(Senarai));

  printf("\nCount A in Senarai: %d\n", CountX(Senarai, 'A'));
  printf("Count B in Senarai: %d\n", CountX(Senarai, 'B'));
  printf("Count C in Senarai: %d\n", CountX(Senarai, 'C'));
  printf("Count D in Senarai: %d\n", CountX(Senarai, 'D'));
  printf("Count E in Senarai: %d\n", CountX(Senarai, 'E'));
  printf("Count X in Senarai: %d\n", CountX(Senarai, 'X'));

  printf("\nCount Vocals in Senarai: %d\n", CountVocal(Senarai));

  printf("\nFrequency of A in senarai : %f\n", FrekuensiX(Senarai, 'A'));
  printf("Frequency of B in senarai : %f\n", FrekuensiX(Senarai, 'B'));
  printf("Frequency of C in senarai : %f\n", FrekuensiX(Senarai, 'C'));
  printf("Frequency of D in senarai : %f\n", FrekuensiX(Senarai, 'D'));
  printf("Frequency of E in senarai : %f\n", FrekuensiX(Senarai, 'E'));
  printf("Frequency of X in senarai : %f\n", FrekuensiX(Senarai, 'X'));

  printf("\n");
  SearchAllX(Senarai, 'A');
  SearchAllX(Senarai, 'B');
  SearchAllX(Senarai, 'C');
  SearchAllX(Senarai, 'D');
  SearchAllX(Senarai, 'E');
  SearchAllX(Senarai, 'X'); 

  printf("\nMode in Senarai : %c\n", Modus(Senarai));
  printf("Mode count      : %d\n", MaxMember(Senarai));

  InsertVLast(&Senarai, 'N');
  InsertVLast(&Senarai, 'N');
  InsertVLast(&Senarai, 'G');
  printf("\nSenarai Upgrade Version!\n");
  PrintList(Senarai);
  printf("IsEmptyList : %s\n", IsEmptyList(Senarai) ? "True" : "False");
  printf("IsOneElm    : %s\n", IsOneElm(Senarai) ? "True" : "False");
  printf("NbElm       : %d\n", NbElm(Senarai));

  printf("\nCount NG in Senarai: %d\n", CountNG(Senarai));

  InsertVAfterX(&Senarai, 'A', 'E');
  printf("\nAdd E after A!\n");
  PrintList(Senarai);
  printf("IsEmptyList : %s\n", IsEmptyList(Senarai) ? "True" : "False");
  printf("IsOneElm    : %s\n", IsOneElm(Senarai) ? "True" : "False");
  printf("NbElm       : %d\n", NbElm(Senarai));

  InsertVBeforeX(&Senarai, 'G', 'B');
  printf("\nAdd B before D!\n");
  PrintList(Senarai);
  printf("IsEmptyList : %s\n", IsEmptyList(Senarai) ? "True" : "False");
  printf("IsOneElm    : %s\n", IsOneElm(Senarai) ? "True" : "False");
  printf("NbElm       : %d\n", NbElm(Senarai));

  DeleteVAfterX(&Senarai, 'C', &V);
  printf("\nDelete %c after C!\n", V);
  PrintList(Senarai);
  printf("IsEmptyList : %s\n", IsEmptyList(Senarai) ? "True" : "False");
  printf("IsOneElm    : %s\n", IsOneElm(Senarai) ? "True" : "False");
  printf("NbElm       : %d\n", NbElm(Senarai));

  DeleteVBeforeX(&Senarai, 'B', &V);
  printf("\nDelete %c before B!\n", V);
  PrintList(Senarai);
  printf("IsEmptyList : %s\n", IsEmptyList(Senarai) ? "True" : "False");
  printf("IsOneElm    : %s\n", IsOneElm(Senarai) ? "True" : "False");
  printf("NbElm       : %d\n", NbElm(Senarai));

  DeleteAllX(&Senarai, 'E');
  printf("\nDelete all E!\n");
  PrintList(Senarai);
  printf("IsEmptyList : %s\n", IsEmptyList(Senarai) ? "True" : "False");
  printf("IsOneElm    : %s\n", IsOneElm(Senarai) ? "True" : "False");
  printf("NbElm       : %d\n", NbElm(Senarai));
  return 0;
}
