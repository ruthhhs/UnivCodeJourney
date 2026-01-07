// ================================================================================
// Nama Program: list1.c
// Deskripsi   : realisasi body ADT list berkait representasi fisik pointer
// NIM/Nama    : 24060124120024/Ruth Septriana Sipangkar
// Tanggal     : 6 November 2025
// ================================================================================
#include <stdio.h>
#include <stdlib.h>
#include "list1.h"

address Alokasi(infotype E) {
	//kamus lokal
	address P;
	//algoritma
	P = (address) malloc(sizeof(Elm));
	if (P != NIL) {
		info(P) = E;
		next(P) = NIL;
	}
	return P;
}

void Dealokasi (address P) {
	//kamus lokal
	
	//algoritma
	if ( P != NIL ) {
		next(P) = NIL;
	}
	P = NIL;
}

void PrintList(List1 L) {
	//kamus lokal 
	address P;
	//algoritma
	P = First(L);
	printf("Element     : [");
	if (!IsEmptyList(L)) {
		do {
			printf(" %c", info(P));
			P = next(P);
		} while( P != NIL );
	}
	printf(" ]\n");
}

void CreateList (List1 *L){
	// kamus lokal

    // algoritma
    L->First = NIL;
}

boolean IsEmptyList (List1 L){
	// kamus lokal

    // algoritma
    return L.First == NIL;
}

int NbElm(List1 L){
	// kamus lokal
	address p;
	int count;

    // algoritma
    p = L.First;
	count = 0;
	while (p!=NIL) {
		count ++;
		p = p->next;
	}

	return count;
}

void InsertVFirst(List1 *L, infotype V ){
	// kamus lokal
	address p;

    // algoritma
	p = Alokasi(V);
	if (p!=NIL){
		if(!IsEmptyList(*L)){
			p->next = L->First;
			L->First = p;
		}
		else {
			L->First = p;
		}
	}
}

void InsertVLast(List1 *L, infotype V ){
	// kamus lokal
	address p;
	address add;

	// algoritma
	add = Alokasi(V);
	p = L->First;
    if (add != NIL) {
        add->next = NIL;
        if (IsEmptyList(*L)) {
            L->First = add;
        } else {
            while (p->next != NIL) {
                p = p->next;
            }
            p->next = add;
		}
    }
}

void DeleteVFirst(List1 *L, infotype *V){
	// kamus lokal
	address p;

    // algoritma
	if (IsEmptyList(*L)){
		*V = '#';
	} else {
		p = L->First;
		*V = p->info;
		L->First = p->next;
		Dealokasi(p);
	}
}

void DeleteVLast(List1 *L, infotype *V){
	// kamus lokal
	address p;
	address del;

    // algoritma
	if (IsEmptyList(*L)){
		*V = '#';
	} else {
		p = L->First;
		if (p->next == NIL){
			*V = p->info;
			L->First = p->next;
			Dealokasi(p);
		} else{
			while (p->next != NIL) {
				del = p;
				p = p->next;
			}
			*V = p->info;
			del->next = NIL;
			Dealokasi(p);
		}
	}
}

void SearchX(List1 L, infotype X, address *A){
	// kamus lokal
	address p;

    // algoritma
	p = L.First;
	*A = NIL;
	while (p!=NIL && *A==NIL){
		if (X == p->info){
			*A = p;
		} else {
			p = p->next;
		}
	}
}

void UpdateX(List1 *L, infotype X, infotype Y){
	// kamus lokal
	address p;

    // algoritma
	p = L->First;
	if (!IsEmptyList(*L)){
		while (p!=NIL && p->info != X){
			p = p->next;
		}
		if (p->info = X){
			p->info = Y;
		}
	}
}

