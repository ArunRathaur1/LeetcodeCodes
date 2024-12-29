class Solution {
public:
    int value = 1e9 + 7; // Modular value to prevent overflow

    int totalways(string& target, int index, int length, int target_index, int target_length, vector<unordered_map<char, int>>& freq, vector<vector<int>>& dp) {
        if (target_length == target_index) return 1; // Base case: target is fully matched
        if (length - index < target_length - target_index) return 0; // Not enough characters left
        if (dp[index][target_index] != -1) return dp[index][target_index]; // Use memoized result

        int total = 0;

        // Check for matching characters at index
        for (auto& ch : freq[index]) {
            if (ch.first == target[target_index]) {
                long long temp = (1LL * totalways(target, index + 1, length, target_index + 1, target_length, freq, dp) * ch.second) % value;
                total = (total + temp) % value; // Update total with modular arithmetic
                break; // Exit loop once matching character is found
            }
        }

        // Skip the current position
        int temp2 = totalways(target, index + 1, length, target_index, target_length, freq, dp) % value;
        total = (total + temp2) % value;

        dp[index][target_index] = total; // Memoize the result
        return total;
    }

    int numWays(vector<string>& words, string target) {
        int l = words.size(); // Number of words
        int word_length = words[0].length(); // Length of each word
        vector<unordered_map<char, int>> freq(word_length); // Frequency map for each position

        // Build the frequency map
        for (int i = 0; i < word_length; i++) {
            for (int j = 0; j < l; j++) {
                freq[i][words[j][i]]++;
            }
        }

        // Initialize DP table
        vector<vector<int>> dp(word_length, vector<int>(target.length(), -1));

        // Compute the result
        return totalways(target, 0, word_length, 0, target.length(), freq, dp);
    }
};
