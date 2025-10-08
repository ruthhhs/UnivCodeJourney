// ======================================================
// Nama Program: tqueue.c
// Deskripsi   : body realisasi ADT Tqueue
// NIM/Nama    : 24060124120024/Ruth Septriana Sipangkar
// Tanggal     : 02/10/2025
// ======================================================
#include <stdio.h>
#include "tqueue.h"

void createQueue(tqueue *Q){
    for(int i=1; i<6; i++){
        Q->wadah[i] = '-';
    }
    Q->head = 0;
    Q->tail = 0;
}

int infoHead(tqueue Q){
    return Q.wadah[Q.head];
}

int infoTail(tqueue Q){
    return Q.wadah[Q.tail];
}

int sizeQueue(tqueue Q){
    return Q.tail;
}

void printQueue(tqueue Q){
    printf("Print queue : |");
    for(int i=1; i<6; i++){
        printf(" %c", Q.wadah[i]);
    }
    printf(" |\n");
}

void viewQueue(tqueue Q){
    printf("View queue  : |");
    for(int i=1; i<=sizeQueue(Q); i++){
        printf(" %c", Q.wadah[i]);
    }
    printf(" |\n");
}

boolean isEmptyQueue(tqueue Q){
    return Q.head == 0;
}
 
boolean isFullQueue(tqueue Q){
    return Q.tail == 6;
}

boolean isOneElement(tqueue Q){
    return Q.tail == 1;
}

void enqueue(tqueue *Q, char e){
    if(isEmptyQueue(*Q)){
        Q->head = 1;
    }
    if(!isFullQueue(*Q)){
        Q->tail ++;
        Q->wadah[Q->tail] = e;
    }
}
  
void dequeue(tqueue *Q, char *e){
    if(!isEmptyQueue(*Q)){
        *e = infoHead(*Q);
            for(int i=1; i<=sizeQueue(*Q); i++){
                Q->wadah[i] = Q->wadah[i+1];
            }
            Q->wadah[Q->tail] = '-';
            Q->tail --;
    }
}

/*tambahan, dikerjakan bila cukup waktu */

void enqueue2Q(tqueue *Q1, tqueue *Q2, char e){
    if(!isFullQueue(*Q1) || !isFullQueue(*Q2)){
        if(sizeQueue(*Q1) < sizeQueue(*Q2)){
            enqueue(Q1, e);
        } else {
            enqueue(Q2, e);
        }
    }
}

void dequeue2Q(tqueue *Q1, tqueue *Q2, char *e){
    if(!isEmptyQueue(*Q1) || !isEmptyQueue(*Q2)){
        if(sizeQueue(*Q1) < sizeQueue(*Q2)){
            dequeue(Q2, e);
        } else {
            dequeue(Q1, e);
        }
    }
}