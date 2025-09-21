#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int Q;
    cin >> Q;

    vector<int> a;
    vector<int> result;
    while(Q--){
        int q;
        cin >> q;
        if(q == 1){
            int x;
            cin>>x;
            a.push_back(x);
        }
        else {
            sort(a.begin(), a.end());
            result.push_back(a.front());
            a.erase(a.begin());
        }
    }
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << endl;
    }
}
