// ======================================================
// Nama Program: tqueue2.h
// Deskripsi   : header ADT Tqueue2
// NIM/Nama    : 24060124120024/Ruth Septriana Sipangkar
// Tanggal     : 02/10/2025
// ======================================================
#include <stdio.h>
#include "tqueue2.h"


void createQueue2(tqueue2 *Q){
    for(int i=1; i<6; i++){
        Q->wadah[i] = '-';
    }
    Q->head = 0;
    Q->tail = 0;
}

int head2(tqueue2 Q){
    return Q.head;
}

int tail2(tqueue2 Q){
    return Q.tail;
}

char infoHead2(tqueue2 Q){
    return Q.wadah[Q.head];
}

char infoTail2(tqueue2 Q){
    return Q.wadah[Q.tail];
}

int sizeQueue2(tqueue2 Q){
    if(isEmptyQueue2(Q)) return 0;
    return Q.tail - Q.head + 1;
}

boolean isEmptyQueue2(tqueue2 Q){
    return Q.head == 0 && Q.tail == 0;
}
 
boolean isFullQueue2(tqueue2 Q){
    return Q.head == 1 && Q.tail == 5;
}

boolean isOneElement2(tqueue2 Q){
    return Q.head == Q.tail && Q.tail == 1;
}

boolean isTailStop(tqueue2 Q){
    return Q.tail == 5;
}

void printQueue2(tqueue2 Q){
    printf("Print queue : |");
    for(int i=1; i<6; i++){
        printf(" %c", Q.wadah[i]);
    }
    printf(" |\n");
}

void viewQueue2(tqueue2 Q){
    printf("View queue  : |");
    if(isEmptyQueue2(Q)){
        printf(" @");
    } else{
        for(int i=Q.head; i<=Q.tail; i++){
            printf(" %c", Q.wadah[i]);
        }
    }
    printf(" |\n");
}

void resetHead(tqueue2 *Q){
    int n = sizeQueue2(*Q);
    int start = Q->head;
    for(int i=1; i<=n; i++){
        Q->wadah[i] = Q->wadah[start + i - 1];
    }
    for(int i=n+1; i<6; i++){
        Q->wadah[i] = '-';
    }
    Q->head = 1;
    Q->tail = n;
}

void enqueue2(tqueue2 *Q, char E){
    if(isEmptyQueue2(*Q)){
        Q->head ++;
        Q->tail ++;
        Q->wadah[Q->head] = E;
    } else if(!isTailStop(*Q) && !isFullQueue2(*Q)){
        Q->tail ++;
        Q->wadah[Q->tail] = E;
    } else if(isTailStop(*Q) && !isFullQueue2(*Q)){
        resetHead(Q);
        Q->tail ++;
        Q->wadah[Q->tail] = E;
    }
}

void dequeue2(tqueue2 *Q, char *E){
    if(isEmptyQueue2(*Q)){
        *E = '@';
    }
    if(isOneElement2(*Q)){
        *E = infoHead2(*Q);
        Q->wadah[Q->head] = '-';
        Q->tail = 0;
        Q->head = 0;
    } else if (!isEmptyQueue2(*Q)){
        *E = infoHead2(*Q);
        Q->wadah[Q->head] = '-';
        Q->head ++;
    }
}

void enqueue2N(tqueue2 *Q, int N){
    char E;

    for(int i = 1; i <= N; i++){
        if(isFullQueue2(*Q)){
            printf("Queue sudah penuh\n");
            break;
        }

        if(isTailStop(*Q) && !isFullQueue2(*Q)){
            resetHead(Q);
        }

        printf("Masukkan elemen ke-%d : ", i);
        scanf(" %c", &E);

        enqueue2(Q, E);
        printQueue2(*Q);
    }
}


boolean isEqualQueue2(tqueue2 Q1, tqueue2 Q2){
    if(sizeQueue2(Q1) != sizeQueue2(Q2)) {
        return false;
    }

    resetHead(&Q1);
    resetHead(&Q2);

    int n = sizeQueue2(Q1);
    for(int i=1; i<=n; i++){
        if(Q1.wadah[i] != Q2.wadah[i]){
            return false; 
        }
    }
    return true;
}
