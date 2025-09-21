#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    vector<long long> X(N);
    for(int i = 0; i < N; i++) {
        cin >> X[i];
    }

    sort(X.begin(), X.end());

    if(M >= N){
        cout << 0 << "\n";
        return 0;
    }

    vector <long long> gaps;
    gaps.reserve(N-1);
    for(int i = 0; i + 1 < N ; i++) {
        gaps.push_back(X[i+1] - X[i]);
    }

    sort(gaps.begin(), gaps.end(), greater<long long>());

    long long result = X.back() - X.front();
    for(int i = 0; i < M - 1 ; i++) {
        result -= gaps[i];
    }

    cout << result << endl;
    return 0;

}