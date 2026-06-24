#include <iostream>
#include <vector>
using namespace std;

// Diberikan N buah bilangan bulat: A1 hingga An.
// Anda ingin mengetahui, untuk setiap 1≤i≤N, berapakah jumlah dari keseluruhan bilangan bulat tersebut kecuali Ai.
int main(){
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    long long jumlah;
    for(int i=0; i<N; i++) {
        jumlah = 0;
        for(int j=0; j<N; j++){
            if(j==i){
                continue;
            } else {
                jumlah += arr[j];
            }
        }
        cout << jumlah << endl;
    }
}
