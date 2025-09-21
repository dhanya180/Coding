#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

void getStrings(int K, int N, const vector<string>& S, string current, vector<string>& F) {
    if (K == 0) {
        F.push_back(current);
        return;
    }
    for (int i = 0; i < N; ++i) {
        getStrings(K - 1, N, S, current + S[i], F);
    }
}

int main(){
    int N, K, X;
    cin >> N >> K >> X;

    vector<string> S(N);
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }

    vector<string> F;

    getStrings(K, N, S, "", F);

    sort(F.begin(), F.end());

    cout << F[X-1] << endl;
    return 0;

}