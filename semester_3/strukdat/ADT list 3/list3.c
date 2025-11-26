// ================================================================================
// Nama Program: list3.c
// Deskripsi   : realisasi body ADT list berkait representasi fisik pointer
// NIM/Nama    : 24060124120024/Ruth Septriana Sipangkar
// Tanggal     : 20 November 2025
// ================================================================================
#include "list3.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

address Alokasi(infotype E) {
    //kamus lokal
    address P;
    //algoritma 
    P = (address) malloc(sizeof(Elm)); 
    if (P != NIL ) {
        info(P) = E;
        next(P) = NIL;
		prev(P) = NIL;
    }
    return P;
}

void Dealokasi (address *P){
    //kamus lokal
	
	//algoritma
	if ( *P != NIL ) {
		next(*P) = NIL;
        prev(*P) = NIL;
	}
	*P = NIL;
}

void CreateList (List3 *L){
    // kamus lokal

    // algoritma
    L->First = NIL;
}

boolean IsEmptyList (List3 L){
    // kamus lokal

    // algoritma
    return L.First == NIL;
}

boolean IsOneElm (List3 L){
    // kamus lokal
    address P;

    // algoritma
    if (!IsEmptyList(L)){
        P = L.First;
        return P->next == NIL && P->prev == NIL;
    } else {
        return false;
    }
}

