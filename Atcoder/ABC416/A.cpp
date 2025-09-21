#include <iostream>

using namespace std;    

int main(){
    int N, L, R;
    cin >> N >> L >> R;

    string S;
    cin >> S;

    bool flag = true;

    for (int i=L-1 ; i<R; i++) {
        if(S[i] == 'x'){
            flag = false;
            break;
        }
    }

    if(flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    
    return 0;
}