#include<stdio.h>

void sort(int N, int arr[N]){
    int temp;
    for (int pass=0; pass<N; pass++){
        for(int k=N-1; k>pass; k--){
            if (arr[k]<arr[k-1]){
                temp = arr[k];
                arr[k] = arr[k-1];
                arr[k-1] = temp;
            }
        }
    }
    // tampilkan array terurut
    printf("\n");
    for(int i=0; i<N; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    // input
    int N; // jlh elemen array
    scanf("%d", &N);
    int arr[N]; // array
    int arrGN[N]; // array bilangan genap
    int arrGJ[N]; // array bilangan ganjil
    for(int i=0; i<N; i++){
        scanf("%d", &arr[i]);
        if (arr[i]%2==0){
            arrGN[i] = arr[i];
        } else {
            arrGJ[i] = arr[i];
        }
    }
    // tampilkan array terurut
    for(int i=0; i<N; i++){
        printf("%d ", arrGN[i]);
    }
    printf("\n");
    for(int i=0; i<N; i++){
        printf("%d ", arrGJ[i]);
    }

    sort(N, arrGN);
    sort(N, arrGJ);

    // mencari nilai tengah
    int midGP, midGJ;
    if ((N/2)%2 == 0){
        midGP = N/2 -1;
        midGJ = N/2;
    } else {
        midGJ = N/2 -1;
        midGP = N/2;
    }

    // nilai tengah
    int GP, GJ;
    GP = arr[midGP];
    GJ = arr[midGJ];
    // tampilkan nilai tengah
    // printf("\n%d %d\n", GP, GJ);

    // mencari rata rata nilai tengah
    float jlh;
    jlh = GP+GJ;
    // tampilkan rata rata (3 digit belaknag koma)
    // printf("%.3f", jlh/2);
}