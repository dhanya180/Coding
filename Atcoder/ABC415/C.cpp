#include <bits/stdc++.h>
using namespace std;    

int main() {
    int T;
    cin >> T;

    vector<string> results;

    while (T--) {
        int N;
        string S;
        cin >> N >> S;

        int full = (1<<N) - 1;   // (2^N) - 1;

        vector<char> dp(1<<N, 0);
        dp[0] = 1;

        for(int mask = 0; mask < full; mask++){
            if(!dp[mask]){
                continue;
            }
            // try adding each chemical i not yet in mask
            for(int i = 0; i < N; i++){
                if(!(mask & (1<<i))){
                    int nxt = mask | (1<<i);
                    if(S[nxt-1] == '0') 
                        dp[nxt] = 1;
                }
            }
            if(dp[full]){
                break;
            }
        }

        results.push_back((dp[full] ? "Yes" : "No"));
    }

    for (string s : results) {
        cout << s << endl;
    }

    return 0;
}