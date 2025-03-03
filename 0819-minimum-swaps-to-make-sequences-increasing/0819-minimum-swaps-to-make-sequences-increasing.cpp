class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2, int index, bool swapped, vector<vector<int>>& dp) {
        if (index >= nums1.size()) return 0;
        
        if (dp[index][swapped] != -1) return dp[index][swapped];

        int ans = INT_MAX;
        int prev1 = nums1[index - 1];
        int prev2 = nums2[index - 1];

        if (swapped) swap(prev1, prev2); // Only swap for comparison, not the actual array

        // Case 1: No swap at current index
        if (prev1 < nums1[index] && prev2 < nums2[index]) {
            ans = solve(nums1, nums2, index + 1, false, dp);
        }

        // Case 2: Swap at current index
        if (prev1 < nums2[index] && prev2 < nums1[index]) {
            ans = min(ans, 1 + solve(nums1, nums2, index + 1, true, dp));
        }

        return dp[index][swapped] = ans;
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        int n = nums1.size();
        vector<vector<int>> dp(n, vector<int>(2, -1)); // Use vector for memoization

        return solve(nums1, nums2, 1, false, dp);
    }
};
