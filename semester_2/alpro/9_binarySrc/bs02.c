#include <stdio.h>

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
        int x;
        scanf("%d", &x);

        int jumlah=0;
        int j=0;
        while(x>=jumlah){
            jumlah+=arr[j];
            if (x<=jumlah){
                printf("%d\n", j+1);
            }
            j++;
        }

    }
}

// Input:
// 3
// 10 10 10
// 3
// 5
// 15
// 25
// Output:
// --> 1
// --> 2
// --> 3