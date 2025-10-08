#include <iostream>
using namespace std;

// Pak Dengklek ingin membariskan N bebeknya ke dalam sebuah formasi r baris dan c kolom, sedemikian sehingga r≤c dan r×c=N.
// Tentukan pasangan nilai r dan c yang mungkin!
// Jika ada lebih dari satu kemungkinan pasangan, pilih pasangan yang memiliki selisih r dan c terkecil.
int main() {
    int N;
    cin >> N;

    int r_terbaik, c_terbaik;
    r_terbaik = 1;
    c_terbaik = N;

    for(int r=1; r<=N; r++){
        for(int c=r; c<=N; c++){
            if(r*c==N){
                if (c-r < c_terbaik-r_terbaik){
                    r_terbaik = r;
                    c_terbaik = c;
                }
            }
        }
    }

    cout << r_terbaik << " " << c_terbaik;
}