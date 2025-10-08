#include<iostream>
#include <vector>
#include<cmath>
using namespace std;

// agak susah jelasinnya singkat, pokoknya gitu wkwkwk

int main(){
    int N, D;
    cin >> N >> D;

     vector<vector<int>> T(N, vector<int>(2));
    for(int i=0; i<N; i++){
        cin >> T[i][0] >> T[i][1];
    }

    int x_awal = abs(T[0][0] - T[1][0]);
    int y_awal = abs(T[0][1] - T[1][1]);
    int kedekatan_awal = pow(x_awal, D) + pow(y_awal, D);

    int min=kedekatan_awal, max=kedekatan_awal;

    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            int x = abs(T[i][0] - T[j][0]);
            int y = abs(T[i][1] - T[j][1]);

            int kedekatan = pow(x, D) + pow(y, D);
            if (kedekatan < min){
                min = kedekatan;
            }
            if (kedekatan > max){
                max = kedekatan;
            }
        }
    }

    cout << min << " " << max << endl;
}