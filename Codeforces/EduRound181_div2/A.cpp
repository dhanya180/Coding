#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;

        // If already non-difficult, output as is
        if (s.find("FFT") == string::npos && s.find("NTT") == string::npos) {
            cout << s << '\n';
            continue;
        }

        // Count frequency of each letter
        array<int,26> cnt{};
        for(char c: s)
            cnt[c - 'A']++;

        // Print all T's first
        for(int i = 0; i < cnt['T'-'A']; i++)
            cout << 'T';

        // Print all other letters A–Z except F, N, T
        for(char c = 'A'; c <= 'Z'; c++){
            if(c == 'F' || c == 'N' || c == 'T') continue;
            for(int i = 0; i < cnt[c - 'A']; i++)
                cout << c;
        }

        // Print all N's
        for(int i = 0; i < cnt['N'-'A']; i++)
            cout << 'N';

        // Print all F's
        for(int i = 0; i < cnt['F'-'A']; i++)
            cout << 'F';

        cout << '\n';
    }

    return 0;
}
