#include <stdio.h>

int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]); // n jumlah elemen array

    for(int i=4; i>=0; i--){   // memprint elemen ke 5 sampai 1
        printf("%d", arr[i]);
    }

    return 0;
}
