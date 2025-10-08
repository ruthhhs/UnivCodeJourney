#include<iostream>
using namespace std;

// pola segitiga angka
// masukan : 5
// keluaran :
    // 0
    // 12
    // 345
    // 6789
    // 01234

int main(){
    int N;
    cin >> N;

    int x = 0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=i; j++){
            cout << x;
            x = (x+1)%10;
        }
        cout << endl;
    }
}
