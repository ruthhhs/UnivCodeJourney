#include <iostream>
#include <cmath>
using namespace std;

// menghitung nilai fungsi mutlak

int main(){
    int A, B, K, X;
    cin >> A >> B >> K >> X;

    for(int i=0; i<K; i++){
        X = abs(A*X + B);
    }

    cout << X;
}