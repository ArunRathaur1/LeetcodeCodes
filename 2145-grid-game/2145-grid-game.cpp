class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long col = grid[0].size();
        
        // Prefix sum of row 1 (Player 1's path)
        vector<long long> prefix(col, 0);
        prefix[0] = grid[1][0];
        for (long long i = 1; i < col; i++) {
            prefix[i] = grid[1][i] + prefix[i - 1];
        }

        // Suffix sum of row 0 (Player 2's path)
        vector<long long> suffix(col, 0);
        suffix[col - 1] = grid[0][col - 1];
        for (long long i = col - 2; i >= 0; i--) {
            suffix[i] = grid[0][i] + suffix[i + 1];
        }

        // Minimize the max score Player 2 can get (i.e., minimize the worst-case scenario)
        long long ans = LLONG_MAX;
        for (long long i = 0; i < col; i++) {
            long long p1 = (i > 0) ? prefix[i - 1] : 0;  // Sum before the index in row 1
            long long p2 = (i < col - 1) ? suffix[i + 1] : 0;  // Sum after the index in row 0
            long long max_score = max(p1, p2);  // Max score player 2 can get if player 1 chooses column i
            ans = min(ans, max_score);  // Minimize the max score
        }

        return ans;
    }
};
