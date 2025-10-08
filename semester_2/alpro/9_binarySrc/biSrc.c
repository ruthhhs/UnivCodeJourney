#include <stdio.h>

int main(){
    int arr[9] = {1,2,3,4,5,6,7,8,9};
    int x=0;

    int l = 0;
    int r = 9;
    int mid = (l+r)/2;

    while (x!=arr[mid] && l<=r){
        if (x<arr[mid]){
            r = mid-1;
        } else{
            l = mid+1;
        }
        mid = (l+r)/2;
    }

    if (x == arr[mid]) {
        printf("elemen %d ada di indeks ke %d\n", x, mid);
    } else {
        printf("%d tidak ada dalam array", x);
    }

    return 0;
}