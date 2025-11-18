// ================================================================================
// Nama Program: list2.c
// Deskripsi   : realisasi body ADT list berkait representasi fisik pointer
// NIM/Nama    : 24060124120024/Ruth Septriana Sipangkar
// Tanggal     : 13 November 2025
// ================================================================================
#include <stdio.h>
#include <stdlib.h>
#include "list2.h" 

address Alokasi(infotype E) {
    //kamus lokal
    address P;
    //algoritma 
    P = (address) malloc(sizeof(Elm)); 
    if (P != NULL ) {
        info(P) = E;
        next(P) = NIL;
    }
    return P;
}

void Dealokasi (address *P){
    //kamus lokal
	
	//algoritma
	if ( *P != NIL ) {
		next(*P) = NIL;
	}
	*P = NIL;
}

void CreateList (List2 *L){
    // kamus lokal

    // algoritma
    L->First = NIL;
}

boolean IsEmptyList (List2 L){
    // kamus lokal

    // algoritma
    return L.First == NIL;
}

boolean IsOneElm (List2 L){
    // kamus lokal
    address P;

    // algoritma
    if (!IsEmptyList(L)){
        P = L.First;
        return P->next == L.First;
    } else {
        return false;
    }
}

void PrintList(List2 L){
    //kamus lokal 
	address P;
	//algoritma
	P = First(L);
	printf("Element     : [");
	if (!IsEmptyList(L)) {
		do {
			printf(" %c", info(P));
			P = P->next;
		} while( P != L.First );
	}
	printf(" ]\n");
}

int NbElm(List2 L){
    // kamus lokal
	address p;
	int count;

    // algoritma
    p = L.First;
    if (!IsEmptyList(L)){
        count = 0;
        do {
            count ++;
            p = p->next;
        } while (p != L.First);
    }
	return count;
}

void InsertVFirst(List2 *L, infotype V ){
    // kamus
    address p, v;

    // algoritma
	v = Alokasi(V);
    p = L->First;
	if (v!=NIL){
		if(!IsEmptyList(*L)){
            while(p->next != L->First){
                p = p->next;
            }
            v->next = L->First;
            L->First = v;
            p->next = v;
		}
		else {
			L->First = v;
            v->next = L->First;
		}
	}
}

void InsertVLast(List2 *L, infotype V ){
    // kamus
     address p, v;

    // algoritma
	v = Alokasi(V);
    p = L->First;
	if (v!=NIL){
		if(!IsEmptyList(*L)){
            while(p->next != L->First){
                p = p->next;
            }
            v->next = L->First;
            p->next = v;
		}
		else {
			L->First = v;
            v->next = L->First;
		}
	}
}

void DeleteVFirst(List2 *L, infotype *V){
    // kamus
    address p, v;

    // algoritma
    p = L->First;
    if (IsEmptyList(*L)){
        *V = '#';
    } else {
        if (IsOneElm(*L)){
            *V = p->info;
			L->First = NIL;
			Dealokasi(&p);
        } else {
            v = L->First;
            *V = v->info;
            while(p->next != L->First){
                p = p->next;
            }
            L->First = v->next;
            p->next = L->First;
            Dealokasi(&v);
        }
    }
}

void DeleteVLast(List2 *L, infotype *V){
    // kamus
    address p, v;

    // algoritma
    p = L->First;
    if (IsEmptyList(*L)){
        *V = '#';
    } else {
        if (IsOneElm(*L)){
            *V = p->info;
			L->First = NIL;
			Dealokasi(&p);
        } else {
            while(p->next != L->First){
                v = p;
                p = p->next;
            }
            *V = p->info;
            v->next = L->First;
            Dealokasi(&p);
        }
    }
}

void DeleteX(List2 *L, infotype X){
    // kamus
    address p, v, last;

    // algoritma
    if (!IsEmptyList(*L)){
        p = L->First;
        last = L->First;
        while (last->next != L->First){
            last = last->next;
        }

        if(IsOneElm(*L)){
            if (p->info == X){
                L->First = NIL;
                Dealokasi(&p);
            }
        } else {
            v = NIL;
            do {
                if (p->info == X) {
                    break;
                }
                v = p;
                p = p->next;
            } while(p!= L->First);

            if (p->info == X) {
                if (p == L->First) {
                    L->First = p->next;
                    last->next = L->First;
                } else {
                    v->next = p->next;
                }
                Dealokasi(&p);
            }
        }
    }
}

void SearchX(List2 L, infotype X, address *A){
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
        } while (p!=L.First);
    }
}

void UpdateX(List2 *L, infotype X, infotype Y){
    // kamus lokal
	address p;

    // algoritma
	if(!IsEmptyList(*L)){
        p = L->First;
        do {
            if (p->info == X){
                p->info = Y;
                break;
            }
            p = p->next;
        } while (p!=L->First);
    }
}

void Invers(List2 *L){
    // kamus lokal
    address prev, p, next, first;

    // algoritma
    if (!IsEmptyList(*L)){
        first = L->First;
        prev = NIL;
        p = L->First;

        do {
            next = p->next;
            p->next = prev;
            prev = p;
            p = next;
        } while (p != first);

        first->next = prev;
        L->First = prev;
    }
}

// =======================================

int CountX(List2 L, infotype X){
    // kamus lokal
	address p;
	int count;

    // algoritma
    count = 0;
    if(!IsEmptyList(L)){
        p = L.First;
        do {
            if(p->info == X){
                count ++;
            }
            p = p->next;
        } while (p!=L.First);
    }
	return count;
}

