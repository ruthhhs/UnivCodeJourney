#include <iostream>
#include <cmath>
using namespace std;

// Pak Dengklek ingin membariskan N bebeknya ke dalam sebuah formasi r baris dan c kolom, sedemikian sehingga r≤c dan r×c=N.
// Tentukan pasangan nilai r dan c yang mungkin!
// Jika ada lebih dari satu kemungkinan pasangan, pilih pasangan yang memiliki selisih r dan c terkecil.
// (c pasti bernilai N/r)
int main() {
    long long N;
    cin >> N;

    long long r = sqrt(N);

    while(N%r != 0){
        r--;
    }

    cout << r << " " << N/r << endl;
}