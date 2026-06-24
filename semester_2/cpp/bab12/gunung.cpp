#include<iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int N;
    cin >> N;

    if (N <= 0) {
        return 0;
    }

    // nested for loop (hampir oke ueueueueu)
    // for(int i=1; i<=N; i++){
    //     for(int j=i; j>=1; j--){
    //         for(int k=j; k>=1; k=k-2){
    //             for(int l=1; l<=k; l++){
    //                 cout << "*";
    //             }
    //             cout << endl;
    //         }
    //     }
    // }

    // pake array + mainin string library
    vector<string> pola;
    pola.push_back("*"); // untuk N=1

    // untuk n>=2
    for(int i=2; i<=N; i++){
        vector<string> pola_atas = pola; // pola bagian atas
        string tengah(i, '*'); // pola bagian tengah
        pola.push_back(tengah);
        for (const string& line : pola_atas){ // pola bagian bawah
            pola.push_back(line);
        }
    }
    // print
    for (const string& line : pola){
            cout << line << endl;
        }
}

// masukan : 4
// keluaran :
    // *
    // **
    // *
    // ***
    // *
    // **
    // *
    // ****
    // *
    // **
    // *
    // ***
    // *
    // **
    // *