float FrekuensiX(List2 L, infotype X){
    // kamus

	// algoritma
	if (IsEmptyList(L)) return 0.0;
	return (float) CountX(L, X) / NbElm(L);
}

int CountVocal(List2 L){
    // kamus lokal
	address p;
	int count;

    // algoritma
    count = 0;
    if(!IsEmptyList(L)){
        p = L.First;
        do {
            if(p->info == 'A' || p->info == 'I' || p->info == 'U' || p->info == 'E' || p->info == 'O'){
                count ++;
            }
            p = p->next;
        } while (p!=L.First);
    }
	return count;
}

int CountNG(List2 L){
    // kamus lokal
	address p;
	int count;

    // algoritma
    count = 0;
    if(!IsEmptyList(L)){
        p = L.First;
        do {
            if(p->info == 'N' && p->next->info == 'G'){
                count ++;
            }
            p = p->next;
        } while (p!=L.First);
    }
	return count;
}

void InsertVAfterX(List2 *L, infotype X, infotype V){
    // kamus lokal
    address p;
    address add;

    // algoritma
    add = Alokasi(V);
    p = L->First;

    if (add != NIL) {
        add->next = L->First;
        do {
            p = p->next;
        } while (p->next!= L->First && p->info != X);

        if(p != NIL){
            add->next = p->next;
            p->next = add;
        }
    }
}

void InsertVBeforeX(List2 *L, infotype X, infotype V){
    // kamus lokal
    address p, q, add;

    // algoritma
    add = Alokasi(V);
    p = L->First;

    if (add != NIL) {
        add->next = L->First;
        do {
            q = p;
            p = p->next;
        } while (p->next!= L->First && p->info != X);

        if(p != NIL){
            add->next = q->next;
            q->next = add;
            add->next = p;
        }
    }
}

void DeleteVAfterX(List2 *L, infotype X, infotype *V){
    // kamus
    address p, del, last;

    // algoritma
    if(!IsEmptyList(*L)){
        p = L->First;
        do{
            if (p->info == X){
                del = p->next;
                *V = del->info;

                if(IsOneElm(*L)){
                    L->First = NIL;
                    Dealokasi(&del);
                    return;
                }
    
                if (del == L->First){
                    last = L->First;
                    while (last->next != L->First){
                        last = last->next;
                    }
                    L->First = L->First->next;
                    last->next = L->First;
                }
                p->next = del->next;
                Dealokasi(&del);
                return;
    
            }
            p = p->next;
        } while (p != L->First);
    }
}

void DeleteVBeforeX(List2 *L, infotype X, infotype *V){
    // kamus
    address p, del, prev, prevPrev, last;

    // algoritma
    if (!IsEmptyList(*L)){
        p = L->First;
        prev = NULL;
        prevPrev = NULL;
    
        do {
            if (p->info == X){
                if (IsOneElm(*L)) return;

                del = prev;
                if (p == L->First){
                    last = L->First;
                    while (last->next != L->First){
                        last = last->next;
                    }
                    del = last;
                    *V = del->info;
                    prevPrev = L->First;
                    while (prevPrev->next != last){
                        prevPrev = prevPrev->next;
                    }
                    prevPrev->next = p;
                    Dealokasi(&del);
                    return;
                }
    
                if (del == L->First){
                    last = L->First;
                    while (last->next != L->First){
                        last = last->next;
                    }
                    *V = del->info;
                    L->First = L->First->next;
                    last->next = L->First;
                    Dealokasi(&del);
                    return;
                }
                *V = del->info;
                prevPrev->next = p;
                Dealokasi(&del);
                return;
            }
            prevPrev = prev;
            prev = p;
            p = p->next;
        } while (p != L->First);
    }
}

void DeleteAllX(List2 *L, infotype X){
    // kamus
    address p, prev, temp, first, last;

    // algoritma
    if (!IsEmptyList(*L)){
        first = L->First;
        p = L->First;
        prev = NULL;
    
        do {
            if (p->info == X){
                temp = p;

                if (IsOneElm(*L)){
                    L->First = NIL;
                    Dealokasi(&temp);
                    return;
                }

                if (p == L->First){
                    last = L->First;
                    while (last->next != L->First){
                        last = last->next;
                    }
                    L->First = p->next;
                    last->next = L->First;
    
                    p = p->next;
                    Dealokasi(&temp);
                    first = L->First;\
                }
                else {
                    prev->next = p->next;
                    p = p->next;
                    Dealokasi(&temp);
                }
            }
            else {
                prev = p;
                p = p->next;
            }
        } while (p != first);
    }
}


void SearchAllX(List2 L, infotype X){
    // kamus lokal
    address p;
    int posisi = 1;
    boolean found = false;

    // algoritma
    if (!IsEmptyList(L)){
        p = L.First;
        printf("'%c' found at : ", X);
        do {
            if (p->info == X){
                printf("%d ", posisi);
                found = true;
            }
            p = p->next;
            posisi++;
        } while (p != L.First);
        if (!found){
            printf("Not found");
        }
        printf("\n");
    }
}

int MaxMember(List2 L){
    return CountX(L, Modus(L));
}

char Modus(List2 L){
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
        do {
            tempCount = 0;
            q = L.First;
            do {
                if (q->info == p->info){
                    tempCount++;
                }
                q = q->next;
            } while (q != L.First);
            
            if (tempCount > maxCount){
                maxCount = tempCount;
                modus = p->info;
            }
            p = p->next;
        } while (p != L.First);
    }
    return modus;
}

void ConcatList(List2 L1, List2 L2, List2 *L); 

void SplitList(List2 L, List2 *L1, List2 *L2);

void CopyList(List2 L1, List2 *L2);
