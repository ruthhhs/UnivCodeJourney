#include <stdio.h>

int main(){
    int arr[6] = {3,20,3,9,3,2};
    int x=3;
    int i;

    // for(i=0; i<6 && arr[i]!=x ; i++){
    // }
    // if(arr[i]==x){
    //     printf("elemen %d ada di indeks ke %d\n", x, i);
    // } else{
    //     printf("%d tidak ada dalam array", x);
    // }

    // int ada=0;
    // for(i=0; i<6; i++){
    //     if(arr[i]==x){
    //         ada=1;
    //         printf("elemen %d ada di indeks ke %d\n", x, i);
    //     } 
    // }
    // if (ada==0){
    //     printf("%d tidak ada dalam array", x);
    // }

    int c=0;
    int hasil[10];
    for(i=0; i<6; i++){
        if(arr[i]==x){
            hasil[c]==i;
            c++;
        }
    }
    for(i=0; 1<c; i++){
        printf("%d ", hasil[i]);
    }

}