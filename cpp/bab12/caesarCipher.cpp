#include<iostream>
#include<vector>
#include<string>
using namespace std;

// caesarCipher encription
int main(){
    int key;
    cin >> key;

    string s;
    cin >> s;

    string sc = "";
    for(char c : s){
        if (isupper(c)) {
            char cc = 'A' + (c - 'A' + key) % 26;
            sc += cc;
        }
        else if (islower(c)) {
            char cc = 'a' + (c - 'a' + key) % 26;
            sc += cc;
        }
        else {
            sc += c;
        }
    }

    cout << sc << endl;
}