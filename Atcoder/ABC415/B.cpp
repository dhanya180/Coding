#include <bits/stdc++.h>
using namespace std;    

int main() {
    string S;
    cin >> S;

    vector <int> packages;

    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '#') {
            packages.push_back(i + 1);
        }
    }
    
    for (int i = 0; i < packages.size(); i++) {
        cout << packages[i] << "," << packages[i+1] << endl;
        i++;
    }
    return 0;
}