void Invers(List1 *L){
    // kamus lokal
    address prev, curr, next;

    // algoritma
    if (!IsEmptyList(*L)){
        prev = NIL;
        curr = L->First;
        while (curr != NIL){
            next = curr->next;   // simpan pointer ke elemen berikutnya
            curr->next = prev;   // balik arah pointer
            prev = curr;         // geser prev ke elemen sekarang
            curr = next;         // lanjut ke elemen berikutnya
        }
        L->First = prev;         // ubah First jadi elemen terakhir
    }
}

int CountVocal(List1 L){
	// kamus lokal
	address p;
	int count;

    // algoritma
    p = L.First;
	count = 0;
	while (p!=NIL) {
		if(p->info == 'A' || p->info == 'I' || p->info == 'U' || p->info == 'E' || p->info == 'O'){
			count ++;
		}
		p = p->next;
	}
	return count;
}

int CountX(List1 L, infotype X){
	// kamus lokal
	address p;
	int count;

    // algoritma
    p = L.First;
	count = 0;
	while (p!=NIL) {
		if(p->info == X){
			count ++;
		}
		p = p->next;
	}
	return count;
}

float FrekuensiX(List1 L, infotype X){
	// kamus

	// algoritma
	if (NbElm(L) == 0) return 0.0;
	return (float) CountX(L, X) / NbElm(L);
}

void SearchAllX(List1 L, infotype X){
    // kamus lokal
    address p;
    int posisi = 1;
    boolean found = false;

    // algoritma
    if (IsEmptyList(L)){
        printf("List kosong.\n");
    } else {
        p = L.First;
        printf("Elemen '%c' ditemukan pada posisi: ", X);
        while (p != NIL){
            if (p->info == X){
                printf("%d ", posisi);
                found = true;
            }
            p = p->next;
            posisi++;
        }
        if (!found){
            printf("tidak ditemukan.");
        }
        printf("\n");
    }
}

void UpdateAllX(List1 *L, infotype X, infotype Y){
	// kamus lokal
	address p;

    // algoritma
	p = L->First;
	if (!IsEmptyList(*L)){
		while (p!=NIL){
			if (p->info == X){
			p->info = Y;
			}
			p = p->next;
		}
	}
}

void InsertVAfter(List1 *L, infotype V, infotype VA ){
	// kamus lokal
	address p;
	address add;

	// algoritma
	add = Alokasi(VA);
	p = L->First;

    if (add != NIL) {
        add->next = NIL;
		while (p->next!= NIL && p->info != V) {
			p = p->next;
		}

		if(p != NIL){
			add->next = p->next;
			p->next = add;
		}
    }
}

infotype Modus(List1 L){
    // kamus lokal
    address p, q;
    infotype modus;
    int count, maxCount, tempCount;

    // algoritma
    p = L.First;
    modus = '-';
    maxCount = 0;
	tempCount = 0;
    if (!IsEmptyList(L)){
        while (p != NIL){
			tempCount = 0;
            q = L.First;
            while (q != NIL){
                if (q->info == p->info){
                    tempCount++;
                }
                q = q->next;
            }
            if (tempCount > maxCount){
                maxCount = tempCount;
                modus = p->info;
            }
            p = p->next;
        }
    }
    return modus;
}

int NbModus(List1 L){
	// kamus lokal
    address p, q;
    infotype modus;
    int count, maxCount, tempCount;

    // algoritma
    p = L.First;
    modus = '-';
    maxCount = 0;
	tempCount = 0;
    if (!IsEmptyList(L)){
        while (p != NIL){
			tempCount = 0;
            q = L.First;
            while (q != NIL){
                if (q->info == p->info){
                    tempCount++;
                }
                q = q->next;
            }
            if (tempCount > maxCount){
                maxCount = tempCount;
                modus = p->info;
            }
            p = p->next;
        }
    }
    return maxCount;
}

void ConcatList(List1 L1, List1 L2, List1 *L); 

void SplitList(List1 L, List1 *L1, List1 *L2);

void CopyList(List1 L1, List1 *L2);
