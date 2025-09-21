#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid; // Target found
        } else if (arr[mid] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }
    return -1; // Target not found
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<int> B(M);
    for (int i = 0; i < M; ++i) {
        cin >> B[i];
    }

    for (int i = 0; i < M; ++i) {
        int target = B[i];
        int index = binarySearch(A, target);
        if (index != -1) {
            A.erase(A.begin() + index);
        } else {
            continue; 
        }
    }

    for (int i : A) {
        cout << i << " ";
    }

    cout << endl;
    return 0;
}