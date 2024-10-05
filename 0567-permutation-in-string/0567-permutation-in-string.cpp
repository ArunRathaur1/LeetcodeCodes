#include <string>
#include <map>
#include <algorithm>

class Solution {
public:
    bool compare_map(const std::map<char,int>& m1, const std::map<char,int>& m2) {
        return m1 == m2; // Direct comparison of maps
    }

    bool checkInclusion(std::string s1, std::string s2) {
        int right = s1.length();
        int end = s2.length();

        if (right > end) return false; // Early exit if s1 is longer than s2

        std::map<char, int> m1, m2;

        // Populate the frequency map for s1
        for (char c : s1) m1[c]++;
        
        // Populate the frequency map for the first window in s2
        for (int i = 0; i < right; i++) m2[s2[i]]++;

        // Check the first window
        if (compare_map(m1, m2)) return true;

        // Start sliding the window
        for (int i = right; i < end; i++) {
            m2[s2[i]]++; // Add new character to the window

            // Remove the character going out of the window
            m2[s2[i - right]]--;

            // Remove the character from the map if its count is zero
            if (m2[s2[i - right]] == 0) {
                m2.erase(s2[i - right]);
            }

            // Check for a match
            if (compare_map(m1, m2)) return true;
        }

        return false;
    }
};
