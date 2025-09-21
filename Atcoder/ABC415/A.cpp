#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void binary_search(const vector<int>& A, int X) {
    int left = 0, right = A.size() - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(A[mid] == X) {
            cout << "Yes" << endl;
            return;
        } else if(A[mid] < X) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << "No" << endl;
}

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int X;
    cin >> X;
    sort(A.begin(), A.end());

    binary_search(A, X);
    return 0;
}

