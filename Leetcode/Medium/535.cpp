// 535. Encode and Decode TinyURL

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    unordered_map<string, string> encodeMap;
    unordered_map<string, string> decodeMap;
    string base = "http://tinyurl.com/";
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(encodeMap.find(longUrl) == encodeMap.end()){
            string shortUrl = base + to_string(encodeMap.size() + 1);
            encodeMap[longUrl] = shortUrl;
            decodeMap[shortUrl] = longUrl;
        }
        return encodeMap[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return decodeMap[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

int main() {
    Solution solution;

    string url = "https://leetcode.com/problems/design-tinyurl";

    cout << "Original URL: " << url << endl;

    string tiny = solution.encode(url);
    cout << "Encoded TinyURL: " << tiny << endl;

    string decoded = solution.decode(tiny);
    cout << "Decoded URL: " << decoded << endl;

    return 0;
}
