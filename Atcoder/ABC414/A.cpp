#include <iostream>
using namespace std;

int main(){
    int N, L, R;
    cin >> N >> L >> R;

    int count = 0;
    for (int i = 0; i < N; ++i) {
        int Xi, Yi;
        cin >> Xi >> Yi;
        if (Xi <= L && Yi >= R) {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}
