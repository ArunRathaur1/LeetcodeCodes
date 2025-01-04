#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> left(26, 0), right(26, 0);
        
        // Initialize the right array with the frequency of each character
        for (char c : s) {
            right[c - 'a']++;
        }
        
        unordered_set<string> uniquePalindromes;
        for (int i = 0; i < n; i++) {
            right[s[i] - 'a']--; // Remove the current character from the right
            
            for (char c = 'a'; c <= 'z'; c++) {
                if (left[c - 'a'] > 0 && right[c - 'a'] > 0) {
                    string palindrome = string(1, c) + s[i] + c;
                    uniquePalindromes.insert(palindrome);
                }
            }
            
            left[s[i] - 'a']++; // Add the current character to the left
        }
        
        return uniquePalindromes.size();
    }
};
