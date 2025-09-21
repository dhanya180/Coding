#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if(!(cin >> t)) return 0;
    while(t--){
        int n;
        string s;
        cin >> n >> s; 
        vector<int> p(n+1, 0); 
        bool flag = true;

        for(int i = 1; i <= n; i++){
            if(s[i-1] == '1'){
                p[i] = i;
            }
        }

        int i = 1;
        while(i <= n){
            if(s[i-1] == '0'){
                int j = i;
                while(j <= n && s[j-1] == '0'){
                    ++j;
                }

                int len = j - i;
                if(len == 1){
                    flag = false;
                    break;
                }

                for(int pos = i; pos <= j-2; ++pos){
                    p[pos] = pos + 1;
                }

                p[j-1] = i;
                i = j;
            }
            else {
                i++;
            }
        }

        if(!flag){
            cout << "No\n";
        } else {
            cout << "Yes\n";
            for(int k = 1; k <= n; k++){
                cout << p[k] << (k==n?'\n':' ');
            }
        }
    }
    return 0;
}
