// Guess the Word

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

/**
 * This is the Master's API interface.
 * In an actual LeetCode problem, this would be provided.
 */
class Master {
    string secret;
    int guessCount = 0;
    int allowedGuesses;

public:
    Master(string sec, int maxGuesses) : secret(sec), allowedGuesses(maxGuesses) {}

    int guess(string word) {
        guessCount++;
        if (guessCount > allowedGuesses) {
            cout << "Error: Exceeded maximum allowed guesses.\n";
            return -1;
        }
        if (word.length() != 6) return -1;
        int matches = 0;
        for (int i = 0; i < 6; i++) {
            if (word[i] == secret[i]) matches++;
        }
        cout << "Guess: " << word << " => Match Count: " << matches << endl;
        return matches;
    }

    bool isSuccess(string word) {
        return word == secret;
    }

    int getGuessCount() const {
        return guessCount;
    }

    bool exceededLimit() const {
        return guessCount > allowedGuesses;
    }
};

class Solution {
    int match(string s1, string s2) {
        int count = 0;
        for (int i = 0; i < 6; i++) {
            if (s1[i] == s2[i]) count++;
        }
        return count;
    }

public:
    void findSecretWord(vector<string>& words, Master& master) {
        srand(time(0));
        vector<string> candidates = words;

        while (!candidates.empty()) {
            string word = candidates[rand() % candidates.size()];
            int guessValue = master.guess(word);
            if (guessValue == 6) {
                cout << "You guessed the secret word correctly.\n";
                return;
            }
            vector<string> temp;
            for (string& w : candidates) {
                if (match(w, word) == guessValue) {
                    temp.push_back(w);
                }
            }
            candidates = temp;
        }

        cout << "Either you took too many guesses, or you did not find the secret word.\n";
    }
};

int main() {
    vector<pair<string, vector<string>>> testCases = {
        {
            "acckzz",
            {"acckzz", "ccbazz", "eiowzz", "abcczz"}
        },
        {
            "hamada",
            {"hamada", "khaled"}
        }
    };

    int allowedGuesses = 10;

    for (size_t i = 0; i < testCases.size(); ++i) {
        cout << "Test Case " << i + 1 << ":\n";
        string secret = testCases[i].first;
        vector<string> words = testCases[i].second;

        Master master(secret, allowedGuesses);
        Solution sol;
        sol.findSecretWord(words, master);

        if (!master.exceededLimit() && master.isSuccess(secret)) {
            cout << "Test Case Passed in " << master.getGuessCount() << " guesses.\n";
        } else {
            cout << "Test Case Failed.\n";
        }
        cout << "--------------------------\n";
    }

    return 0;
}
