#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    unordered_map<int, int> freq;
    long long result = 0;

    for (int j = 0; j < N; ++j) {
        int key = j - A[j];
        if (freq.count(key)) {
            result += freq[key];
        }
        freq[j + A[j]]++;
    }

    cout << result << endl;
    return 0;
}
