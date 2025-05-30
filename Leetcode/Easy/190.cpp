// 190. Reverse Bits

#include <iostream>
#include <bitset>
#include <vector>
#include <cstdint>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; ++i) {
            result <<= 1;         // Shift result left
            result |= (n & 1);    // Take last bit of n
            n >>= 1;              // Shift n right
        }
        return result;
    }
};

void printBinary(uint32_t n) {
    cout << bitset<32>(n);
}

int main() {
    Solution sol;

    vector<uint32_t> testCases = {
        0b00000010100101000001111010011100, // 43261596
        0b11111111111111111111111111111101  // 4294967293
    };

    for (uint32_t n : testCases) {
        cout << "Input:  ";
        printBinary(n);
        cout << "\n";

        uint32_t output = sol.reverseBits(n);

        cout << "Output: ";
        printBinary(output);
        cout << " (" << output << ")\n\n";
    }

    return 0;
}
