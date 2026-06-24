#include<iostream>
#include<string>
using namespace std;

// membuang string anak dari string induk
// masukan : sabunkeramaskekerara kera
// keluaran : sabunmas

int main(){
    string s, t;
    cin >> s >> t;

    size_t pos;
    while ((pos = s.find(t)) != string::npos) {
        s.erase(pos, t.length());
    }

    cout << s << endl;
}