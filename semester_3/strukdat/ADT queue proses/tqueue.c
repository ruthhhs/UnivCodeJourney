// ======================================================
// Nama Program: tqueue.c
// Deskripsi   : body realisasi ADT Tqueue tipe 1
// NIM/Nama    : 24060124120024/Ruth Septriana Sipangkar
// Tanggal     : 02/10/2025
// ======================================================
#include <stdio.h>
#include "tqueue.h"

void createQueue(tqueue *Q){
    for(int i=1; i<6; i++){
        (Q->wadah[i]).IDprocess = '#';
        (Q->wadah[i]).burstTime = 0;
    }
    Q->head = 0;
    Q->tail = 0;
}

process infoHead(tqueue Q){
    return Q.wadah[Q.head];
}

process infoTail(tqueue Q){
    return Q.wadah[Q.tail];
}

int sizeQueue(tqueue Q){
    return Q.tail;
}

void printQueue(tqueue Q){
    printf("Print Queue : [");
    for(int i=1; i<6; i++){
        printf(" <%c,%d>", infoIDprocess(Q.wadah[i]), infoBurstTime(Q.wadah[i]));
    }
    printf(" ]\n");
}

void viewQueue(tqueue Q){
    printf("View Queue  : [");
    for(int i=1; i<=sizeQueue(Q); i++){
        printf(" <%c,%d>", infoIDprocess(Q.wadah[i]), infoBurstTime(Q.wadah[i]));
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

void enqueue(tqueue *Q, process p){
    if(isEmptyQueue(*Q)){
        Q->head = 1;
    }
    if(!isFullQueue(*Q)){
        Q->tail ++;
        Q->wadah[Q->tail] = p;
    }
}
  
void dequeue(tqueue *Q, process *p){
    if(!isEmptyQueue(*Q)){
        if(infoHead(*Q).burstTime<=3){
            *p = infoHead(*Q);
            for(int i=1; i<=tail(*Q); i++){
                Q->wadah[i] = Q->wadah[i+1];
            }
            (Q->wadah[Q->tail]).IDprocess = '#';
            (Q->wadah[Q->tail]).burstTime = 0;
            Q->tail --;
        } else{
            *p = infoHead(*Q);
            char tempID = (Q->wadah[Q->head]).IDprocess;
            int tempT = (Q->wadah[Q->head]).burstTime;
            for(int i=1; i<=sizeQueue(*Q); i++){
                Q->wadah[i] = Q->wadah[i+1];
            }
            (Q->wadah[Q->tail]).IDprocess = tempID;
            (Q->wadah[Q->tail]).burstTime = tempT-3;
        }
    }
}