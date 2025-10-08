#include<iostream>
using namespace std;

// perkalian 2 matrix
int main(){
    int n, m, p;
    cin >> n >> m >> p;

    int A[n][m], B[m][p];
    // matrix A(n.m)
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> A[i][j];
        }
    }
    // matrix B(m.p)
    for(int i=0; i<m; i++){
        for(int j=0; j<p; j++){
            cin >> B[i][j];
        }
    }

    int C[n][p];
    // matrix C(n.p)
    for(int i=0; i<n; i++){
        for(int j=0; j<p; j++){
            C[i][j] = 0;
            for(int k=0; k<m; k++){
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<p; j++){
           cout << C[i][j] << " ";
        }
        cout << endl;
    }
}