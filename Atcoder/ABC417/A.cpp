#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int N, A, B;
    cin >> N >> A >> B;

    string S;
    cin >> S;

    string result = "";
    for (int i = A; i < N-B; ++i) {
        result += S[i];
    }

    cout << result << endl;
    return 0;
}