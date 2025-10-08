#include <iostream>
#include <vector>
using namespace std;

// menemuka nilai max dan min dalam sebuah array

int main(){
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i=0; i<N; i++) {
        cin >> arr[i];
    }

    int max, min;
    max = arr[0];
    min = arr[0];
    for (int i=1; i<N; i++) {
        if(arr[i]>max){
            max = arr[i];
        } else if (arr[i]<min){
            min = arr[i];
        }
    }

    cout << max << " " << min;
}