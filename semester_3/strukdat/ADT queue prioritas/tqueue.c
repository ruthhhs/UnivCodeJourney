// ======================================================
// Nama Program: tqueue.c
// Deskripsi   : body realisasi ADT Tqueue tipe 1
// NIM/Nama    : 24060124120024/Ruth Septriana Sipangkar
// Tanggal     : 09/10/2025
// ======================================================
#include <stdio.h>
#include "tqueue.h"

void createQueue(tqueue *Q){
    for(int i=1; i<6; i++){
        (Q->wadah[i]).IDpasien = 0;
        (Q->wadah[i]).prioritas = 0;
    }
    Q->head = 0;
    Q->tail = 0;
}

pasien infoHead(tqueue Q){
    return Q.wadah[Q.head];
}

pasien infoTail(tqueue Q){
    return Q.wadah[Q.tail];
}

int sizeQueue(tqueue Q){
    return Q.tail;
}

void printQueue(tqueue Q){
    printf("Print Queue : [");
    for(int i=1; i<6; i++){
        printf(" <%d,%d>", infoIDpasien(Q.wadah[i]), infoprioritas(Q.wadah[i]));
    }
    printf(" ]\n");
}

void viewQueue(tqueue Q){
    printf("View Queue  : [");
    for(int i=1; i<=sizeQueue(Q); i++){
        printf(" <%d,%d>", infoIDpasien(Q.wadah[i]), infoprioritas(Q.wadah[i]));
    }
    printf(" ]\n");
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

void enqueue(tqueue *Q, pasien p){
    if(isEmptyQueue(*Q)){
        Q->head = 1;
        Q->tail = 1;
        Q->wadah[Q->tail] = p;
        return;
    }
    if(!isFullQueue(*Q)){
        Q->tail++;
        int i = Q->tail - 1;
        while (i >= Q->head && Q->wadah[i].prioritas > p.prioritas) {
            Q->wadah[i + 1] = Q->wadah[i];
            i--;
        }
        Q->wadah[i + 1] = p;
    }
}

  
void dequeue(tqueue *Q, pasien *p){
    if(!isEmptyQueue(*Q)){
        *p = infoHead(*Q);
        for(int i=1; i<=tail(*Q); i++){
            Q->wadah[i] = Q->wadah[i+1];
        }
        (Q->wadah[Q->tail]).IDpasien = '#';
        (Q->wadah[Q->tail]).prioritas = 0;
        Q->tail --;
    }
}