#include<stdio.h>
#include"ReverseArray.h"

int main(){
    // t1 dan t2
    int size1, size2;
    scanf("%d %d", &size1, &size2);

    int t1[size1], t2[size2];
    for (int i=0; i<size1; i++){
        scanf("%d", &t1[i]);
    }
    for (int i=0; i<size2; i++){
        scanf("%d", &t2[i]);
    }

    ReverseArray(t1, size1);
    ReverseArray(t2, size2);

    // array hasil (t3)
    int N; 
    if(size1>size2){
        N = size1+1;
    } else {
        N = size2+1;
    }
    int t3[N];

    // penjumlahan
    int carry=0; // menampung jumlah lebih
    for (int i = 0; i < N; i++) {
        int sum = carry;
        if (i < size1) {
            sum += t1[i];
        }
        if (i < size2) {
            sum += t2[i];
        }
        carry = sum / 10;
        t3[i] = sum % 10;
    }

    // menghapus 0 di awal (akhir)
    while (t3[N-1] == 0) {
        N--;
    }

    // hasil
    ReverseArray(t3, N);
    for (int i=0; i<N; i++){
        printf("%d ", t3[i]);
    }
}