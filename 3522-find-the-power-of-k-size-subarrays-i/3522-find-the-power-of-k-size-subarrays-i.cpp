class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> result;
        int n = nums.size();
        
        // Traverse the array to consider each subarray of size k
        for (int i = 0; i <= n - k; i++) {
            bool isSortedAndConsecutive = true;
            int maxElement = nums[i];
            
            // Check if the subarray is sorted and consecutive
            for (int j = i; j < i + k - 1; j++) {
                if (nums[j] + 1 != nums[j + 1]) {
                    isSortedAndConsecutive = false;
                    break;
                }
                maxElement = max(maxElement, nums[j + 1]);
            }
            
            // If the subarray is sorted and consecutive, add the maximum element
            // Otherwise, add -1
            if (isSortedAndConsecutive) {
                result.push_back(maxElement);
            } else {
                result.push_back(-1);
            }
        }
        
        return result;
    }
};
