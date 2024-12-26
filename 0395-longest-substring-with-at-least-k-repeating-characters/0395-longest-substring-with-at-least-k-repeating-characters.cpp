#include <iostream>
#include <map>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        if (n < k) return 0; // No valid substring if length of string is smaller than k

        // Create a priority queue for substrings
        priority_queue<pair<int, int>> q;
        q.push({n, 0});  // Push the entire string as the first substring

        while (!q.empty()) {
            pair<int, int> tem = q.top();
            q.pop();
            int start = tem.second;
            int length = tem.first;
            map<char, int> freq;

            // Build the frequency map for the current substring
            for (int i = start; i < start + length; i++) {
                freq[s[i]]++;
            }

            int flag = 1;

            // Check all characters in the frequency map
            for (auto j : freq) {
                if (j.second < k) {
                    int p = start;
                    // Split the substring at each occurrence of the character j.first
                    for (int i = start; i < start + length; i++) {
                        if (s[i] == j.first) {
                            if (i > p) {
                                q.push({i - p, p});  // Push the left part of the substring
                            }
                            p = i + 1;  // Move the starting point past this character
                        }
                    }
                    if (p < start + length) {
                        q.push({start + length - p, p});  // Push the right part of the substring
                    }

                    // Since we split, no need to check further characters
                    flag = 0;
                    break;
                }
            }

            // If all characters satisfy the condition, return the current substring length
            if (flag == 1) {
                return length;
            }
        }
        return 0;  // No valid substring found
    }
};