void PrintList(List3 L){
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

int NbElm(List3 L){
    // kamus lokal
	address p;
	int count;

    // algoritma
    count = 0;
    if (!IsEmptyList(L)){
        p = L.First;
        do {
            count ++;
            p = p->next;
        } while (p != NIL);
    }
	return count;
}

void InsertVFirst(List3 *L, infotype V ){
    // kamus
    address p;

    //algoritma
    p = Alokasi(V);
    if (p!=NIL){
        if(IsEmptyList(*L)){
            L->First = p;
        }
        else { // ada isinya
            p->next = L->First;
            L->First->prev = p;
            L->First = p;
        }
    }
}

void InsertVLast(List3 *L, infotype V ){
    // kamus
    address last, p;

    // algoritma
    p = Alokasi(V);
    if (p != NIL){
        if(IsEmptyList(*L)){
            L->First = p;
        }
        else { // ada isinya
            last = L->First;
            while(last->next != NIL){
                last = last->next;
            }
            last->next = p;
            p->prev = last;
        }
    }
}

void DeleteVFirst(List3 *L, infotype *V){
    // kamus
    address p;

    // algoritma
    if(IsEmptyList(*L)){
        *V = '#'; // asumsi
    } else{ // ada isinya
        p = L->First;
        *V = p->info;
        if(p->next == NIL){ //oneElmt
            L->First = NIL;
        } else{
            L->First = p->next;
            L->First->prev = NIL;
        }
        Dealokasi(&p);
    }
}

void DeleteVLast(List3 *L, infotype *V){
        // kamus
    address p, last;

    // algoritma
    if(IsEmptyList(*L)){
        *V = '#'; // asumsi
    } else{ // ada isinya
        p = L->First;
        *V = p->info;
        if(p->next == NIL){ //oneElmt
            L->First = NIL;
        } else{ // isi >1
            while (p->next != NIL) {
                p = p->next;
            }
            p->prev->next = NIL;
        }
        Dealokasi(&p);
    }
}

void DeleteX(List3 *L, infotype X){
    // kamus
    address p, q, last;

    // algoritma
    if(!IsEmptyList(*L)){
        p = L->First;
        last = L->First;
        while (last->next != NIL){ // cari posisi last
            last = last->next;
        }

        // kondisi
        if(p->next == NIL){ //oneElmt
            if (p->info == X){
                L->First = NIL;
            }
        } else{ // isi >1
            while (p->next != NIL && p->info != X){ // cari posisi X (p)
                q = p;
                p = p->next;
            }

            if(p == L->First){ // p di first
                p->next->prev = NIL;
                L->First = p->next;
            }
            else if (p == last){ // p di last
                q->next = NIL;
            }
            else{ // p di tengah
                q->next = p->next;
                p->next->prev = q;
            }
        }

        // hapus X dari list
        Dealokasi(&p);
    }
}

void SearchX(List3 L, infotype X, address *A){
    // kamus lokal
	address p;

    // algoritma
    *A = NIL;
    if(!IsEmptyList(L)){
        p = L.First;
        do {
            if (X == p->info){
                *A = p;
                break;
            }
            p = p->next;
        } while (p!=NIL);
    }
}

void UpdateX(List3 *L, infotype X, infotype Y){
    // kamus
    address p;

    //algoritma
    if(!IsEmptyList(*L)){
        p = L->First;
        do{
            if(p->info == X){
                p->info = Y;
                break;
            }
            p = p->next;
        } while (p != NIL);
    }
}

void Invers(List3 *L){
    // kamus lokal
    address temp, p, first;

    // algoritma
    if (!IsEmptyList(*L)){
        first = L->First;
        p = first;

        do {
           temp = p->next;
            p->next = p->prev;
            p->prev = temp;
            p = temp; 
        } while (p != first);

        L->First = first->prev;
    }
}

// =======================================
void InsertVAfterX(List3 *L, infotype X, infotype V){
    // kamus
    address p, v, temp;

    // algoritma
    if(!IsEmptyList(*L)){
        v = Alokasi(V);
        p = L->First;

        while (p->next != NIL && p->info != X){ // cari posisi X (p)
            p = p->next;
        }

        temp = p->next; // setelah v
        p->next = v;
        v->prev = p;
        v->next = temp;
        if(temp != NIL){ // p bukan last
            temp->prev = v;
        }
    }
}

void InsertVBeforeX(List3 *L, infotype X, infotype V){
    // kamus
    address p, v, temp;

    // algoritma
    if(!IsEmptyList(*L)){
        v = Alokasi(V);
        p = L->First;

        while (p->next != NIL && p->info != X){ // cari posisi X (p)
            p = p->next;
        }

        temp = p->prev; // sebelum v
        p->prev = v;
        v->next = p;
        v->prev = temp;
        if(temp != NIL){ // v bukan first
            temp->next = v;
        } else { // v first
            L->First = v;
        }
    }
}

void DeleteVAfterX(List3 *L, infotype X, infotype *V){
    // kamus
    address p, q, last;

    // algoritma
    if(!IsEmptyList(*L)){
        p = L->First;
        last = L->First;
        while (last->next != NIL){ // cari posisi last
            last = last->next;
        }

        // kondisi
        if(p->next == NIL){ //oneElmt
            if (p->info == X){
                DeleteVFirst(L, V);
            }
        } else{ // isi >1
            while (p->next != NIL && p->info != X){ // cari posisi X (p)
                q = p;
                p = p->next;
            }

            if (p == last){ // p di last
                DeleteVLast(L, V);
            }
            else{ // p di tengah
                q->next = p->next;
                p->next->prev = q;
                Dealokasi(&p);
            }
        }
    }
}

void DeleteVBeforeX(List3 *L, infotype X, infotype *V){

}

int CountX(List3 L, infotype X){
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

float FrekuensiX(List3 L, infotype X){
    // kamus

	// algoritma
	if (NbElm(L) == 0) return 0.0;
	return (float) CountX(L, X) / NbElm(L);
}

int MaxMember(List3 L){
    return CountX(L, Modus(L));
}

char Modus(List3 L){
    // kamus lokal
    address p, q;
    infotype modus;
    int count, maxCount, tempCount;

    // algoritma
    p = L.First;
    modus = '#';
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

int CountVocal(List3 L){
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

int CountNG(List3 L){
    // kamus lokal
    address p;
    int count;

    // algoritma
    p = L.First;
    count = 0;
    while (p!=NIL) {
        if(p->info == 'N' && p->next->info == 'G'){
            count ++;
        }
        p = p->next;
    }
    return count;
}

void SearchAllX(List3 L, infotype X){
    // kamus
    address p;
    int pos;
    boolean found;

    //algoritma
    if(!IsEmptyList(L)){
        p = L.First;
        pos = 1;
        found = false;
        printf("%c is on :");
        do{
            if(p->info == X){
                printf(" %d", pos);
                found = true;
            }
            pos ++;
            p = p->next;
        } while (p != NIL);
        if(!found){
            printf(" there's no %c", X);
        }
        printf("\n");
    }
}

void DeleteAllX(List3 *L, infotype X);

void ConcatList(List3 L1, List3 L2, List3 *L); 

void SplitList(List3 L, List3 *L1, List3 *L2);

void CopyList(List3 L1, List3 *L2);
