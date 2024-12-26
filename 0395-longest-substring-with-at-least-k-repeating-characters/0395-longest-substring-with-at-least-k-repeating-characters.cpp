class Solution {
public:
    int longestSubstring(string s, int k) {
        // Priority Queue to manage substrings
        priority_queue<pair<int, int>> q;
        int l = s.length();
        q.push({l, 0}); // Initially push the entire string
        
        while (!q.empty()) {
            pair<int, int> x = q.top(); q.pop(); // Extract the front of the queue
            
            map<char, int> f; // Frequency map of characters
            int start = x.second;
            int length = x.first;
            
            // Build frequency map
            for (int i = start; i < start + length; i++) {
                f[s[i]]++;
            }
            
            int flag = 1;
            
            // Check the frequencies of the characters
            for (auto j : f) {
                if (j.second < k) {
                    // If character frequency is less than k, split the substring around it
                    int p = start;
                    for (int i = start; i < start + length; i++) {
                        if (s[i] == j.first) {
                            if (i > p) {
                                q.push({i - p, p}); // Push the left segment
                            }
                            p = i + 1; // Skip the character
                        }
                    }
                    if (p < start + length) {
                        q.push({start + length - p, p}); // Push the right segment if valid
                    }
                    flag = 0; // Substring is not valid, break and process further
                    break; // Stop checking further characters
                }
            }
            
            // If all characters are valid, return the current substring length
            if (flag == 1) {
                return length;
            }
        }
        return 0; // Return -1 if no valid substring found
    }
};
