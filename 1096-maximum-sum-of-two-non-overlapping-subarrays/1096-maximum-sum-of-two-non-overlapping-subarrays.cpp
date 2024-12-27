class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int> prefixsum(n + 1, 0); // Initialize prefix sum array with size n+1

        // Compute prefix sums
        for (int i = 0; i < n; ++i) {
            prefixsum[i + 1] = prefixsum[i] + nums[i];
        }

        int sum = 0;

        // Case 1: First subarray of length `firstLen` comes before second subarray of length `secondLen`
        for (int i = firstLen; i <= n - secondLen; ++i) {
            int firstSum = prefixsum[i] - prefixsum[i - firstLen];
            for (int j = i + secondLen; j <= n; ++j) {
                int secondSum = prefixsum[j] - prefixsum[j - secondLen];
                sum = max(sum, firstSum + secondSum);
            }
        }

        // Case 2: First subarray of length `secondLen` comes before second subarray of length `firstLen`
        for (int i = secondLen; i <= n - firstLen; ++i) {
            int secondSum = prefixsum[i] - prefixsum[i - secondLen];
            for (int j = i + firstLen; j <= n; ++j) {
                int firstSum = prefixsum[j] - prefixsum[j - firstLen];
                sum = max(sum, firstSum + secondSum);
            }
        }

        return sum;
    }
};
