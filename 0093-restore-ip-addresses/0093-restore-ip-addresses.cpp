class Solution {
public:
    void generate(string& s, vector<string>& ar, string ans, int index, int n, int count) {
        // Base case: If index is at the end of the string and 4 segments are formed
        if (index == n) {
            if (count == 4) {
                ans.pop_back(); // Remove trailing '.'
                ar.push_back(ans);
            }
            return;
        }

        // If more than 4 segments or index goes out of bounds, return
        if (count >= 4 || index >= n) return;

        // Try 1, 2, and 3 digit segments
        for (int len = 1; len <= 3; ++len) {
            if (index + len > n) break; // Ensure within bounds

            string segment = s.substr(index, len);
            int number = stoi(segment);

            // Check if the segment is valid (0 <= number <= 255) and no leading zeros
            if (number > 255 || (segment[0] == '0' && segment.size() > 1)) continue;

            // Recursively generate next segments
            generate(s, ar, ans + segment + ".", index + len, n, count + 1);
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ar;
        int n = s.length();
        if (n < 4 || n > 12) return ar; // Early return for invalid string lengths
        generate(s, ar, "", 0, n, 0);
        return ar;
    }
};
