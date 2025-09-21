#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>
using namespace std;

int main() {
    int T;
    cin >> T;

    vector<long long> results(T);

    for (int t = 0; t < T; ++t) {
        int N;
        long long M;
        cin >> N >> M;

        vector<long long> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        vector<long long> B(N);
        for (int i = 0; i < N; ++i) {
            cin >> B[i];
        }

        multiset<long long> S(A.begin(), A.end());
        sort(B.begin(), B.end());

        long long answer = 0;
        for(long long b : B){
            // We want the smallest a such that (a + b) >= M,
            // i.e. a >= (M - b % M) % M.
            long long need = (M - (b % M)) % M;
            auto it = S.lower_bound(need);

            if(it == S.end()){
                it = S.begin();
            }

            long long a = *it;
            S.erase(it);
            answer += (a + b) % M;
        }

        results[t] = answer;
    }

    for (const auto& res : results) {
        cout << res << endl;
    }

}
