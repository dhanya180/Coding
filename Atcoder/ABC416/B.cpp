#include <iostream>
#include <string>

using namespace std;

int main() {
    string S;
    cin >> S;

    int n = S.length();
    string T = S;

    int last_o_index = -1;

    for (int i = 0; i < n; ++i) {
        if (S[i] == '#') {
            continue;
        }

        if (last_o_index == -1) {
            T[i] = 'o';
            last_o_index = i;
        } else {
            bool is_there = false;
            for (int j = last_o_index + 1; j < i; ++j) {
                if (S[j] == '#') {
                    is_there = true;
                    break;
                }
            }
            if (is_there) {
                T[i] = 'o';
                last_o_index = i;
            } else {
                T[i] = '.';
            }
        }
    }

    cout << T << endl;
    return 0;
}
