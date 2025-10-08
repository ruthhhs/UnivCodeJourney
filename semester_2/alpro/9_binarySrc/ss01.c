#include <stdio.h>
#include <math.h>

int main(){
    int N, X;
    scanf("%d %d", &N, &X);

    int i;
    int arr[N];
    for(i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }

    int terdekat = 0;
    for(i=0; i<N; i++){
        for(int i=0; i<N; i++){
            if(abs(X-arr[i]) <= abs(X-terdekat)){
                terdekat = arr[i];
            }
        }
    }
    printf("%d ", terdekat);
}

// Input:
// 3 30
// 10 20 30
// Output:
// --> 30