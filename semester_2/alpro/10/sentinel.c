#include<stdio.h>

int main(){
    int N; // jlh array
    scanf("%d", &N);
    int X; // sentinel
    scanf("%d", &X);

    int arr[N]; // array
    for(int i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }

    // sequential search dengan batas (sentinel)
    int i=0;
    while (arr[i]<X){
        i++;
    }
    if (arr[i]==X){
        printf("%d ", i);
    } else {
        printf("%d ", -1);
    }
}