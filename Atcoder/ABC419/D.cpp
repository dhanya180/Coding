#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    string S, T;
    cin >> S >> T;

    string result = S;

    vector<int> diff(N + 1, 0);
    for (int i = 0; i < M; ++i) {
        int L, R;
        cin >> L >> R;
        diff[L - 1] ^= 1;
        diff[R] ^= 1;
    }

    int cur = 0;
    for (int i = 0; i < N; ++i) {
        cur ^= diff[i];
        result[i] = (cur == 0 ? S[i] : T[i]);
    }

    cout << result << endl;

    return 0;
}