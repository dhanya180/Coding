#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;

    vector<string> results;

    while(t--){
        int n, m;
        cin >> n >> m;

        vector<vector<int>> sets(n);
        vector<int> cnt(m+1,0);

        for(int i=0 ; i<n ; i++){
            int l;
            cin >> l;

            sets[i].resize(l);
            for(int j=0 ; j<l ; j++){
                cin >> sets[i][j];
                cnt[sets[i][j]]++;
            }
        }

        bool missing = false;
        for(int x=1 ; x<=m ; x++){
            if(cnt[x] == 0){
                missing = true;
                break;
            }
        }
        if(missing){
            results.push_back("No");
            continue;
        }
        int nonessential = 0;
        for(int i=0 ; i<n ; i++){
            bool essential = false;
            for(int x: sets[i]){
                if(cnt[x] == 1){
                    essential = true;
                    break;
                }
            }
            if(!essential){
                nonessential++;
            }
        }
        if(nonessential >= 2){
            results.push_back("Yes");
        }
        else{
            results.push_back("No");
        }
    }

    for(string result: results){
        cout << result << "\n";
    }
    return 0;
}
