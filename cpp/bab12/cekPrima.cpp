#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int N;
    cin >> N;

    int T[N];
    for(int i=0; i<N; i++){
        cin >> T[i];
    }

    for(int i=0; i<N; i++){
        int prima=1;
        for(int j=2; j<=sqrt(T[i]); j++){
            if (T[i]%j==0){
                prima = 0;
            }
        }

        if(prima==1){
            cout<< "YA" <<endl;
        } else {
            cout<< "BUKAN" <<endl;
        }
    }
}