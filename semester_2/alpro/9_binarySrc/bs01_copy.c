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
        int X, Y;
        scanf("%d %d", &X, &Y);

        int l=0;
        int r=N;
        int mid = (l+r)/2;

        while (X!=arr[mid] && l<=r){
            if (X<arr[mid]){
                r = mid-1;
            } else{
                l = mid+1;
            }
            mid = (l+r)/2;
        }
        X = mid;

        l=0;
        r=N;
        mid = (l+r)/2;

        while (Y!=arr[mid] && l<=r){
            if (Y<arr[mid]){
                r = mid-1;
            } else{
                l = mid+1;
            }
            mid = (l+r)/2;
        }
        Y = mid + 1;

        if (X == 0){
            printf("%d\n", Y-X);
        } else {
            printf("%d\n", Y-X-1);
        }
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