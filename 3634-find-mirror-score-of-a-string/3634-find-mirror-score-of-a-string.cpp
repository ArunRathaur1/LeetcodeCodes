#include <string>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    long long calculateScore(string s) {
        vector<int> mirrorMap(26);
        for (int i = 0; i < 26; ++i) {
            mirrorMap[i] = 25 - i;
        }

        vector<deque<int>> charIndices(26); // Deque for each character
        long long score = 0;

        for (int i = 0; i < s.size(); ++i) {
            int currentChar = s[i] - 'a';
            int mirrorChar = mirrorMap[currentChar];

            // Check for the closest unmarked mirror character
            if (!charIndices[mirrorChar].empty()) {
                int j = charIndices[mirrorChar].back(); // Use the most recent valid index
                charIndices[mirrorChar].pop_back();    // Remove it from deque
                score += (i - j);                      // Update the score
            } else {
                // If no mirror found, add the current index to its deque
                charIndices[currentChar].push_back(i);
            }
        }

        return score;
    }
};
