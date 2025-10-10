// ======================================================
// Nama Program: tqueue3.c
// Deskripsi   : body realisasi ADT Tqueue3
// NIM/Nama    : 24060124120024/Ruth Septriana Sipangkar
// Tanggal     : 09/10/2025
// ======================================================
#include<stdio.h>
#include"tqueue3.h"

void createQueue3(tqueue3 *Q){
    for(int i=1; i<6; i++){
        Q->wadah[i] = '-';
    }
    Q->head = 0;
    Q->tail = 0;
}

int head3(tqueue3 Q){
    return Q.head;
}

int tail3(tqueue3 Q){
    return Q.tail;
}

char infoHead3(tqueue3 Q){
    if(isEmptyQueue3(Q)){
        return '-';
    } else{
        return Q.wadah[Q.head];
    }
}

char infoTail3(tqueue3 Q){
    if(isEmptyQueue3(Q)){
        return '-';
    } else {
        return Q.wadah[Q.tail];
    }
}

int sizeQueue3(tqueue3 Q){
    if(Q.head <= Q.tail){
        return Q.tail-Q.head+1;
    } else{
        return (10-Q.head) + (Q.tail-1);
    }
}

boolean isEmptyQueue3(tqueue3 Q){
    return Q.head == 0 && Q.tail == 0;
}

boolean isFullQueue3(tqueue3 Q){
    if(Q.head <= Q.tail){
        return Q.head == 1 && Q.tail == 5;
    } else{
        return Q.tail+1 == Q.head;
    }
}

boolean isOneElement3(tqueue3 Q){
    return Q.head == Q.tail && Q.tail == 1;
}

void printQueue3(tqueue3 Q){
    printf("Print queue : |");
    for(int i=1; i<=5; i++){
        printf(" %c", Q.wadah[i]);
    }
    printf(" |\n");
}

void viewQueue3(tqueue3 Q){
    if(isEmptyQueue3(Q)){
        printf("View queue  : | |\n");
    } else{
        printf("View queue  : |");
        if(Q.head <= Q.tail){
            for(int i=Q.head; i<=Q.tail; i++){
                printf(" %c", Q.wadah[i]);
            }
        } else {
            for(int i=Q.head; i<=5; i++){
                printf(" %c", Q.wadah[i]);
            }
            for(int i=1; i<Q.tail; i++){
                printf(" %c", Q.wadah[i]);
            }
        }
        printf(" |\n");
    }
}

void enqueue3(tqueue3 *Q, char E){
    if(isEmptyQueue3(*Q)){
        Q->head = 1;
        Q->tail = 1;
        Q->wadah[Q->tail] = E;
    } else {
        if(Q->tail==5){
            Q->tail = 1;
            Q->wadah[Q->tail] = E;
        } else {
            Q->tail ++;
            Q->wadah[Q->tail] = E;
        }
    }
}
  
void dequeue3(tqueue3 *Q, char *E){
    *E = infoTail3(*Q);
    Q->wadah[Q->head] = '-';
    if(isEmptyQueue3(*Q)){
        Q->head = 0;
        Q->tail = 0;
    } else {
        if(Q->head==5){
            Q->head = 1;
        } else {
            Q->head ++;
        }
    }
}

boolean isTailOverHead(tqueue3 Q){
    return Q.tail < Q.head;
}
