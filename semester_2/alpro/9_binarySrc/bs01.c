#include<stdio.h>

int main(){
    int N;
    scanf("%d", &N);
    int arr[N];
    for(int i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }

    int Q;
    scanf("%d", &Q);
    for(int i=0; i<Q; i++){
        int L, R;
        scanf("%d %d", &L, &R);
        int jumlah = 0;
        for(int i=0; i<N; i++){
            if (L < arr[i] && arr[i] <= R){
                jumlah ++;
            }
        }
        printf("%d\n", jumlah);
    }
}

// Input:
// 5
// 3 6 8 10 20
// 2
// 2 15
// 10 20
// Output:
// --> 4
// --> 1